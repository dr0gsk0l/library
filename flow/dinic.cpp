template<typename T,bool directed>
struct Dinic{
  struct edge{
    int to,cap,rev;
    edge(){}
    edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){} 
  };
  vector<vector<edge>> G;
  vector<int> level,iter;

  Dinic(){}
  Dinic(int n):G(n),level(n),iter(n){}

  int add_edge(int from,int to,T cap){
    G[from].emplace_back(to,cap,G[to].size());
    G[to].emplace_back(from,directed?0:cap,G[from].size()-1);
    return G[to].back().rev;
  }

  inline void bfs(int s){
    //level[v]を（容量正の辺による）sからの最短距離にする 到達出来なければ-1
    fill(level.begin(),level.end(),-1);
    queue<int> que;
    level[s]=0;
    que.emplace(s);
    while(que.size()){
      int v=que.front();que.pop();
      for(int i=0;i<(int)G[v].size();i++){
        edge &e=G[v][i];
        if(e.cap==0||~level[e.to])continue;
        level[e.to]=level[v]+1;
        que.emplace(e.to);
      }
    }
  }
  
  inline T dfs(int v,int t,T f){
    //vからtに最短路で水を流す fがvまで持ってこれた水量 流せた量が返り値
    if(v==t)return f;
    for(int &i=iter[v];i<(int)G[v].size();i++){//このdfsで使わなかった辺は次のBFSまで使われることはない
      edge &e=G[v][i];
      if(e.cap>0&&level[v]<level[e.to]){//bfsをしているのでlevel[v]<level[e.to]ならlevel[v]+1==level[e.to]
        T d=dfs(e.to,t,min(f,e.cap));
        if(d==0)continue;
        e.cap-=d;
        G[e.to][e.rev].cap+=d;
        return d;//一本流せたらreturn
      }
    }
    return 0;
  }
  
  T flow(int s,int t,T lim){
    T fl=0;
    while(lim>0){
      bfs(s);
      if(level[t]<0)break;
      fill(iter.begin(),iter.end(),0);
      while(true){
        T f=dfs(s,t,lim);
        if(f==0)break;
        fl+=f;
        lim-=f;
      }
    }
    return fl;
  }
  
  T flow(int s,int t){
    return flow(s,t,numeric_limits<T>::max()/2);
  }
  
  T cut(int s,int t,int x,int a){
    static_assert(directed,"must be directed");
    auto &e=G[x][a];
    int y=e.to;
    T cr=G[y][e.rev].cap;
    if(cr==0) return e.cap=0;
    e.cap=G[y][e.rev].cap=0;
    T cap=cr-flow(x,y,cr);
    if(x!=s&&cap!=0)flow(x,s,cap);
    if(t!=y&&cap!=0)flow(t,y,cap);
    return cap;
  }
  
  T link(int s,int t,int x,int a,T f){
    auto &e=G[x][a];
    e.cap+=f;
    return flow(s,t,f);
  }
};