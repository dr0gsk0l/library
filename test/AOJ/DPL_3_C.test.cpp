#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C"
#include <bits/stdc++.h>
using namespace std;

#include "tree/CartesianTree.cpp"

using ll=long long;
void chmax(ll&a,ll b){ a=max(a,b); }

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;
  vector<ll> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  auto T=cartesian_tree(v);

  ll ans=0;
  chmax(ans,v[T.root]*n);
  for(int i=0;i<n;i++)
    for(const auto&e:T.son(i)){
      const auto&[L,R]=e.weight;
      chmax(ans,v[e.to]*(R-L));
    }
  cout<<ans<<endl;
}