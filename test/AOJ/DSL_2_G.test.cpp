#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"
#include <bits/stdc++.h>
using namespace std;

#include "algebra/lazy/AddSum.cpp"
#include "segtree/LazySegmentTree.cpp"

using ll=long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;cin>>n>>q;
  LazySegmentTree<LazyAddSum<ll>> seg(cnt_init(n,0LL));
  
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