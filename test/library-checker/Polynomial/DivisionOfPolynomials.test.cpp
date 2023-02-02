#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"
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
#include "formalpowerseries/DivMod.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;cin>>n>>m;
  FPS f(n),g(m);
  REP(i,n)cin>>f[i];
  REP(j,m)cin>>g[j];
  auto [q,r]=div_mod(f,g);
  q.shrink();
  r.shrink();
  cout<<q.size()<<" "<<r.size()<<endl;
  REP(i,q.size())cout<<q[i]<<" ";cout<<"\n";
  REP(i,r.size())cout<<r[i]<<" ";cout<<"\n";
}