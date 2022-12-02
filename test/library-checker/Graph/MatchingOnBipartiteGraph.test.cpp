#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include <bits/stdc++.h>
using namespace std;

#include "graph/BipartiteMatching.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int l,r,m;cin>>l>>r>>m;

  BipartiteMatching BM(l,r);
  while(m--){
    int a,b;cin>>a>>b;
    BM.add_edge(a,b);
  }
  auto ans=BM.solve();
  cout<<ans.size()<<"\n";
  for(const auto&[u,v]:ans)cout<<u<<" "<<v<<"\n";
}