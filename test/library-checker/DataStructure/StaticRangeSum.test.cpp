#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <bits/stdc++.h>
using namespace std;

#include "datastructure/cumulaitvesum.cpp"

int main() {
  int n,q;cin>>n>>q;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  auto wa=CumulativeSum(v);
  while(q--){
    int l,r;cin>>l>>r;
    cout<<wa.sum(l,r)<<'\n';
  }
}