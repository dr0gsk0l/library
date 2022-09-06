struct Graph:vector<vector<int>>{
  int n;
  Graph()=default;
  Graph(int n):n(n){resize(n);}
  Graph(int n,int m,bool directed=false,int index=1):n(n){
    resize(n);
    while(m--){
      int from,to;cin>>from>>to;
      if(directed)add_arc(from-index,to-index);
      else add_edge(from-index,to-index);
    }
  }

  vector<int>& operator[](int v){return at(v);}

  void add_arc(int from,int to){
    at(from).push_back(to);
  }

  void add_edge(int u,int v){
    add_arc(u,v);
    add_arc(v,u);
  }
};