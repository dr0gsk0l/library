#include "graph/WeightedGraph.cpp"
template<typename WG,typename T=typename WG::cost_type>
pair<vector<T>,vector<int>> dijkstra(WG&g,int s=0){
  assert(g.is_prepared());
  vector<T> d(g.n,-1);
  vector<int> pre(g.n,-1);
  priority_queue< pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> que;
  d[s]=0;
  que.emplace(0,s);
  while(que.size()){
    auto [now,id]=que.top();que.pop();
    if(d[id]<now)continue;
    for(const auto&e:g[id])
      if(d[e.to]==-1 || d[e.to]>now+e.cost){
        d[e.to]=now+e.cost;
        pre[e.to]=id;
        que.emplace(d[e.to],e.to);
      }
  }
  return {d,pre};
}