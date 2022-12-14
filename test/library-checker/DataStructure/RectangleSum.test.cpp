#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

#include "datastructure/GroupWaveletMatrix.cpp"
#include "r2/XY.cpp"
#include "r2/Projection.cpp"
#include "algebra/group/Add.cpp"

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
  vector<ll> W(P.size(),0);
  REP(id,P.size())Y[id]=P.r(id).y;
  REP(i,n){
    int id=P.id(x[i],y[i]);
    W[id]+=w[i];
  }

  GroupWaveletMatrix<int,GroupAdd<ll>> WM(Y,W);

  REP(j,q){
    int l,r,d,u;cin>>l>>d>>r>>u;
    auto [L,R]=P.interval(l,r);
    cout<< WM.sum(L,R,d,u) <<"\n";
  }
}