#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A"
#include <bits/stdc++.h>
using namespace std;

#include "graph/BipartiteMatching.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x,y,m;cin>>x>>y>>m;

  BipartiteMatching BM(x,y);
  while(m--){
    int u,v;cin>>u>>v;
    BM.add_edge(u,v);
  }
  cout<< BM.solve().size() <<endl;
}