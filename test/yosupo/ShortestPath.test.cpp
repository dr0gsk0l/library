#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <bits/stdc++.h>
using namespace std;

#include "../../graph/WeightedGraph.cpp"
#include "../../graph/dijkstra.cpp"

using ll=long long;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n,m;cin>>n>>m;
  int s,t;cin>>s>>t;
  WeightedGraph<ll,true> g(n);
  g.scan(m,0);
  
  auto [d,pre]=dijkstra(g,s);
  ll x=d[t];
  if(x<0){
    cout<<-1<<endl;
    return 0;
  }
  
  vector<pair<int,int>> ans;
  while(t!=s){
    ans.emplace_back(pre[t],t);
    t=pre[t];
  }
  reverse(ans.begin(),ans.end());
  cout<<x<<" "<<ans.size()<<"\n";
  for(const auto&[u,v]:ans)cout<<u<<" "<<v<<"\n";
}