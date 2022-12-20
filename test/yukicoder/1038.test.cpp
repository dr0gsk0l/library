#define PROBLEM "https://yukicoder.me/problems/no/1038"
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

#include "tree/Tree.cpp"
#include "tree/CentroidDecomposition.cpp"
#include "segtree/DualSegmentTree.cpp"
#include "algebra/lazy/AddMin.cpp"

using ll=long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;cin>>n>>q;
  Tree T(n);
  T.scan(1);

  vector<tuple<int,int,int>> query(q);
  vector<vector<int>> query_at(n);
  REP(i,q){
    auto&[x,y,z]=query[i];
    cin>>x>>y>>z;
    x--;
    query_at[x].push_back(i);
  }

  vector<ll> ans(q,0);
  DualSegmentTree< LazyAddMin<ll> > seg(vector<ll>(n,0));
  vector<int> D(n),events;
  int root;

  auto next_val=[&](int d,const auto&e){
    for(int id:query_at[e.to])events.push_back(id);
    return D[e.to]=d+1;
  };
  auto action=[&](int d,bool add){
    if(d==0)next_val(-1,Edge{root,root});
  };
  auto finish=[&](bool add){
    sort(events.begin(),events.end());
    for(int id:events){
      const auto&[x,y,z]=query[id];
      int d=D[x];
      if(add)ans[id]+=seg[d];
      else ans[id]-=seg[d];
      if(d<=y)
        seg.apply(0,y-d+1,z);
    }
    for(int id:events){
      const auto&[x,y,z]=query[id];
      int d=D[x];
      if(d<=y)
        seg.apply(0,y-d+1,-z);
    }
    events.resize(0);
  };

  CentroidDecomposition CD(T);
  for(root=0;root<n;root++)
    CD.calc(root,0,next_val,action,finish);
  
  REP(i,q)cout<<ans[i]<<"\n";
}