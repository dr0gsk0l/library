#pragma once
#include "datastructure/FullyIndexableDictionary.cpp"
#define REP_(i,n) for(int i=0;i<(n);i++)
template<typename T,int LOG>
class WaveletMatrix{
  int n;
  array<FullyIndexableDictionary,LOG> mat;
  array<int,LOG> zero_cnt;
  int memo;

  // 0-indexed で下から i bit 目
  static constexpr bool low_bit (const T&a,int i){ return (a>>i)&1; }
  // 0-indexed で上から i bit 目
  static constexpr bool high_bit(const T&a,int i){ return low_bit(a,LOG-i-1); }

  int nxt(int idx,int h,const T&a){
    // idx の位置に a があった場合上から h bit 目でどこに行くか
    bool bit=high_bit(a,h);
    return mat[h].rank(idx,bit)+(bit?zero_cnt[h]:0);
  }
public:
  WaveletMatrix(vector<T> v):n(v.size()){
    for(const T&p:v)
      assert(0<=p and p<(1ull<<LOG));
    vector<T> lv(n),rv(n);
    REP_(h,LOG){
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
    REP_(h,LOG){
      l=nxt(l,h,a);
      r=nxt(r,h,a);
    }
    memo=l;
    return r-l;
  }
  int rank(T a,int r){ return rank(a,0,r); }

  // k 番目の a の index
  int select(T a,int k){
    if(rank(a,n)<k)return -1;
    k+=memo;
    for(int h=LOG-1;h>=0;h--){
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
    REP_(h,LOG){
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
    return res;
  }
  T kth_smallest(int l,int r,int k){ return kth_largest(l,r,r-l-k-1); }
};
#undef REP_