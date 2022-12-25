#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

#include "mod/Modint.cpp"
#include "bitwise/Base.cpp"

using mint=Mint<long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Bitwise<mint> B;

  int n;cin>>n;
  int N=1<<n;
  vector<mint> a(N),b(N);
  REP(i,N)cin>>a[i];
  REP(i,N)cin>>b[i];
  auto c=B.and_convolution(a,b);
  REP(i,N)cout<<c[i]<<"\n "[i+1<N];
}