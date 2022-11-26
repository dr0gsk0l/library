#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include <bits/stdc++.h>
using namespace std;

#include "segtree/SegmentTree.cpp"
#include "algebra/group/Affine.cpp"
#include "algebra/Reverse.cpp"
#include "mod/Modint.cpp"

using ll=long long;
using mint=Mint<ll>;
using G_=GroupAffine<mint>;
using G=AlgebraReverse<G_>;
using F=G::value_type;

int main(){
  int n,q;cin>>n>>q;
  vector<F> v(n);
  for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;
  SegmentTree<G> seg(v);
  while(q--){
    int t,l,r,x;cin>>t>>l>>r>>x;
    if(t)cout<<G::eval(seg.prod(l,r),x)<<"\n";
    else seg.set(l,F(r,x));
  }
}