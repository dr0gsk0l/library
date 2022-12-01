#pragma once
#include "graph/Graph.cpp"
struct Tree:Graph{
  using Graph::Graph;
  int root=-1;
  vector<int> DFS,BFS,depth;

  void scan_root(int indexed=1){
    for(int i=1;i<n;i++){
      int p;cin>>p;
      add_edge(p-indexed,i);
    }
    build();
  }
  void scan(int indexed=1){
    Graph::scan(n-1,false,indexed);
    build();
  }

  edge_type& parent(int v){
    assert(~root and root!=v);
    return (*this)[v][0];
  }
  OutgoingEdges son(int v){
    assert(~root);
    if(v==root)return {this,in_deg[v],in_deg[v+1]};
    return {this,in_deg[v]+1,in_deg[v+1]};
  }

private:
  void dfs(int v,int pre=-1){
    for(int i=0;i<T[v].size();i++){
      auto&e=T[v][i];
      if(e.to==pre)swap(T[v][0],T[v][i]);
      else{
        depth[e.to]=depth[v]+1;
        dfs(e.to,v);
      }
    }
    DFS.push_back(v);
  }
public:
  void build(int r=0){
    if(!is_prepared())Graph::build();
    if(~root){
      assert(r==root);
      return;
    }
    root=r;
    depth=vector<int>(n,0);
    DFS.reserve(n);BFS.reserve(n);
    dfs(root);
    queue<int> que;
    que.push(root);
    while(que.size()){
      int p=que.front();que.pop();
      BFS.push_back(p);
      for(int c:son(p))que.push(c);
    }
  }
};