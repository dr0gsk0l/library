#pragma once
#include "algebra/group/Add.cpp"
template<typename AbelGroup=GroupAdd<long long>>
class FenwickTree{
  using G=AbelGroup;
  using T=typename G::value_type;
  int n;
  vector<T> dat,raw;
public:
  FenwickTree(){
    assert(G::commute);
  }
  FenwickTree(int n):n(n){
    assert(G::commute);
    dat=raw=vector<T>(n,G::unit());
  }
  FenwickTree(const vector<T>&v):n(v.size()),raw(v),dat(v){
    assert(G::commute);
    for(int i=1;i<=n;i++){
      int j=i+(i&-i);
      if(j<=n)G::Rchop(dat[j-1],dat[i-1]);
    }
  }

  T operator[](int k)const{ return raw[k]; }
  T get(int k)const{ return raw[k]; }

  void multiply(int k,const T&x){
    G::Rchop(raw[k],x);
    for(++k;k<=n;k+=k&-k)G::Rchop(dat[k-1],x);
  }
  void add(int k,const T&x){ multiply(k,x); }
  void set(int k,const T&x){ multiply(k,G::op(x,G::inverse(raw[k]))); }

  T prod(int k)const{
    T res=G::unit();
    while(k>0){
      G::Rchop(res, dat[k-1]);
      k -= k&-k;
    }
    return res;
  }
  T sum(int k)const{ return prod(k); }
  T prod(int L,int R)const{
    T pos=G::unit();
    while(L<R){
      G::Rchop(pos,dat[R-1]);
      R -= R&-R;
    }
    T neg=G::unit();
    while(R<L){
      G::Rchop(neg,dat[L-1]);
      L -= L&-L;
    }
    return G::op(pos,G::inverse(neg));
  }
  T sum(int L,int R)const{ return prod(L,R); }

  template<class F>
  int max_right(const F check)const{
    assert(check(G::unit()));
    int r=0;
    T sum=G::unit();
    int k=1;
    while(2*k<=n)k<<=1;
    while(k){
      if(r+k-1<dat.size())
        if(check(G::op(sum,dat[r+k-1]))){
          G::Rchop(sum,dat[r+k-1]);
          r += k;
        }
      k >>= 1;
    }
    return r;
  }

  int kth(T k)const{
    return max_right( [&k](T x){ return x<=k; } );
  }
};