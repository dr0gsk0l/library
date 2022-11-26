#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include <bits/stdc++.h>
using namespace std;

#include "graph/WeightedGraph.cpp"
#include "graph/Dijkstra.cpp"

using ll=long long;

int main(){
  int n,m,s,t;cin>>n>>m>>s>>t;
  WeightedGraph<ll> g(n,m,true,0);
  auto [d,pre]=dijkstra(g,s);

  cout<<d[t];
  if(d[t]<0){
    cout<<"\n";
    return 0;
  }

  vector<pair<int,int>> ans;
  while(t!=s){
    ans.emplace_back(pre[t],t);
    t=pre[t];
  }
  reverse(ans.begin(),ans.end());
  cout<<" "<<ans.size()<<"\n";
  for(const auto&[from,to]:ans)cout<<from<<" "<<to<<"\n";
}