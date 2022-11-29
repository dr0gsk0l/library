#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
#include <bits/stdc++.h>
using namespace std;

#include "algebra/lazy/RangeAddRangeMin.cpp"
#include "segtree/DualSegmentTree.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;cin>>n>>q;
  DualSegmentTree< LazyRangeAddRangeMin<int> > seg(vector<int>(n,0));
  while(q--){
    int t;cin>>t;
    if(t){
      int x;cin>>x;x--;
      cout<<seg[x]<<"\n";
    }
    else{
      int l,r,x;cin>>l>>r>>x;l--;
      seg.apply(l,r,x);
    }
  }
}