#define IGNORE
// 最大ケースで 8m　程度かかるっぽい

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E"
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

#include "algebra/lazy/AddSum.cpp"
#include "tree/Tree.cpp"
#include "tree/TreeLazy.cpp"
using ll=long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;cin>>n;

  Tree t(n);
  REP(i,n){
    int k;cin>>k;
    REP(_,k){
      int c;cin>>c;
      t.add_edge(i,c);
    }
  }
  t.build(0);

  TreeLazy<Tree,LazyAddSum<ll>> TL(t,cnt_init(n,0LL));
  // 辺の情報は子に持たせる
  // 各頂点 v について、根から 1 移動した点が必要
  // Tree に jump を実装してないので無理くり求める
  vector<int> root2(n,-1);
  for(int v:t.BFS){
    if(v==0)continue;
    if(t.parent[v]==0)root2[v]=v;
    else root2[v]=root2[ t.parent[v] ];
  }

  int q;cin>>q;
  REP(_,q){
    int c;cin>>c;
    if(c){
      int u;cin>>u;
      cout<<TL.path_prod(u,root2[u]).first<<"\n";
    }
    else{
      int v,w;cin>>v>>w;
      TL.path_apply(v,root2[v],w);
    }
  }
}
