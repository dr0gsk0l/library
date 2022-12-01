#pragma once
#include "graph/WeightedGraph.cpp"
template<typename T>
struct WeightedTree:WeightedGraph<T>{
  using WeightedGraph<T>::WeightedGraph;
  using edge_type=typename WeightedGraph<T>::edge_type;
  using OutgoingEdges=typename WeightedGraph<T>::OutgoingEdges;
  using WeightedGraph<T>::n;
  using WeightedGraph<T>::in_deg;
  
  int root=-1;
  vector<int> DFS,BFS,depth;

  void scan_root(int indexed=1){
    for(int i=1;i<n;i++){
      int p;cin>>p;
      T weight;cin>>weight;
      add_edge(p-indexed,i,weight);
    }
    build();
  }
  void scan(int indexed=1){
    WeightedGraph<T>::scan(n-1,false,indexed);
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
    for(auto&e:(*this)[v]){
      if(e.to==pre)swap((*this)[v][0],e);
      else{
        depth[e.to]=depth[v]+1;
        dfs(e.to,v);
      }
    }
    DFS.push_back(v);
  }
public:
  void build(int r=0){
    if(!WeightedGraph<T>::is_prepared())WeightedGraph<T>::build();
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
      for(const auto&e:son(p))que.push(e.to);
    }
  }
};