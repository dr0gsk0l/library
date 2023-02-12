#define PROBLEM "https://yukicoder.me/problems/no/2012"
#include <bits/stdc++.h>
using namespace std;

#include "linearalgebra/ConvexHullTrick.cpp"
#include "r2/XY.cpp"
using ll=long long;
using ld = long double;
void chmax(ld&a,ld b){ if(a<b)a=b; }

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;
  vector<XY<ld>> xy(n);
  for(int i=0;i<n;i++)cin>>xy[i];
  sort(xy.begin(),xy.end());

  MinConvexHullTrick<ld> CHT1;
  MaxConvexHullTrick<ld> CHT2;

  ld ans=0;

  for(const auto&v:xy){
    if(v.x==0){
      chmax(ans,abs(xy[0].x*v.y));
      chmax(ans,abs(xy.back().x*v.y));
      continue;
    }
    if(CHT1.size()){
      ld res1=CHT1.query(v.y/v.x)*v.x, res2=CHT2.query(v.y/v.x)*v.x;
      chmax(ans, max(abs(res1),abs(res2)));
    }
    Line<ld> f(v.x,-v.y);
    CHT1.add(f);
    CHT2.add(f);
  }
  cout<<ll(round(ans))<<'\n';
}