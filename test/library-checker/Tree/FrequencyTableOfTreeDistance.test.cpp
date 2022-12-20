#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"
#include <bits/stdc++.h>
using namespace std;

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

  CentroidDecomposition CD(T);
  
  vector<ll> ans(n,0),D{0};

  auto next_val=[&](int d,auto&e){
    return d+1;
  };
  auto action=[&](int d,bool add){
    if(D.size()<=d)D.push_back(0);
    D[d]++;
  };
  auto finish=[&](bool add){
    auto D2=convolution_ll(D,D);
    for(int i=0;i<D2.size() and i<n;i++)
      if(add)ans[i]+=D2[i];
      else ans[i]-=D2[i];
    D=vector<ll>{0};
  };

  CD.all_calc(0,next_val,action,finish);

  for(int i=1;i<n;i++)cout<< ans[i]/2 <<"\n "[i+1<n];
}