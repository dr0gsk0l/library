#pragma once
// 辺の重みが流量に対して単調増加な関数
// 現在の流量を引数として、そこに新たに 1 流す時にかかるコストを返す関数を渡す
#include "graph/WeightedGraph.cpp"
#define REP_(i,n) for(int i=0;i<(n);i++)
template<typename TC>
class NondecreasingMCF{
  using F = function<TC(int)>;
  struct EdgeInfo{
    int cap,flow,rev;
    bool reverse_edge;
    F cost_func;
    
    EdgeInfo()=default;
    EdgeInfo(int cap,F cost_func,int rev,bool reverse_edge):
      cap(cap),cost_func(cost_func),rev(rev),reverse_edge(reverse_edge),flow(0){}
    
    TC cost()const{
      if(!reverse_edge)return cost_func(flow);
      return -cost_func(cap-1);
    }
  };
  int n;
  WeightedGraph< EdgeInfo > G;
  vector<TC> potential,dist;
  static constexpr TC INF= is_same_v<TC,__int128> ? TC(1e30) : numeric_limits<TC>::max()/2;
  // numeric_limits<__int128 >::max() は AOJ でバグった
  vector<pair<int,int>> pre; // pre[v]=[u,i] : G[u][i] で v に来た
  vector<int> in_deg,out_deg;
  priority_queue< pair<TC,int>,vector<pair<TC,int>>,greater<pair<TC,int>>> que;
  bool negative=false;//負辺存在するか

  template<typename T>
  bool chmin(T&a,const T&b){
    return (a>b and (a=b,true));
  }
  bool SP_update(int from,int edge_id){
    const auto&e=G[from][edge_id];
    if((e.weight).cap==0)return false;
    if(chmin(dist[e.to],dist[from]+(e.weight).cost()+potential[from]-potential[e.to])){
      pre[e.to]={from,edge_id};
      return true;
    }
    return false;
  }

  void dijkstra(int s){//dist[i]:sから残余グラフで辺の重みによるiへの最短路 となるようにdistを作る
    fill(dist.begin(),dist.end(),INF);
    dist[s]=0;
    que.emplace(0,s);
    while(que.size()){
      const auto [now,v]=que.top();que.pop();
      if(dist[v]<now)continue;
      REP_(i,G[v].size())
        if(SP_update(v,i))
          que.emplace(dist[G[v][i].to],G[v][i].to);
    }
  }

  void DAG(int s){
    negative=false;
    fill(dist.begin(),dist.end(),INF);
    dist[s]=0;
    queue<int> que;
    REP_(i,n)if(!in_deg[i])que.push(i);
    while(que.size()){
      int v=que.front();que.pop();
      REP_(i,G[v].size()){
        SP_update(v,i);
        if(!--in_deg[G[v][i].to])que.push(G[v][i].to);
      }
    }
  }
public:
  NondecreasingMCF(){}
  NondecreasingMCF(int n_):n(n_),G(n_),potential(n_,0),dist(n_),pre(n_),in_deg(n_,0),out_deg(n_,0),negative(false){}
  
  void add_arc(int u,int v,int cap,F cost_func){
    G.add_arc(u,v,{cap,cost_func,out_deg[v],false});
    G.add_arc(v,u,{0,cost_func,out_deg[u],true});
    out_deg[v]++;out_deg[u]++;
    if(cap>0){
      in_deg[v]++;
      negative|=cost_func(0)<0;
    }
  }

  pair<TC,bool> flow(int s,int t,int f){
    if(!G.is_prepared())G.build();
    TC res=0;
    fill(potential.begin(),potential.end(),0);
    for(int i=0;i<f;i++){
      if(negative)DAG(s);
      else dijkstra(s);
      if(dist[t]==INF)return make_pair(res,false);
      REP_(v,n)if(dist[v]!=INF)potential[v]+=dist[v];
      res+=potential[t];
      for(int v=t;v!=s;v=pre[v].first){
        auto& w=G[pre[v].first][pre[v].second].weight;
        w.cap--;w.flow++;
        auto& r=G[v][w.rev].weight;
        r.cap++;r.flow--;
      }
    }
    return make_pair(res,true);
  }
};
#undef REP_