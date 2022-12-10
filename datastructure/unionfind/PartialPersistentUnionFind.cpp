#pragma once
class PartialPersistentUnionFind{
  int now; // 現在時刻
  vector<int> par,rank,time;
public:
  PartialPersistentUnionFind(int n):now(0),par(n),rank(n,0),time(n,0){
    iota(par.begin(),par.end(),0);
  }

  // 時刻 t の leader
  int find(int x, int t=numeric_limits<int>::max()){
    while(x!=par[x] and time[x]<t)x=par[x];
    return x;
  }
  // 時刻 t で x,y が連結か
  bool same(int x,int y,int t=numeric_limits<int>::max()){
    return find(x,t)==find(y,t);
  }
  // x と y がいつ連結になったか（まだ非連結なら -1 ）
  int when_same(int x,int y){
    stack<int> sx,sy;
    while(x!=par[x]){
      sx.push(time[x]);
      x=par[x];
    }
    while(y!=par[y]){
      sy.push(time[y]);
      y=par[y];
    }
    if(x!=y)return -1;
    while(sx.size() and sy.size() and sx.top()==sy.top()){
      sx.pop();
      sy.pop();
    }
    int res=0;
    while(sx.size()){
      res=max(res,sx.top());
      sx.pop();
    }
    while(sy.size()){
      res=max(res,sy.top());
      sy.pop();
    }
    return res;
  }
  // merge が成功したら時刻を 1 進めたあとその時刻を返す
  // 失敗したら stop が false なら時刻を進めて、-1 を返す 
  int merge(int x,int y,bool stop=false){
    now++;
    x=find(x);
    y=find(y);
    if(x==y){
      if(stop)now--;
      return -1;
    }
    if(rank[x]<rank[y])swap(x,y);
    if(rank[x]==rank[y])rank[x]++;
    par[y]=x;
    return time[y]=now;
  }
};