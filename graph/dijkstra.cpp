template<typename T,typename Comp>
using pque=priority_queue<T,vector<T>,Comp>;

template<typename T>
bool chmin(T &a,T b){
  return (a>b&&(a=b,true));
}

template<typename T>
vector<T> dijkstra(const WeightedGraph<T> &g,int s=0){
  vector<T> d(g.size(),numeric_limits<T>::max()/2);
  pque<pair<T,unsigned int>,greater<>> que;
  d[s]=0;
  que.emplace(0,s);
  while(que.size()){
    auto [now,id]=que.top();que.pop();
    if(d[id]<now)continue;
    for(auto&[to,co]:g[id])
      if(chmin(d[to],now+co))que.emplace(d[to],to);
  }
  return d;
}