#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B"
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

#include "graph/WeightedGraph.cpp"
#include "graph/shortest_path/Dial.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;
  WeightedGraph<int> G(n);
  REP(_,n){
    int u,k;cin>>u>>k;
    REP(_,k){
      int v,c;cin>>v>>c;
      G.add_arc(u,v,c);
    }
  }
  G.build();
  auto [d,pre]=dial(G);
  REP(i,n)cout<<i<<" "<<d[i]<<"\n";
}