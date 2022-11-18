#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include <bits/stdc++.h>
using namespace std;

#include "tree/tree.cpp"
#include "tree/hld.cpp"

int main(){
  int n,q;cin>>n>>q;
  Tree t(n);
  t.scan_root(0);
  HLD hld(t);
  while(q--){
    int u,v;cin>>u>>v;
    cout<<hld.lca(u,v)<<"\n";
  }
}