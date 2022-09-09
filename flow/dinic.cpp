// https://misawa.github.io/others/flow/dinic_time_complexity.html
template<typename T>
struct Dinic{
  struct edge{
    const int to,rev;
    T cap;
    edge(){}
    edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){} 
  };
  vector<vector<edge>> G;
  vector<int> lavel,current_edge;
  const int s,t;

  Dinic()=default;
  Dinic(int n,int s,int t):G(n),lavel(n),current_edge(n),s(s),t(t){}

  void add_edge(int from,int to,T cap){
    G[from].emplace_back(to,cap,G[to].size());
    G[to].emplace_back(from,0,G[from].size()-1);
  }

  void bfs(){
    //lavel[v]を（容量正の辺による）sからの最短距離にする 到達出来なければ-1
    fill(lavel.begin(),lavel.end(),-1);
    queue<int> que;
    lavel[s]=0;
    que.emplace(s);
    while(que.size()){
      int v=que.front();que.pop();
      for(const auto&e:G[v]){
        if(e.cap==0||~lavel[e.to])continue;
        lavel[e.to]=lavel[v]+1;
        que.emplace(e.to);
      }
    }
  }
  
  T dfs(int v,T f){
    //vからtに最短路で水を流す fがvまで持ってこれた水量 流せた量が返り値
    if(v==t)return f;
    for(int &i=current_edge[v];i<G[v].size();i++){//このdfsで使わなかった辺は次のBFSまで使われることはない
      edge &e=G[v][i];
      if(e.cap>0&&lavel[v]<lavel[e.to]){//bfsをしているのでlavel[v]<lavel[e.to]ならlavel[v]+1==lavel[e.to]
        T d=dfs(e.to,min(f,e.cap));
        if(d==0)continue;
        e.cap-=d;
        G[e.to][e.rev].cap+=d;
        return d;//一本流せたらreturn
      }
    }
    return 0;
  }
  
  T flow(T lim){
    T fl=0;
    while(lim>0){
      bfs();
      if(lavel[t]<0)break;
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
  
  T flow(){
    return flow(numeric_limits<T>::max()/2);
  }
};