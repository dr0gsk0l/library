#pragma once
#include "algebra/group/Add.cpp"
template<typename AbelGroup=GroupAdd<long long>>
class FenwickTree{
  using T=typename AbelGroup::value_type;
  int n;
  vector<T> dat,raw;
public:
  FenwickTree(){
    assert(AbelGroup::commute);
  }
  FenwickTree(int n):n(n){
    assert(AbelGroup::commute);
    dat=raw=vector<T>(n,AbelGroup::unit());
  }
  FenwickTree(const vector<T>&v):n(v.size()),raw(v),dat(v){
    assert(AbelGroup::commute);
    for(int i=1;i<=n;i++){
      int j=i+(i&-i);
      if(j<=n)AbelGroup::Rchop(dat[j-1],dat[i-1]);
    }
  }

  T operator[](int k)const{ return raw[k]; }
  T get(int k)const{ return raw[k]; }

  void set(int k,const T&x){
    T diff=AbelGroup::op(x,AbelGroup::inverse(raw[k]));
    raw[k]=x;
    for(++k;k<=n;k+=k&-k)AbelGroup::Rchop(dat[k-1],diff);
  }
  void multiply(int k,const T&x){
    AbelGroup::Rchop(raw[k],x);
    for(++k;k<=n;k+=k&-k)AbelGroup::Rchop(dat[k-1],x);
  }
  void add(int k,const T&x){ multiply(k,x); }

  T prod(int k)const{
    T res=AbelGroup::unit();
    while(k>0){
      AbelGroup::Rchop(res, dat[k-1]);
      k -= k&-k;
    }
    return res;
  }
  T sum(int k)const{ return prod(k); }
  T prod(int L,int R)const{
    T pos=AbelGroup::unit();
    while(L<R){
      AbelGroup::Rchop(pos,dat[R-1]);
      R -= R&-R;
    }
    T neg=AbelGroup::unit();
    while(R<L){
      AbelGroup::Rchop(neg,dat[L-1]);
      L -= L&-L;
    }
    return AbelGroup::op(pos,AbelGroup::inverse(neg));
  }
  T sum(int L,int R)const{ return prod(L,R); }
};