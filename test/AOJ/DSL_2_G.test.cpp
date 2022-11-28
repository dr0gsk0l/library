#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"
#include <bits/stdc++.h>
using namespace std;

#include "algebra/lazy/RangeAddRangeSum.cpp"
#include "segtree/LazySegmentTree.cpp"

using ll=long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;cin>>n>>q;
  LazySegmentTree<LazyRangeAddRangeSum<ll>> seg(vector<pair<ll,ll>>(n,{0,1}));
  
  while(q--){
    int t,l,r;cin>>t>>l>>r;l--;
    if(t)
      cout<<seg.prod(l,r).first<<"\n";
    else{
      int x;cin>>x;
      seg.apply(l,r,x);
    }
  }
}