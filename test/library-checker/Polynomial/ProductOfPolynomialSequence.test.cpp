#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"
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
using FPS=FormalPowerSeries<mint,500000>;
#include "formalpowerseries/Prod.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  FPSProdDiversity<FPS> P;

  int n;cin>>n;
  REP(_,n){
    int d;cin>>d;
    FPS f(d+1);
    REP(i,d+1)cin>>f[i];
    P.add(f);
  }
  FPS f=P.prod();
  REP(i,f.size())cout<<f[i]<<"\n "[i+1<f.size()];
}