#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"
#include <bits/stdc++.h>
using namespace std;

#include "graph/WeightedGraph.cpp"
#include "graph/BellmanFord.cpp"

using ll=long long;

int main(){
  int n,m,s;cin>>n>>m>>s;
  WeightedGraph<ll> g(n,m,true,0);
  auto [d,pre]=bellman_ford(g,s);
  for(const auto&p:d)if(!p){
    cout<<"NEGATIVE CYCLE\n";
    return 0;
  }
  for(int i=0;i<n;i++)
    if(~pre[i]||i==s)cout<<d[i].value()<<"\n";
    else cout<<"INF\n";
}