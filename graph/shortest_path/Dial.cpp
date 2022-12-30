#pragma once
#include "graph/WeightedGraph.cpp"
template<typename WG,typename T=typename WG::weight_type>
pair<vector<T>,vector<int>> dial(const WG&g,int s=0){
  assert(g.is_prepared());
  vector<T> d(g.n,-1);
  vector<int> pre(g.n,-1);
  vector<bool> used(g.n,false);

  T K=0,rem=0;
  for(const auto&e:g.edges)K=max(K,e.weight);
  vector<queue<int>> que(K+1);
  auto cmp=[&](T a,T b){
    if(a==rem||b==rem)return b==rem;
    if((a<rem)^(b<rem))return a<rem;
    return a>b;
  };
  priority_queue<T,vector<T>,decltype(cmp)> nxt{cmp};

  d[s]=0;
  que[0].push(0);
  nxt.push(0);

  while(nxt.size()){
    rem=nxt.top();nxt.pop();
    auto&Q=que[rem];
    while(Q.size()){
      int v=Q.front();Q.pop();
      if(used[v])continue;
      used[v]=true;
      for(const auto&e:g[v]){
        if(d[e.to]==-1 || d[e.to]>d[v]+e.weight){
          d[e.to]=d[v]+e.weight;
          pre[e.to]=v;
          T x=rem+e.weight;
          if(x>=K+1)x-=K+1;
          if(!que[x].size())nxt.push(x);
          que[x].push(e.to);
        }
      }
    }
  }
  return {d,pre};
}