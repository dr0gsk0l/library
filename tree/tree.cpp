#include "graph/Graph.cpp"
struct Tree:Graph{
  using Graph::Graph;
  int root=-1;
  vector<vector<int>> son;
  vector<int> DFS,BFS,parent,depth;

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

private:
  void dfs(int idx,int pre=-1){
    parent[idx]=pre;
    for(const auto&e:(*this)[idx])if(e.to!=pre){
      depth[e.to]=depth[idx]+1;
      dfs(e.to,idx);
      son[idx].push_back(e.to);
    }
    DFS.push_back(idx);
  }
public:
  void build(int r=0){
    if(!is_prepared())Graph::build();
    if(~root){
      assert(r==root);
      return;
    }
    root=r;
    son.resize(n);parent.resize(n);depth.resize(n);
    DFS.reserve(n);BFS.reserve(n);
    depth[root]=0;
    dfs(root);
    queue<int> que;
    que.push(root);
    while(que.size()){
      int p=que.front();que.pop();
      BFS.push_back(p);
      for(int c:son[p])que.push(c);
    }
  }
};