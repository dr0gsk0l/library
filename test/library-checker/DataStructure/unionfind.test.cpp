#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <bits/stdc++.h>
using namespace std;

#include "datastructure/UnionFind.cpp"

int main() {
  int n,q;cin>>n>>q;
  UnionFind uf(n);
  while(q--){
    int t,u,v;cin>>t>>u>>v;
    if(t)cout<<uf.same(u,v)<<"\n";
    else uf.merge(u,v);
  }
}