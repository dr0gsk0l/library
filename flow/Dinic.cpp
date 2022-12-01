// https://misawa.github.io/others/flow/dinic_time_complexity.html
#pragma once
#include "graph/WeightedGraph.cpp"
template<typename T>
class Dinic{
  struct EdgeInfo{
    T cap;
    int rev;
  };
  int n;
  WeightedGraph< EdgeInfo > G;
  vector<int> level,current_edge,out_deg;
  int s,t;
  queue<int> que;

  void bfs(){
    //level[v]を（容量正の辺による）sからの最短距離にする 到達出来なければ-1
    fill(level.begin(),level.end(),-1);
    level[s]=0;
    que.emplace(s);
    while(que.size()){
      int v=que.front();que.pop();
      for(const auto&e:G[v]){
        const auto&[cap,rev]=e.weight;
        if(cap==0||~level[e.to])continue;
        level[e.to]=level[v]+1;
        que.emplace(e.to);
      }
    }
  }
  T dfs(int v,T f){
    //vからtに最短路で水を流す fがvまで持ってこれた水量 流せた量が返り値
    if(v==t)return f;
    for(int &i=current_edge[v];i<G[v].size();i++){//このdfsで使わなかった辺は次のBFSまで使われることはない
      auto&e=G[v][i];
      auto&[cap,rev]=e.weight;
      if(cap>0&&level[v]<level[e.to]){//bfsをしているのでlevel[v]<level[e.to]ならlevel[v]+1==level[e.to]
        T d=dfs(e.to,min(f,cap));
        if(d==0)continue;
        cap-=d;
        G[e.to][rev].weight.cap+=d;
        return d;//一本流せたらreturn
      }
    }
    return 0;
  }
public:
  Dinic()=default;
  Dinic(int n,int s,int t):G(n),level(n),current_edge(n),out_deg(n,0),s(s),t(t){}

  void add_arc(int from,int to,T cap){
    G.add_arc(from,to,{cap,out_deg[to]});
    G.add_arc(to,from,{0,out_deg[from]});
    out_deg[from]++;out_deg[to]++;
  }
  T flow(T lim){
    if(!G.is_prepared())G.build();
    T fl=0;
    while(lim>0){
      bfs();
      if(level[t]<0)break;
      fill(current_edge.begin(),current_edge.end(),0);
      while(true){
        T f=dfs(s,lim);
        if(f==0)break;
        fl+=f;
        lim-=f;
      }
    }
    return fl;
  }
  T flow(){ return flow(numeric_limits<T>::max()/2); }
  
  T st_flow(int s_,int t_,T lim){ s=s_;t=t_; return flow(lim);}
  T st_flow(int s_,int t_){ s=s_;t=t_; return flow(); }
};