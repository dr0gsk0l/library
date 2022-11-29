#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
#include <bits/stdc++.h>
using namespace std;

#include "algebra/lazy/RangeSetRangeSum.cpp"
#include "segtree/LazySegmentTree.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;cin>>n>>q;
  LazySegmentTree< LazyRangeSetRangeSum<int> > seg(vector<pair<int,int>>(n,{0,1}));
  while(q--){
    int t,l,r;cin>>t>>l>>r;r++;
    if(t)cout<<seg.prod(l,r).first<<"\n";
    else{
      int x;cin>>x;
      seg.apply(l,r,x);
    }
  }
}