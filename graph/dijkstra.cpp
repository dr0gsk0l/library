template<typename T,bool directed>
pair<vector<T>,vector<int>> dijkstra(const WeightedGraph<T,directed> &g,int s=0){
  vector<T> d(g.n,-1);
  vector<int> pre(g.n,-1);
  priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> que;
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