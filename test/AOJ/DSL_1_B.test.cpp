#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"
#include <bits/stdc++.h>
using namespace std;

#include "datastructure/unionfind/PotentialUnionFind.cpp"
#include "algebra/group/Add.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;cin>>n>>q;
  PotentialUnionFind<GroupAdd<int>> PUF(n);
  while(q--){
    int t,x,y;cin>>t>>x>>y;
    if(t){
      auto diff=PUF.diff(x,y);
      if(diff)cout<<diff.value()<<"\n";
      else cout<<"?\n";
    }
    else{
      int d;cin>>d;
      assert(PUF.merge(x,y,d));
    }
  }
}