---
title: Distance
documentation_of: local/Distance.cpp
---

* ```int shortest_path(const F&f,const T&s)```  
$s$ から終端（ $f(t)$ が空であるような頂点 $t$ ）までの最短距離を求める  
一度求めた距離はメモ化され、2回目以降にもその結果が用いられる
実装が BFS でなく DFS であることに注意

* ```vector<vector<T>> from_root(const F&f,const T&s,int MAX=10)```  
$s$ からの距離が $MAX$ 以下の点を BFS で求める  
```result[d]``` には $s$ から距離 $d$ の頂点が辞書順に入ってる  
この関数を呼ぶ場合、（```from_root``` も含めて）他に関数は呼ばない

* ```vector<vector<T>> from_root(const F&f,const vector<T>&s,int MAX=10)```  
```from_root``` の多始点版

## 概要
最短手数を求める実験用ライブラリ  
有向辺　$f:T\rightarrow vector<T>$ を渡す  

## 例
[AGC059A](https://atcoder.jp/contests/agc059/tasks/agc059_a) の実験コード  
操作を逆向きにして ```from_root``` を呼ぶことで、5手以内で終了する長さ 7 の列を列挙している
```cpp
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) v.begin(),v.end()
using vi=vector<int>;
vi iota(int n){ vi v(n);iota(ALL(v),0);return v; }

auto f=[](vi v){
  vector<vi> nxt;
  auto p=iota(3);
  do{
    REP(l,v.size()){
      vi w=v;
      for(int r=l;r<v.size();r++){
        w[r]=p[v[r]];
        nxt.push_back(w);
      }
    }
  }while(next_permutation(ALL(p)));
  return nxt;
};

Distance<vi> D;
auto level=D.from_root(f,{vi(7,0),vi(7,1),vi(7,2)},5);
```
対称性などがあるものに関しては、$f$ で代表元に向かうコードにしても良いし、以下のように出力で省いても良い
```cpp
set<vi> used;
REP(d,level.size()){
  cout<<d<<":\n";
  auto p=iota(3);
  for(vi v:level[d]){
    v.erase(unique(ALL(v)),v.end());
    if(used.count(v))continue;
    bool ok=true;
    do{
      auto w=v;
      for(int&a:w)a=p[a];
      if(used.count(w))ok=false;
    }while(next_permutation(ALL(p)));
    if(ok){
      cout<<v<<endl;
      used.insert(v);
    }
  }
}
```
