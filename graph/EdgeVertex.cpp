#pragma once
#include "graph/Graph.cpp"
class EdgeVertex{
  int n,N;
  vector<tuple<int,int,int>> edges;
  vector<tuple<int,int,int>> arcs;
public:
  EdgeVertex(int n):n(n),N(n){}

  int add_edge(int u,int v){
    assert(0<=u and u<n);
    assert(0<=v and v<n);
    edges.emplace_back(u,v,N);
    return N++;
  }
  int add_arc(int u,int v){
    assert(0<=u and u<n);
    assert(0<=v and v<n);
    arcs.emplace_back(u,v,N);
    return N++;
  }

  Graph build(){
    Graph G(N);
    for(const auto&[u,v,e]:edges){
      G.add_edge(u,e);
      G.add_edge(e,v);
    }
    for(const auto&[u,v,e]:arcs){
      G.add_arc(u,e);
      G.add_arc(e,v);
    }
    G.build();
    return G;
  }
};