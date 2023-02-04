#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"
#include <bits/stdc++.h>
using namespace std;

#include "math/ExtraGCD.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a,b;cin>>a>>b;
  auto [x,y]=ext_gcd(a,b);
  cout<<x<<" "<<y<<endl;
}