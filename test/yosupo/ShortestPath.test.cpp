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
  WeightedGraph<ll> g(n);
  while(m--){
    int a,b,c;cin>>a>>b>>c;
    g.add_edge(a,b,c);
  }
  auto d=dijkstra(g,s);
  if(d[t]>1e15){
    cout<<-1<<endl;
    return 0;
  }
  vector<int> pre(n,-1);
  queue<int> que;
  que.push(s);
  pre[s]=s;
  while(que.size()){
    int p=que.front();que.pop();
    for(auto [to,co]:g[p])
      if(pre[to]==-1 and d[p]+co==d[to]){
        pre[to]=p;
        que.push(to);
      }
  }
  vector<int> ans;
  while(true){
    ans.push_back(t);
    if(t==s)break;
    t=pre[t];
  }
  cout<<d[ans[0]]<<" "<<ans.size()-1<<"\n";
  for(int i=ans.size()-1;i;i--)cout<<ans[i]<<" "<<ans[i-1]<<"\n";
}