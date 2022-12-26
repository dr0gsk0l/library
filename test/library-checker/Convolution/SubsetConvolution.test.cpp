#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

#include "bitwise/Ranked.cpp"
#include "mod/Modint.cpp"
using mint=Mint<long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;
  int N=1<<n;
  vector<mint> a(N),b(N);
  REP(i,N)cin>>a[i];
  REP(i,N)cin>>b[i];
  auto c=RankedBitwise::subset_convolution(a,b);
  REP(i,N)cout<<c[i]<<"\n "[i+1<N];
}