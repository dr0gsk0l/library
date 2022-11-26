#pragma once
#include "graph/WeightedGraph.cpp"
#define REP_(i,n) for(int i=0;i<(n);i++)
template<typename TF,typename TC>
class MCF{
  struct EdgeInfo{
    TF cap;
    TC cost;
    int rev;
  };
  int n;
  WeightedGraph< EdgeInfo > G;
  vector<TC> potential,dist;
  static constexpr TC INF=numeric_limits<TC>::max()/2;
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
    if((e->cost).cap==0)return false;
    if(chmin(dist[e->to],dist[from]+(e->cost).cost+potential[from]-potential[e->to])){
      pre[e->to]={from,edge_id};
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
          que.emplace(dist[G[v][i]->to],G[v][i]->to);
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
        if(!--in_deg[G[v][i]->to])que.push(G[v][i]->to);
      }
    }
  }
public:
  MCF(){}
  MCF(int n_):n(n_),G(n_),potential(n_,0),dist(n_),pre(n_),in_deg(n_,0),out_deg(n_,0),negative(false){}
  
  void add_arc(int u,int v,TF cap,TC cost){
    G.add_arc(u,v,{cap,cost,out_deg[v]});
    G.add_arc(v,u,{0,-cost,out_deg[u]});
    out_deg[v]++;out_deg[u]++;
    if(cap>0){
      in_deg[v]++;
      negative|=cost<0;
    }
  }
 
  pair<TC,bool> flow(int s,int t,TF f){//second が 0 で返ってきた場合はそもそも最大流がfに達しない
    if(!G.is_prepared())G.build();
    TC res=0;
    fill(potential.begin(),potential.end(),0);//一番最初は負のコストの辺が無いからポテンシャルは0にしていい
    while(f>0){
      if(negative)DAG(s);
      else dijkstra(s);
      if(dist[t]==INF)return pair<TC,bool>(res,false);
      REP_(v,n)if(dist[v]<INF)potential[v]+=dist[v];
      TF d=f;//d:今回流す量
      for(int v=t;v!=s;v=pre[v].first)chmin(d,(G[pre[v].first][pre[v].second]->cost).cap);
      f-=d;
      res+=potential[t]*d;
      for(int v=t;v!=s;v=pre[v].first){
        auto&[cap,cost,rev]=G.mutable_edge(pre[v].first,pre[v].second)->cost;
        cap-=d;
        (G.mutable_edge(v,rev)->cost).cap+=d;
      }
    }//このループを抜けてるならf流れてる
    return pair<TC,bool>(res,true);
  }
};
#undef REP_