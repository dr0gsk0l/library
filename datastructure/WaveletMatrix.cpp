#pragma once
#include "datastructure/FullyIndexableDictionary.cpp"
#include "util/Compress.cpp"
#define REP_(i,n) for(int i=0;i<(n);i++)
template<typename T,bool COMPRESS=true>
class WaveletMatrix{
  using U=conditional_t<COMPRESS,int,T>;
  static_assert(is_integral_v<U>,"Wavelet Matrix is only for integer");
  int n,memo,log;
  vector<FullyIndexableDictionary> mat;
  vector<int> zero_cnt;
  Compress<T,true> C;

  constexpr U comp(const T&a)const{
    if constexpr(COMPRESS){ return C.leq(a); }
    else{ return a; }
  }

  // 0-indexed で下から i bit 目
  inline bool low_bit (const U&a,int i)const{ return (a>>i)&1; }
  // 0-indexed で上から i bit 目
  inline bool high_bit(const U&a,int i)const{ return low_bit(a,log-i-1); }

  int nxt(int idx,int h,const U&a){
    // idx の位置に a があった場合上から h bit 目でどこに行くか
    bool bit=high_bit(a,h);
    return mat[h].rank(idx,bit)+(bit?zero_cnt[h]:0);
  }
public:
  WaveletMatrix(vector<T> v,int log_=0):n(v.size()),log(log_){
    if constexpr(COMPRESS){
      C=Compress<T,true>(v);
      for(T&a:v)a=C[a];
      while(C.size()>=(1ull<<log))log++;
    }
    else{
      T mx=0;
      for(const T&a:v){
        assert(a>=0);
        if(mx<a)mx=a;
      }
      while(mx>=(1ull<<log))log++;
    }
    mat.resize(log);
    zero_cnt.resize(log);
    vector<U> lv(n),rv(n);
    REP_(h,log){
      mat[h]=FullyIndexableDictionary(n);
      int l=0,r=0;
      REP_(i,n)
        if(high_bit(v[i],h)){
          rv[r++]=v[i];
          mat[h].set(i);
        }
        else
          lv[l++]=v[i];
      zero_cnt[h]=l;
      mat[h].build();
      swap(lv,v);
      REP_(i,r)v[l+i]=rv[i];
    }
  }

  // [l,r) の x の個数
  int rank(const T&x,int l,int r){
    if constexpr(COMPRESS){
      if(!C.exist(x))return 0;
    }
    U a=comp(x);
    REP_(h,log){
      l=nxt(l,h,a);
      r=nxt(r,h,a);
    }
    memo=l;
    return r-l;
  }
  int rank(const T&x,int r){ return rank(x,0,r); }

  // k 番目の x の index
  int select(const T&x,int k){
    U a=comp(x);
    if(rank(a,n)<k)return -1;
    k+=memo;
    for(int h=log-1;h>=0;h--){
      bool bit=high_bit(a,h);
      if(bit)k-=zero_cnt[h];
      k=mat[h].select(k,bit);
    }
    return k;
  }
  
  // [l,r) で 0-indexed k 番目に大きい値
  T kth_largest(int l,int r,int k){
    if(k<0 or r-l<=k) return -1;
    U res=0;
    REP_(h,log){
      int L=mat[h].rank(l);
      int R=mat[h].rank(r);
      res<<=1;
      if(R-L>k){
        l=L+zero_cnt[h];
        r=R+zero_cnt[h];
        res++;
      }
      else{
        k-=R-L;
        l-=L;
        r-=R;
      }
    }
    if constexpr(COMPRESS){ return C.r(res); }
    else{ return res; }
  }
  T kth_smallest(int l,int r,int k){ return kth_largest(l,r,r-l-k-1); }
};
#undef REP_