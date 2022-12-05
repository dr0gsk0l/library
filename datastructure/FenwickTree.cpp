#pragma once
template<typename AbelGroup>
class FenwickTree{
  using T=typename AbelGroup::value_type;
  int n;
  vector<T> dat,raw;
  void chop(T&a,T b){ a=AbelGroup::op(a,b); }
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

  void set(int k,const T&x){
    T diff=AbelGroup::op(x,AbelGroup::inverse(raw[k]));
    raw[k]=x;
    for(++k;k<=n;k+=k&-k)AbelGroup::Rchop(dat[k-1],diff);
  }
  void multiply(int k,const T&x){
    chop(raw[k],x);
    for(++k;k<=n;k+=k&-k)AbelGroup::Rchop(dat[k-1],x);
  }

  T prod(int k){
    T res=AbelGroup::unit();
    while(k>0){
      AbelGroup::Rchop(res, dat[k-1]);
      k -= k&-k;
    }
    return res;
  }
  T prod(int L,int R){
    T pos=AbelGroup::unit();
    while(L<R){
      AbelGroup::Rchop(pos,dat[R-1]);
      R -= R&-R;
    }
    T neg=AbelGroup::unit();
    while(R<L){
      AbelGroup::Rchop(neg, dat[L - 1]);
      L -= L&-L;
    }
    AbelGroup::Rchop(pos,AbelGroup::inverse(neg));
    return pos;
  }
};