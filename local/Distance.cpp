template<typename T>
class Distance{
  map<T,int> d;
  queue<T> que;
public:
  // s から終端にたどり着くまでの距離
  template<typename F>
  int shortest_path(const F&f,const T&s){
    if(d.count(s))return d[s];
    if(!f(s).size())return d[s]=0;
    int res=1e9;
    for(const T&to:f(s))res=min(res,shortest_path(f,to)+1);
    return d[s]=res;
  }

  // s からの最短距離が MAX 以下のものを列挙
  template<typename F>
  vector<vector<T>> from_root(const F&f,const T&s,int MAX=10){
    vector<vector<T>> level(MAX+1);
    d[s]=0;
    que.push(s);
    while(que.size()){
      T v=que.front();que.pop();
      int D=d[v];
      for(const T&to:f(v)){
        if(d.count(to))continue;
        d[to]=D+1;
        if(D+1<MAX)que.push(to);
      }
    }
    for(const auto&[key,val]:d)level[val].push_back(key);
    return level;
  }

  template<typename F>
  vector<vector<T>> from_root(const F&f,const vector<T>&s,int MAX=10){
    vector<vector<T>> level(MAX+1);
    for(const T&v:s){
      d[v]=0;
      que.push(v);
    }
    while(que.size()){
      T v=que.front();que.pop();
      int D=d[v];
      for(const T&to:f(v)){
        if(d.count(to))continue;
        d[to]=D+1;
        if(D+1<MAX)que.push(to);
      }
    }
    for(const auto&[key,val]:d)level[val].push_back(key);
    return level;
  }
};
