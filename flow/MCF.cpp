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
  int n,s,t;
  WeightedGraph< EdgeInfo > G;
  vector<TC> potential,dist;
  static constexpr TC INF=numeric_limits<TC>::max()/2;
  vector<pair<int,int>> pre,edge_memo; // pre[v]=[u,i] : G[u][i] で v に来た
  vector<int> in_deg,out_deg;
  
  bool negative,dag;

  template<typename T>
  bool chmin(T&a,const T&b){
    return (a>b and (a=b,true));
  }
  bool SP_update(int from,int edge_id){
    const auto&e=G[from][edge_id];
    if((e.weight).cap==0)return false;
    if(chmin(dist[e.to],dist[from]+(e.weight).cost+potential[from]-potential[e.to])){
      pre[e.to]={from,edge_id};
      return true;
    }
    return false;
  }

  priority_queue< pair<TC,int>,vector<pair<TC,int>>,greater<pair<TC,int>>> que;
  void dijkstra(){//dist[i]:sから残余グラフで辺の重みによるiへの最短路 となるようにdistを作る
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

  void DAG(){
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

  void BellmanFord(){
    negative=false;
    fill(dist.begin(),dist.end(),INF);
    dist[s]=0;
    REP_(_,n){
      bool update=false;
      REP_(v,n)if(dist[v]<INF)
        REP_(i,G[v].size())
          if(SP_update(v,i))
            update=true;
      if(!update)return;
    }
    assert(false); // 負閉路
  }
public:
  MCF(){}
  MCF(int n_,int s_=0,int t_=-1):n(n_),G(n_),potential(n_,0),dist(n_),pre(n_),in_deg(n_,0),out_deg(n_,0),negative(false),dag(true),s(s_),t(t_){
    if(t<0)t=n-1;
  }
  void use_bellman_ford(){ dag=false; }

  TF operator[](const int edge_id)const{
    assert(G.is_prepared());
    const auto&[from,id]=edge_memo[edge_id];
    return G.edge[from][id].weight.cap;
  }
  vector< tuple<int,int,TF,TC> > all_edge(){
    assert(G.is_prepared());
    vector< tuple<int,int,TF,TC> > res;
    res.reserve(edge_memo.size());
    for(const auto&[v,id]:edge_memo){
      const auto&[to,from,weight]=G[v][id];
      res.emplace_back(from,to,weight.cap,-weight.cost);
    }
    return res;
  }
  
  void add_arc(int from,int to,TF cap,TC cost){
    G.add_arc(from,to,{cap,cost,out_deg[to]});
    G.add_arc(to,from,{0,-cost,out_deg[from]++});
    edge_memo.emplace_back(to,out_deg[to]++);
    if(cap>0){
      in_deg[to]++;
      negative|=cost<0;
    }
  }
 
  pair<TC,bool> flow(TF f=numeric_limits<TF>::max()){//second が 0 で返ってきた場合はそもそも最大流がfに達しない
    if(!G.is_prepared())G.build();
    TC res=0;
    fill(potential.begin(),potential.end(),0);//一番最初は負のコストの辺が無いからポテンシャルは0にしていい
    while(f>0){
      if(negative)
        if(dag)DAG();
        else BellmanFord();
      else dijkstra();
      if(dist[t]==INF)return make_pair(res,false);
      REP_(v,n)if(dist[v]<INF)potential[v]+=dist[v];
      TF d=f;//d:今回流す量
      for(int v=t;v!=s;v=pre[v].first)chmin(d,(G[pre[v].first][pre[v].second].weight).cap);
      f-=d;
      res+=potential[t]*d;
      for(int v=t;v!=s;v=pre[v].first){
        auto&[cap,cost,rev]=G[pre[v].first][pre[v].second].weight;
        cap-=d;
        (G[v][rev].weight).cap+=d;
      }
    }//このループを抜けてるならf流れてる
    return make_pair(res,true);
  }

  pair<TC,bool> st_flow(int s_, int t_, TF lim=numeric_limits<TF>::max()/2){ 
    s=s_;t=t_; 
    return flow(lim);
  }
};
#undef REP_