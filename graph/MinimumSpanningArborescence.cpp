#pragma once
#include "datastructure/UnionFind.cpp"
template<typename WG,typename E=typename WG::edge_type,typename W=typename WG::weight_type>
optional< pair<W,vector<int>> > minimum_spanning_arborescence(WG g,int r=0){
  int n=g.n;
  W res=0;
  vector<W> new_add(n,0);
  vector<int> tree(n);
  vector<int> state(n,0);
  vector<int> pre(n);
  UnionFind uf(n);
  state[r]=2;

  auto compare=[&](const int&a,const int&b){return g.edges[a].weight>g.edges[b].weight;};
  using PQ=priority_queue<int,vector<int>,decltype(compare)>;
  vector< pair<PQ,W> > pq_add(n,{PQ{compare},0});
  for(int i=0;i<g.edges.size();i++)
    pq_add[g.edges[i].to].first.push(i);
  vector<int> pq_id(n);
  iota(pq_id.begin(),pq_id.end(),0);
  
  auto merge=[&](int u,int v){
    u=uf.leader(u);v=uf.leader(v);
    if(u==v)return;
    uf.merge(u,v);
    auto&[pq1,add1]=pq_add[pq_id[u]];
    auto&[pq2,add2]=pq_add[pq_id[v]];
    if(pq1.size()>pq2.size()){
      while(pq2.size()){
        int edge_id=pq2.top();pq2.pop();
        g.edges[edge_id].weight-=add2-add1;
        pq1.push(edge_id);
      }
      pq_id[uf.leader(v)]=pq_id[u];
    }
    else{
      while(pq1.size()){
        int edge_id=pq1.top();pq1.pop();
        g.edges[edge_id].weight-=add1-add2;
        pq2.push(edge_id);
      }
      pq_id[uf.leader(v)]=pq_id[v];
    }
  };
  
  for(int i=0;i<n;i++){
    int now=uf.leader(i);
    if(state[now])continue;
    vector<int> processing;
    while(state[now]!=2){
      processing.push_back(now);
      state[now]=1;
      auto&[pq,add]=pq_add[pq_id[now]];
      if(!pq.size())return nullopt;
      int edge_id=pq.top();pq.pop();
      auto&e=g.edges[edge_id];
      res+=e.weight-add;
      tree[e.to]=edge_id;
      pre[now]=uf.leader(e.from);
      new_add[now]=e.weight;
      if(state[pre[now]]==1){
        int v=now;
        do{
          pq_add[pq_id[v]].second=new_add[v];
          merge(v,now);
          v=uf.leader(pre[v]);
        }while(!uf.same(v,now));
        now=uf.leader(now);
      }
      else
        now=uf.leader(pre[now]);
    }
    for(int v:processing)state[v]=2;
  }
  tree.erase(tree.begin()+r);
  return make_pair(res,tree);
}