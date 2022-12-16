#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

#include "datastructure/WaveletMatrix.cpp"
#include "r2/XY.cpp"
#include "r2/Projection.cpp"
#include "datastructure/CumulativeSum.cpp"

using ll=long long;
using r2=XY<ll>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;cin>>n>>q;
  vector<r2> r2s(n);
  vector<int> x(n),y(n),w(n);
  REP(i,n){
    cin>>x[i]>>y[i]>>w[i];
    r2s[i]=r2(x[i],y[i]);
  }

  auto P=Projection(r2s);
  vector<int> Y(P.size(),0);
  REP(id,P.size())Y[id]=P.r(id).y;
  WaveletMatrix WM(Y);

  int LOG=WM.height();
  vector W(LOG,vector<ll>(P.size(),0));
  REP(i,n){
    int idx=P.id(x[i],y[i]);
    auto idxs=WM.points(idx);
    REP(h,LOG)W[h][idxs[h]]+=w[i];
  }
  vector<CumulativeSum<ll>> C(LOG);
  REP(h,LOG)C[h]=CumulativeSum<ll>(W[h]);

  REP(j,q){
    int l,r,d,u;cin>>l>>d>>r>>u;
    auto [L,R]=P.interval(l,r);
    ll res=0;
    auto intervals=WM.intervals(L,R,u);
    for(const auto&[h,l,r]:intervals)res+=C[h].sum(l,r);
    auto intervals2=WM.intervals(L,R,d);
    for(const auto&[h,l,r]:intervals2)res-=C[h].sum(l,r);
    cout<<res<<"\n";
  }
}