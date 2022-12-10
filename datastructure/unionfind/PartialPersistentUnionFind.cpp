#pragma once
// https://tiramister.net/blog/posts/persistent-unionfind/
class PartialPersistentUnionFind{
  int now; // 現在時刻
  vector<int> par,rank,time;
  vector<vector<pair<int,int>>> sz;
  static constexpr int NOW=numeric_limits<int>::max();
public:
  PartialPersistentUnionFind(int n):now(0),par(n),rank(n,0),time(n,0),size(x){
    iota(par.begin(),par.end(),0);
  }

  // 時刻 t の leader
  int find(int x, int t=NOW){
    while(x!=par[x] and time[x]<t)x=par[x];
    return x;
  }
  // 時刻 t で x,y が連結か
  bool same(int x,int y,int t=NOW){
    return find(x,t)==find(y,t);
  }
  // x と y がいつ連結になったか（まだ非連結なら -1 ）
  // stack を使う実装も考えたけど少し遅そう https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/37116694
  int when_same(int x,int y){
    int diff=0; // x の深さ - y の深さ
    int X=x,Y=y;
    while(par[x]!=x){
      x=par[x];
      diff++;
    }
    while(par[y]!=y){
      y=par[y];
      diff--;
    }
    if(x!=y)return -1;
    int res=0;
    while(X!=Y){
      if(diff>0){
        res=max(res,time[X]);
        X=par[X];
        diff--;
      }
      else{
        res=max(res,time[Y]);
        Y=par[Y];
        diff++;
      }
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
    sz[x].emplace_back(now, size(x)+size(y));
    if(rank[x]==rank[y])rank[x]++;
    par[y]=x;
    return time[y]=now;
  }
  // 時刻 t の連結成分 x のサイズ
  int size(int x,int t=NOW){
    x=find(x,t);
    int ok=-1,ng=num[x].size();
    while(ng-ok>1){
      int mid=(ok+ng)>>1;
      (num[x][mid].first <= t?ok:ng)=mid;
    }
    return ( ~ok ? num[x][ok].second : 1 );
  }
};