#pragma once
#include "datastructure/FullyIndexableDictionary.cpp"
#define REP_(i,n) for(int i=0;i<(n);i++)
template<typename T>
class WaveletMatrix{
  int n,memo,log;
  vector<FullyIndexableDictionary> mat;
  vector<int> zero_cnt;
  T slide;

  // 0-indexed で下から i bit 目
  inline bool low_bit (const T&a,int i)const{ return (a>>i)&1; }
  // 0-indexed で上から i bit 目
  inline bool high_bit(const T&a,int i)const{ return low_bit(a,log-i-1); }

  int nxt(int idx,int h,const T&a){
    // idx の位置に a があった場合上から h bit 目でどこに行くか
    bool bit=high_bit(a,h);
    return mat[h].rank(idx,bit)+(bit?zero_cnt[h]:0);
  }
public:
  WaveletMatrix(vector<T> v):n(v.size()){
    assert(v.size());
    T mn=v[0],mx=v[0];
    for(const T&p:v){
      mn=min(mn,p);
      mx=max(mx,p);
    }
    assert(-mn<=numeric_limits<T>::max()-mx);
    for(T&p:v)p-=mn;
    mx-=mn;
    slide=mn;
    for(log=0;mx>=(1ull<<log);log++){}
    mat.resize(log);
    zero_cnt.resize(log);
    vector<T> lv(n),rv(n);
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

  // [l,r) の a の個数
  int rank(T a,int l,int r){
    a+=slide;
    REP_(h,log){
      l=nxt(l,h,a);
      r=nxt(r,h,a);
    }
    memo=l;
    return r-l;
  }
  int rank(T a,int r){ return rank(a,0,r); }

  // k 番目の a の index
  int select(T a,int k){
    a+=slide;
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
    T res=0;
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
    return res+slide;
  }
  T kth_smallest(int l,int r,int k){ return kth_largest(l,r,r-l-k-1); }
};
#undef REP_