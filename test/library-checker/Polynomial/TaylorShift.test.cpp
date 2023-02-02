#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

#include <atcoder/modint>
#include <atcoder/convolution>
using namespace atcoder;
using mint=modint998244353;
ostream& operator<<(ostream &os,mint a){os<<a.val();return os;}
istream& operator>>(istream &is,mint &a){
  long long b;is>>b;a=b;
  return is;
}

#include "formalpowerseries/Base.cpp"
using FPS=FormalPowerSeries<mint,524288>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,c;cin>>n>>c;
  FPS f(n);
  REP(i,n)cin>>f[i];
  f.taylor_shift(c);
  REP(i,n)cout<<(i<f.size()?f[i]:0)<<"\n "[i+1<n];
}