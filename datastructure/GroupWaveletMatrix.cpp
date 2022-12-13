#pragma once
#include "datastructure/WaveletMatrix.cpp"
#include "datastructure/FenwickTree.cpp"
#define REP_(i,n) for(int i=0;i<(n);i++)
template<typename T,typename AbelGroup>
class GroupWaveletMatrix:WaveletMatrix<T,true>{
  using super=WaveletMatrix<T,true>;
  using super::log,super::n,super::nxt,super::comp,super::data,super::high_bit,super::mat;
  using U=typename super::U;
  using FT=FenwickTree<AbelGroup>;
  using S=typename AbelGroup::value_type;
  vector<FT> ft;
public:
  using super::rank,super::select,super::kth_largest,super::kth_smallest,super::range_freq,super::lt,super::leq,super::gt,super::geq;
  GroupWaveletMatrix(vector<T> v):super::WaveletMatrix(v){
    ft.resize(log);
    for(auto&p:ft)p=FT(n);
  }
  GroupWaveletMatrix(vector<T> v,const vector<S>&w):GroupWaveletMatrix(v){
    for(int i=0;i<n;i++)add(i,w[i]);
  }
  void add(int idx,const S&val){
    U a=comp(data[idx]);
    REP_(h,log){
      idx=nxt(idx,h,a);
      ft[h].add(idx,val);
    }
  }
  S sum(int l,int r,const T&upper){
    U a=comp(upper);
    S res=AbelGroup::unit();
    REP_(h,log){
      bool bit=high_bit(a,h);
      if(bit){
        int L=mat[h].rank(l,0),R=mat[h].rank(r,0);
        AbelGroup::Rchop(res,ft[h].sum(L,R));
        l=nxt(l,h,a);
        r=nxt(r,h,a);
      }
      else{
        l=nxt(l,h,a);
        r=nxt(r,h,a);
      }
    }
    return res;
  }
  S sum(int l,int r,const T&lower,const T&upper){
    return AbelGroup::op(sum(l,r,upper),AbelGroup::inverse(sum(l,r,lower)));
  }
};
#undef REP_