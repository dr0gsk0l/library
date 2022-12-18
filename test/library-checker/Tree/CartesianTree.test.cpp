#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"
#include <bits/stdc++.h>
using namespace std;

#include "tree/CartesianTree.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];

  auto T=cartesian_tree(v);
  for(int i=0;i<n;i++)
    cout<<(i==T.root ? i : T.parent(i).to)<<"\n "[i+1<n];
}