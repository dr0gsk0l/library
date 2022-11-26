#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include <bits/stdc++.h>
using namespace std;

#include "algebra/lazy/RangeAffineRangeSum.cpp"
#include "segtree/LazySegmentTree.cpp"
#include "mod/Modint.cpp"

using mint=Mint<long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n,q;cin>>n>>q;

  vector<pair<mint,mint>> v(n);
  for(auto&[a,b]:v){ cin>>a; b=1; }
  LazySegTree< LazyRangeAffineRangeSum<mint> > seg(v);

  while(q--){
    int t,l,r;cin>>t>>l>>r;
    if(t)cout<<seg.prod(l,r).first<<'\n';
    else{
      int b,c;cin>>b>>c;
      seg.apply(l,r,{b,c});
    }
  }
}