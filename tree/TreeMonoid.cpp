#pragma once
#include "segtree/SegmentTree.cpp"
#include "algebra/Reverse.cpp"
#include "tree/HLD.cpp"
template<typename TREE,typename Monoid>
struct TreeMonoid{
  using X=typename Monoid::value_type;
  using Monoid_r=AlgebraReverse<Monoid>;
  int n;
  TREE T;
  HLD<Tree> hld;
  vector<int> hld_id,euler_in,euler_out;
  SegmentTree<Monoid> seg;
  SegmentTree<Monoid_r> seg_r; 
  
  TreeMonoid(TREE T,int r=0):T(T),hld(T),n(T.n),seg(n),seg_r(n){
    T.build(r);
    hld_id=hld.build(r);
  }
  TreeMonoid(TREE T,vector<X> a,int r=0):T(T),hld(T),n(T.n){
    T.build(r);
    hld_id=hld.build(r);
    vector<X> hld_a(n);
    for(int v=0;v<n;v++)hld_a[hld_id[v]]=a[v];
    seg=SegmentTree<Monoid>(hld_a);
    if(!Monoid::commute)seg_r=SegmentTree<Monoid_r>(hld_a);
  }

  void set(int v,X x){
    seg.set(hld_id[v],x);
    if(!Monoid::commute)seg_r.set(hld_id[v],x);
  }
  void multiply(int v,X x){
    seg.multiply(hld_id[v],x);
    if(!Monoid::commute)seg_r.multiply(hld_id[v],x);
  }
  X get(int v){ return seg.get(hld_id[v]); }
  
  // [u,v]パスの monoid 積
  X path_prod(int u,int v){
    auto [path_u,path_v]=hld.path(u,v);
    X prod_u=Monoid::unit(),prod_v=Monoid::unit();
    for(const auto&[l,r]:path_u){
      X val=(Monoid::commute?seg.prod(r,l+1):seg_r.prod(r,l+1));
      Monoid::Rchop(prod_u,val);
    }
    for(const auto&[l,r]:path_v){
      X val=seg.prod(r,l+1);
      Monoid::Lchop(val,prod_v);
    }
    return Monoid::op(prod_u,prod_v);
  }
  // root -> path
  X path_root(int v){ return path(T.root,v); }

  X subtree_prod(int v){
    assert(Monoid::commute);
    auto [l,r]=hld.subtree(v);
    return seg.prod(l,r);
  }
};