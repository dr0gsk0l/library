struct Tree : vector<vector<int>>{
  Tree(int n){
    (*tree).resize(n);
  }

  void add_edge(int u,int v){
    (*this)[u].push_back(v);
    (*this)[v].push_back(u);
  }
};
