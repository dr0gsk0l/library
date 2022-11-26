#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#include <bits/stdc++.h>
using namespace std;

#include "flow/Dinic.cpp"

int main(){
  int n,m;cin>>n>>m;
  Dinic<int> fl(n,0,n-1);
  while(m--){
    int u,v,c;cin>>u>>v>>c;
    fl.add_edge(u,v,c);
  }
  cout<<fl.flow()<<endl;
}