#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"
#include <bits/stdc++.h>
using namespace std;

#include "tree/Tree.cpp"
#include "tree/RootedTreeIsomorphism.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;
  Tree t(n);
  t.scan_root(0);

  auto [k,hsh]=rooted_tree_isomorphism(t);
  cout<<k<<"\n";
  for(int p:hsh)cout<<p<<" ";cout<<"\n";
}