#define PROBLEM "https://judge.yosupo.jp/problem/directedmst"
#include <bits/stdc++.h>
using namespace std;

#include "graph/WeightedGraph.cpp"
#include "graph/MinimumSpanningArborescence.cpp"
#include "tree/WeightedTree.cpp"
using ll=long long;

int main(){
  int n,m,s;cin>>n>>m>>s;
  WeightedGraph<ll> g(n,m,true,0);
  auto ans=minimum_spanning_arborescence(g,s);
  assert(ans.has_value());
  auto [val,tree]=ans.value();
  WeightedTree<ll> t(n);
  for(int edge_id:tree)
    t.add_edge(g.edges[edge_id]);
  t.build(s);
  cout<<val<<"\n";
  for(int v=0;v<n;v++)
    cout<<(v==s?s:t.parent(v).to)<<"\n "[v+1<n];
}