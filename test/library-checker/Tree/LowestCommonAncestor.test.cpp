#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include <bits/stdc++.h>
using namespace std;

#include "tree/lca.cpp"

int main(){
  int n,q;cin>>n>>q;
  Tree t(n);
  t.scan_root(0);
  LCA lca(t);
  while(q--){
    int u,v;cin>>u>>v;
    cout<<lca.lca(u,v)<<"\n";
  }
}