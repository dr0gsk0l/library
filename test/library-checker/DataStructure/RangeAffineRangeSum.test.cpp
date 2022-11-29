#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include <bits/stdc++.h>
using namespace std;

#include "algebra/lazy/AffineSum.cpp"
#include "segtree/LazySegmentTree.cpp"
#include "mod/Modint.cpp"

using mint=Mint<long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n,q;cin>>n>>q;

  vector<mint> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  LazySegmentTree< LazyAffineSum<mint> > seg(cnt_init(v));

  while(q--){
    int t,l,r;cin>>t>>l>>r;
    if(t)cout<<seg.prod(l,r).first<<'\n';
    else{
      int b,c;cin>>b>>c;
      seg.apply(l,r,{b,c});
    }
  }
}