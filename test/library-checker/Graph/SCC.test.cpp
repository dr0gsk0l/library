#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include <bits/stdc++.h>
using namespace std;

#include "graph/Graph.cpp"
#include "graph/SCC.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;cin>>n>>m;
  Graph g(n,m,true,0);
  SCC scc(g);
  int k=scc.DAG.n;
  cout<<k<<"\n";
  for(const auto&ve:scc.component){
    cout<<ve.size();
    for(int p:ve)cout<<" "<<p;
    cout<<"\n";
  }
}