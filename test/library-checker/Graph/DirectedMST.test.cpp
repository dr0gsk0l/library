#define PROBLEM "https://judge.yosupo.jp/problem/directedmst"
#include <bits/stdc++.h>
using namespace std;

#include "graph/WeightedGraph.cpp"
#include "graph/MinimumSpanningArborescence.cpp"
using ll=long long;

int main(){
  int n,m,s;cin>>n>>m>>s;
  WeightedGraph<ll> g(n,m,true,0);
  auto ans=minimum_spanning_arborescence(g,s);
  assert(ans.has_value());
  auto [val,tree]=ans.value();
  vector<int> p(n);
  p[s]=s;
  ll sum=0;
  for(int id:tree){
    const auto&e=g.edges[id];
    sum+=e.weight;
    p[e.to]=e.from;
  }
  val=sum;//assert(sum==val);
  cout<<val<<"\n";
  for(int v=0;v<n;v++)
    cout<<p[v]<<"\n "[v+1<n];
}