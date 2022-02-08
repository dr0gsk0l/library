template<typename T>
struct Edge{
  int to;
  T cost;
};
 
template<typename T>
struct WeightedGraph{
  int n;
  vector<vector<Edge<T>>> g;
    
  WeightedGraph(){}
  WeightedGraph(int n):n(n),g(n){}
    
  void add_edge(int from, int to, T cost){
    g[from].push_back({to,cost});
  }
};