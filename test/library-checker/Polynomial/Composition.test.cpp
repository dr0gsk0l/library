#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"
#include <bits/stdc++.h>
using namespace std;

#include <formalpowerseries/Base.cpp>

#include <atcoder/modint>
#include <atcoder/convolution>
using namespace atcoder;
using mint=modint998244353;
ostream& operator<<(ostream &os,mint a){os<<a.val();return os;}
istream& operator>>(istream &is,mint &a){
  long long b;is>>b;a=b;
  return is;
}

using FPS=FormalPowerSeries<mint,8000>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;cin>>n;
  FPS f(n),g(n);
  for(int i=0;i<n;i++)cin>>f[i];
  for(int i=0;i<n;i++)cin>>g[i];
  f=f(g);
  for(int i=0;i<n;i++)cout<<f[i]<<"\n "[i+1<n];
}