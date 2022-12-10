#define PROBLEM "https://judge.yosupo.jp/problem/number_of_subsequences"
#include <bits/stdc++.h>
using namespace std;

#include "mod/Modint.cpp"
#include "util/Subsequence.cpp"
using mint=Mint<long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  cout<< sparse_subsequence<mint,int>(v)-1 <<endl;
}