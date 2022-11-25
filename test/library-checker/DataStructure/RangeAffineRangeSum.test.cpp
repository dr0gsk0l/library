#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include <bits/stdc++.h>
using namespace std;

#include "algebra/lazy_range_affine_range_sum.cpp"
#include "segtree/lazysegtree.cpp"
#include "mod/modint.cpp"

using mint=Mint<long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n,q;cin>>n>>q;

  vector<pair<mint,mint>> v(n);
  for(auto&[a,b]:v){ cin>>a; b=1; }
  LazySegTree< Lazy_Range_Affine_Range_Sum<mint> > seg(v);

  while(q--){
    int t,l,r;cin>>t>>l>>r;
    if(t)cout<<seg.prod(l,r).first<<'\n';
    else{
      int b,c;cin>>b>>c;
      seg.apply(l,r,{b,c});
    }
  }
}