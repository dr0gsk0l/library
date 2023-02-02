#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"
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

using FPS=FormalPowerSeries<mint,500000>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n,m;cin>>n>>m;
  FPS f(n);
  for(int i=0;i<n;i++)cin>>f[i];
  f=f.pow(m);
  for(int i=0;i<n;i++)cout<<f[i]<<"\n "[i+1<n];
}