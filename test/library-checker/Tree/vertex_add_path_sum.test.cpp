#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include <bits/stdc++.h>
using namespace std;

#include "algebra/group/Add.cpp"
#include "algebra/Reverse.cpp"
#include "segtree/SegmentTree.cpp"
#include "tree/Tree.cpp"
#include "tree/HLD.cpp"
#include "tree/TreeMonoid.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  using G=GroupAdd<long long>;

  int n,q;cin>>n>>q; 
  vector<long long> a(n);
  for(int i=0;i<n;i++)cin>>a[i];

  Tree t(n);
  t.scan(0);

  TreeMonoid<Tree,G> TM(t,a);

  while(q--){
    int c;cin>>c;
    if(c){
      int u,v;cin>>u>>v;
      cout<< TM.path_prod(u,v) <<"\n";
    }
    else{
      int p,x;cin>>p>>x;
      TM.multiply(p,x);
    }
  }
}