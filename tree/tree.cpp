struct Tree:vector<vector<int>>{
  int n;
  vector<vector<int>> son;
  vector<int> DFS,BFS,parent;
  
  Tree(int n):n(n),son(n),parent(n,-1){
    DFS.reserve(n);
    BFS.reserve(n);
    resize(n);
  }

  void scan(int index=1){
    for(int i=0;i<n-1;i++){
      int u,v;cin>>u>>v;
      add_edge(u-index,v-index);
    }
  }
  void scan_root(int index=1){
    for(int i=1;i<n;i++){
      int p;cin>>p;
      add_edge(p-index,i);
    }
  }

  void add_edge(int u,int v){
    at(u).push_back(v);
    at(v).push_back(u);
  }

  vector<int>& operator[](int k){return at(k);}
private:
  void dfs(int idx,int pre=-1){
    parent[idx]=pre;
    for(int p:at(idx))if(p!=pre){
      dfs(p,idx);
      son[idx].push_back(p);
    }
    DFS.push_back(idx);
  }
public:
  void build(int root=0){ 
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