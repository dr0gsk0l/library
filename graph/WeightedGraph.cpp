template<typename T>
struct Edge{
  int to;
  T cost;
};
 
template<typename T>
struct WeightedGraph:vector<vector<Edge<T>>>{
  WeightedGraph(){}
  WeightedGraph(int n):{
    (*this).resize(n);
  }
    
  void add_edge(int from, int to, T cost){
    (*this).push_back({to,cost});
  }
};