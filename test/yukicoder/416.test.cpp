#define PROBLEM "https://yukicoder.me/problems/no/416"
#include <bits/stdc++.h>
using namespace std;

#include "datastructure/unionfind/PartialPersistentUnionFind.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m,q;cin>>n>>m>>q;
  PartialPersistentUnionFind uf(n);

  set<pair<int,int>> edge;
  while(m--){
    int a,b;cin>>a>>b;a--;b--;
    edge.insert(minmax(a,b));
  }

  vector<pair<int,int>> query(q);
  for(int i=0;i<q;i++){
    int a,b;cin>>a>>b;a--;b--;
    edge.erase(minmax(a,b));
    query[i]=minmax(a,b);
  }

  for(const auto&[a,b]:edge)uf.merge(a,b);

  map<int,int> time;
  while(q--){
    auto [a,b]=query[q];
    int now=uf.merge(a,b);
    time[now]=q+1;
  }
  
  for(int i=1;i<n;i++){
    int t=uf.when_same(0,i);
    if(t==-1)cout<<0<<"\n";
    else if(!time.count(t))cout<<-1<<"\n";
    else cout<<time[t]<<"\n";
  }
}