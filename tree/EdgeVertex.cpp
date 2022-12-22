#pragma once
#include "tree/Tree.cpp"
class EdgeVertex{
  int n,m;
  Tree T;
public:
  EdgeVertex(int n):n(n),m(0),T(n*2-1){}

  int add_edge(int u,int v){
    assert(0<=u and u<n);
    assert(0<=v and v<n);
    int w=n+(m++);
    assert(w<T.n);
    T.add_edge(u,w);
    T.add_edge(w,v);
    return w;
  }

  Tree build(int root=0){
    assert(m==n-1);
    T.build(root);
    return T;
  }
};