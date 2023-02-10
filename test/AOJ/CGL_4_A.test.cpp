#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"
#include <bits/stdc++.h>
using namespace std;

#include "geometry/UtilFunction.cpp"
using namespace geometry;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;
  Polygon P(n);
  cin>>P;

  Polygon Q=convex_hull(P);
  cout<<Q.size()<<"\n";
  for(const Point&p:Q)
    cout<<p<<"\n";
}