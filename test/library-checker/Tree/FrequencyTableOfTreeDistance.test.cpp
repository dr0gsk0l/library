#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

#include <atcoder/convolution>
using namespace atcoder;

#include "tree/Tree.cpp"
#include "tree/CentroidDecomposition.cpp"

using ll=long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;
  Tree T(n);
  T.scan(0);
  
  vector<ll> ans(2*n,0);
  vector<bool> used(n,false);

  auto calc_D=[&](const vector<ll>&D,bool add){
    auto D2=convolution_ll(D,D);
    REP(i,D2.size())
      if(add)ans[i]+=D2[i];
      else ans[i]-=D2[i];
  };

  auto make_D=[&](auto make_D,int v,int pre,int d,vector<ll>&D)->void{
    if(D.size()<=d)D.push_back(0);
    D[d]++;
    for(const auto&e:T[v])
      if(e.to!=pre and !used[e.to])
        make_D(make_D,e.to,v,d+1,D);
  };
  auto CD=centroid_decomposition(T);
  for(int c:CD){
    used[c]=true;
    vector<ll> D{1};
    for(const auto&e:T[c]){
      if(used[e.to])continue;
      vector<ll> subD{0};
      make_D(make_D,e.to,c,1,subD);
      calc_D(subD,false);
      if(D.size()<subD.size())D.resize(subD.size(),0);
      REP(i,subD.size())D[i]+=subD[i];
    }
    calc_D(D,true);
  }

  REP(i,n)if(i)cout<< ans[i]/2 <<"\n "[i+1<n];
}