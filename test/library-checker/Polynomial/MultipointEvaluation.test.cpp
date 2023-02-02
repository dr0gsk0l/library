#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"
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
using FPS=FormalPowerSeries<mint,(1<<17)+1>;
#include "formalpowerseries/MultipointEvaluation.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;cin>>n>>m;
  FPS f(n);
  REP(i,n)cin>>f[i];
  vector<mint> p(m);
  REP(j,m)cin>>p[j];

  vector<mint> ans=multipoint_evaluation(f,p);
  REP(j,m)cout<<ans[j]<<"\n "[j+1<m];
}