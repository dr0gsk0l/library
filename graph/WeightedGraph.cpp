template<typename T>
struct Edge{
  int to;
  T cost;
  Edge(int to,T cost):to(to),cost(cost){}
};

template<typename T,bool directed>
struct WeightedGraph:vector<vector<Edge<T>>>{
  int n;
  WeightedGraph(){}
  WeightedGraph(int n):n(n){
    (*this).resize(n);
  }
    
  void add_edge(int from, int to, T cost){
    (*this)[from].emplace_back(to,cost);
    if(!directed)(*this)[to].emplace_back(from,cost);
  }

  void scan(int m,int index){
    while(m--){
      int from,to;cin>>from>>to;from-=index;to-=index;
      T cost;cin>>cost;
      add_edge(from,to,cost);
    }
  }
};