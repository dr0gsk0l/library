#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"
#include <bits/stdc++.h>
using namespace std;

#include "flow/MCF.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m,f;cin>>n>>m>>f;
  MCF<int,int> fl(n);
  while(m--){
    int u,v,c,d;cin>>u>>v>>c>>d;
    fl.add_arc(u,v,c,d);
  }
  auto [ans,ok]=fl.flow(f);
  cout<< (ok?ans:-1) <<endl;
}