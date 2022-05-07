#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../../tree/tree.cpp"
#include "../../tree/lca.cpp"

int main(){
  int n,q;cin>>n>>q;
  Tree t(n);
  for(int i=1;i<n;i++){
    int p;cin>>p;
    t.add_edge(i,p);
  }
  LCA lca(t,0);
  while(q--){
    int u,v;cin>>u>>v;
    cout<<lca.lca(u,v)<<"\n";
  }
}