#define PROBLEM "https://atcoder.jp/contests/abc217/tasks/abc217_h"
#include <bits/stdc++.h>
using namespace std;

#include "datastructure/slopetrick.cpp"

int main(){
  int n;cin>>n;

  Slope_Trick<long long> f;
  for(int i=0;i<=n;i++)f.add_abs(0);

  int pret=0;
  while(n--){
    int t,d,x;cin>>t>>d>>x;

    int diff=t-pret;
    f.sliding_window_minimum(-diff,diff);
    pret=t;

    if(d)f.add_x_minus_a(x);
    else f.add_a_minus_x(x);
  }
  cout<<f.min_f<<"\n";
}