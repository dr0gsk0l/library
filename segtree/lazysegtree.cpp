#pragma once

template<typename Lazy>
class LazySegTree{
  using MX = typename Lazy::MX;
  using MF = typename Lazy::MF;
  using X = typename MX::value_type;
  using F = typename MF::value_type;
  int n,log,size;
  vector<X> dat;
  vector<F> laz;

  X reflect(int k){
    if(k<size)return Lazy::mapping(laz[k],dat[k]);
    return dat[k];
  }
  void point_apply(int k,const F&f){
    if(k<size)laz[k]=MF::op(f,laz[k]);
    else dat[k]=Lazy::mapping(f,dat[k]);
  }
  void push(int k){
    dat[k]=reflect(k);
    point_apply(2*k,laz[k]);
    point_apply(2*k+1,laz[k]);
    laz[k]=MF::unit();
  }
  void thrust(int k){ for(int i=log;i;i--)push(k>>i); }
  void update(int i){ dat[i]=MX::op(reflect(2*i),reflect(2*i+1)); }
  void recalc(int k){ while(k>>=1)update(k); }

public:
  LazySegTree() : LazySegTree(0) {}
  LazySegTree(int n):LazySegTree(vector<X>(n,MX::unit())) {}
  LazySegTree(const vector<X>&v) : n(v.size()) {
    for(log=1;(1<<log)<n;log++){}
    size=1<<log;
    dat.assign(size<<1,MX::unit());
    laz.assign(size,MF::unit());
    for(int i=0;i<n;++i)dat[size+i]=v[i];
    for(int i=size-1;i>=1;--i)update(i);
  }

  void set(int p,X x){
    assert(0<=p and p<n);
    thrust(p+=size);
    dat[p]=x;
    recalc(p);
  }

  X operator[](int p){
    assert(0<=p and p<n);
    thrust(p+=size);
    return reflect(p);
  }

  X prod(int L,int R){
    assert(0<=L and L<=R and R<=n);
    if(L==R)return MX::unit();
    thrust(L+=size);
    thrust((R+=size-1)++);
    X vl=MX::unit(),vr=MX::unit();
    while(L<R){
      if(L&1)vl=MX::op(vl,reflect(L++));
      if(R&1)vr=MX::op(reflect(--R),vr);
      L>>=1,R>>=1;
    }
    return MX::op(vl,vr);
  }

  void apply(int l,int r,F f){
    assert(0 <= l && l <= r && r <= n);
    if(l==r)return;
    thrust(l+=size);
    thrust(r+=size-1);
    for(int L=l,R=r+1;L<R;L>>=1,R>>=1){
      if(L&1)point_apply(L++,f);
      if(R&1)point_apply(--R,f);
    }
    recalc(l);
    recalc(r);
  }
};