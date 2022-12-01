template<typename WG,typename T=typename WG::weight_type>
optional<pair<vector<T>,vector<int>>> bellman_ford(const WG&g,int s=0){
  int n=g.n;
  static constexpr T INF=numeric_limits<T>::max()/2;
  vector<T> d(n,INF);
  vector<int> pre(n,-1);
  d[s]=0;
  while(n--)
    for(const auto&e:g.edges)
      if(d[e.to]>d[e.from]+e.weight){
        if(!n)return nullopt;
        d[e.to]=d[e.from]+e.weight;
        pre[e.to]=e.from;
      }
  return make_pair(d,pre);
}