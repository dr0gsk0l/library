template<typename T>
using pqg=priority_queue<T,vector<T>,greater<T>>;

template<typename T>
pair<vector<T>,vector<int>> dijkstra(const WeightedGraph<T> &g,int s=0){
  int n=g.size();
  vector<T> d(n,-1);
  vector<int> pre(n,-1);
  pqg< pair<T,int> > que;
  d[s]=0;
  que.emplace(0,s);
  while(que.size()){
    auto [now,id]=que.top();que.pop();
    if(d[id]<now)continue;
    for(const auto&[to,co]:g[id])
      if(d[to]==-1 || d[to]>now+co){
        d[to]=now+co;
        pre[to]=id;
        que.emplace(d[to],to);
      }
  }
  return {d,pre};
}