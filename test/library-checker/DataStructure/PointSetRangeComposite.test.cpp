#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include <bits/stdc++.h>
using namespace std;

#include "segtree/segtree.cpp"
#include "algebra/group_linear.cpp"
#include "algebra/algebra_reverse.cpp"
#include "mod/modint.cpp"

using ll=long long;
using mint=Mint<ll>;
using G_=Group_Affine<mint>;
using G=Algebra_Reverse<G_>;
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