#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include <bits/stdc++.h>
using namespace std;

#include "graph/WeightedGraph.cpp"
#include "graph/NegativeCycleFind.cpp"
#include "graph/WarshallFloyd.cpp"

using ll=long long;

int main(){
  int n,m;cin>>n>>m;
  WeightedGraph<ll> g(n,m,true,0);
  if(negative_cycle_find(g))cout<<"NEGATIVE CYCLE\n";
  else{
    auto d=warshall_floyd(g);
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        if(d[i][j]<1e10)cout<<d[i][j]<<"\n "[j+1<n];
        else cout<<"INF"<<"\n "[j+1<n];
  }
}