#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

#include "graph/Graph.cpp"
#include "graph/shortest_path/BFS.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;
  Graph g(n);
  REP(_,n){
    int u,k;cin>>u>>k;u--;
    REP(_,k){
      int v;cin>>v;v--;
      g.add_arc(u,v);
    }
  }
  g.build();
  auto [d,pre]=BFS(g);
  REP(i,n)cout<<i+1<<" "<<d[i]<<"\n";
}
