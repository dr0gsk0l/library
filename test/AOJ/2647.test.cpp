#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2647"
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

#include "graph/WeightedGraph.cpp"
#include "graph/MinimumSpanningArborescence.cpp"

int main(){
  int n,m;cin>>n>>m;
  vector<bool> koho(n,true);
  WeightedGraph<int> G(n);
  REP(_,m){
    int a,b;cin>>a>>b;
    koho[b]=false;
    G.add_arc(a,b,0);
    G.add_arc(b,a,1);
  }

  int mn=1e9;
  vector<int> ans;
  REP(i,n)if(koho[i]){
    auto res=minimum_spanning_arborescence(G,i);
    assert(res.has_value());
    const auto&[val,tree]=res.value();
    if(mn==val)ans.push_back(i);
    if(mn>val){
      mn=val;
      ans={i};
    }
  }
  cout<<ans.size()<<" "<<mn<<"\n";
  REP(i,ans.size())cout<<ans[i]<<"\n "[i+1<ans.size()];
}