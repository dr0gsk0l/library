#include "graph/WeightedGraph.cpp"
template<typename WG,typename T=typename WG::weight_type>
pair<vector<T>,vector<int>> bfs01(WG&g,int s=0){
  assert(g.is_prepared());
  vector<T> d(g.n,-1);
  vector<int> pre(g.n,-1);
  deque<pair<T,int>> deq;
  d[s]=0;
  deq.emplace_back(0,s);
  while(deq.size()){
    auto [now,id]=deq.front();deq.pop_front();
    if(d[id]<now)continue;
    for(const auto&e:g[id]){
      assert(e.weight==0||e.weight==1);
      if(d[e.to]==-1 || d[e.to]>now+e.weight){
        d[e.to]=now+e.weight;
        pre[e.to]=id;
        if(e.weight==0)deq.emplace_front(d[e.to],e.to);
        else deq.emplace_back(d[e.to],e.to);
      }
    }
  }
  return {d,pre};
}