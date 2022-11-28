#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
#include <bits/stdc++.h>
using namespace std;

#include "algebra/lazy/RangeSetRangeMin.cpp"
#include "segmenttree/DualSegmentTree.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;cin>>n>>q;
  DualSegmentTree< LazyRangeSetRangeMin<int> > seg(vector<int>(n,(1LL<<31)-1));
  while(q--){
    int t;cin>>t;
    if(t){
      int i;cin>>i;
      cout<<seg[i]<<"\n";
    }
    else{
      int l,r,x;cin>>l>>r>>x;r++;
      seg.apply(l,r,x);
    }
  }
}