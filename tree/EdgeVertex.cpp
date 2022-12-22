#pragma once
#include "tree/Tree.cpp"
class EdgeVertex{
  int n;
  vector<pair<int,int>> edges;
public:
  EdgeVertex(int n):n(n){
    edges.reserve(n-1);
  }
  int add_edge(int u,int v){
    assert(0<=u and u<n);
    assert(0<=v and v<n);
    edges.emplace_back(u,v);
    return n+int(edges.size())-1;
  }

  Tree build(int root=0){
    assert(edges.size()==n-1);
    Tree T(n*2-1);
    for(int i=0;i<edges.size();i++){
      const auto&[u,v]=edges[i];
      int w=n+i;
      T.add_edge(u,w);
      T.add_edge(v,w);
    }
    T.build(root);
    return T;
  }
};