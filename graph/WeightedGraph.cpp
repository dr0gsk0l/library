template<typename T>
struct Edge{
  int to;
  T cost;
  Edge()=default;
  Edge(int to,T cost):to(to),cost(cost){}
};

template<typename T>
struct WeightedGraph:vector<vector<Edge<T>>>{
  using vector<vector<Edge<T>>>::resize;
  using vector<vector<Edge<T>>>::at;

  using cost_type=T;
  using edge_type=Edge<T>;

  WeightedGraph(){}
  WeightedGraph(int n){ resize(n); }
  WeightedGraph(int n,int m,bool directed=false,int index=1){
    resize(n);
    while(m--){
      int from,to;T cost;cin>>from>>to>>cost;
      if(directed)add_arc(from-index,to-index,cost);
      else add_edge(from-index,to-index,cost);
    }
  }

  void add_arc(int from,int to,T cost){
    at(from).emplace_back(to,cost);
  }

  void add_edge(int u,int v,T cost){
    add_arc(u,v,cost);
    add_arc(v,u,cost);
  }
};