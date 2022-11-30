#pragma once
#include "segtree/LazySegmentTree.cpp"
#include "algebra/lazy/Reverse.cpp"
#include "tree/HLD.cpp"
template<typename TREE,typename Lazy>
struct TreeLazy{
  using MX=typename Lazy::MX;
  using MF=typename Lazy::MF;
  using X=typename MX::value_type;
  using F=typename MF::value_type;
  using Lazy_r=LazyReverse<Lazy>;
  int n;
  TREE T;
  HLD<Tree> hld;
  vector<int> hld_id,euler_in,euler_out;
  LazySegmentTree<Lazy> seg;
  LazySegmentTree<Lazy_r> seg_r; 
  
  TreeLazy(TREE T,int r=0):T(T),hld(T),n(T.n),seg(n),seg_r(n){
    T.build(r);
    hld_id=hld.build(r);
  }
  TreeLazy(TREE T,vector<X> a,int r=0):T(T),hld(T),n(T.n){
    T.build(r);
    hld_id=hld.build(r);
    vector<X> hld_a(n);
    for(int v=0;v<n;v++)hld_a[hld_id[v]]=a[v];
    seg=LazySegmentTree<Lazy>(hld_a);
    seg_r=LazySegmentTree<Lazy_r>(hld_a);
  }

  void set(int v,X x){
    seg.set(hld_id[v],x);
    seg_r.set(hld_id[v],x);
  }
  void multiply(int v,X x){
    seg.multiply(hld_id[v],x);
    seg_r.multiply(hld_id[v],x);
  }
  X get(int v){ return seg.get(hld_id[v]); }
  
  // [u,v]パスの monoid 積
  X path_prod(int u,int v){
    auto [path_u,path_v]=hld.path(u,v);
    X prod_u=MX::unit(),prod_v=MX::unit();
    for(const auto&[l,r]:path_u){
      X val=seg_r.prod(r,l+1);
      prod_u=MX::op(prod_u,val);
    }
    for(const auto&[l,r]:path_v){
      X val=seg.prod(r,l+1);
      prod_v=MX::op(val,prod_v);
    }
    return MX::op(prod_u,prod_v);
  }
  // root -> path
  X path_root_prod(int v){ return path_prod(T.root,v); }

  void path_apply(int u,int v,const F&f){
    auto [path_u,path_v]=hld.path(u,v);
    for(const auto&[l,r]:path_u){
      seg.apply(r,l+1,f);
      seg_r.apply(r,l+1,f);
    }
    for(const auto&[l,r]:path_v){
      seg.apply(r,l+1,f);
      seg_r.apply(r,l+1,f);
    }
  }
  void path_root_apply(int v,const F&f){ path_apply(T.root,v,f); }

  X subtree_prod(int v){
    assert(MX::commute);
    auto [l,r]=hld.subtree(v);
    return seg.prod(l,r);
  }
  void subtree_apply(int v,const F&f){
    auto [l,r]=hld.subtree(v);
    seg.apply(l,r,f);
    seg_r.apply(l,r,f);
  }
};