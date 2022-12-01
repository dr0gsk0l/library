template<typename WG,typename T=typename WG::weight_type>
vector<vector<T>> warshall_floyd(const WG&g){
  int n=g.n;
  static constexpr T INF=numeric_limits<T>::max()/2;
  vector d(n,vector<T>(n,INF));
  for(int i=0;i<n;i++)d[i][i]=0;
  for(const auto&e:g.edges)
    if(d[e.from][e.to]>e.weight)
      d[e.from][e.to]=e.weight;
  for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)if(d[i][k]<INF)
      for(int j=0;j<n;j++)if(d[k][j]<INF)
        if(d[i][j]>d[i][k]+d[k][j])
          d[i][j]=d[i][k]+d[k][j];
  return d;
}