#pragma once
#include "graph/Graph.cpp"
#include "graph/ReverseGraph.cpp"
#define ALL_(v) v.begin(),v.end()
#define REP_(i,n) for(int i=0;i<(n);i++)
template<typename DirectedGraph>
class SCC{
  int n;
  DirectedGraph G,R;
  vector<int> visit,belong;
  vector<bool> used;
  void dfs(int v){
    used[v]=true;
    for(const auto&e:G[v])if(!used[e.to])dfs(e.to);
    visit.push_back(v);
  }
  void rdfs(int v,int k){
    used[v]=true;
    belong[v]=k;
    for(const auto&e:R[v])if(!used[e.to])rdfs(e.to,k);
  }
public:
  Graph DAG;
  vector<vector<int>> component;
  SCC(const DirectedGraph&G):n(G.n),G(G),belong(n),used(n,false){
    assert(G.is_prepared());
    visit.reserve(n);
    R=reverse_graph(G);
    REP_(v,n)if(!used[v])dfs(v);
    fill(ALL_(used),false);
    reverse(ALL_(visit));
    int k=0;
    for(const int&v:visit)
      if(!used[v])rdfs(v,k++);
    vector<vector<int>> edges(k);
    component.resize(k);
    REP_(v,n){
      component[belong[v]].push_back(v);
      for(auto&e:G[v])
        if(belong[v]!=belong[e.to])
          edges[belong[v]].push_back(belong[e.to]);
    }
    DAG=Graph(k);
    REP_(from,k){
      sort(ALL_(edges[from]));
      REP_(i,edges[from].size())
        if(!i || edges[from][i]!=edges[from][i-1])
          DAG.add_arc(from,edges[from][i]);
    }
  }
  int operator[](int k){ return belong[k]; }
};
#undef ALL_
#undef REP_