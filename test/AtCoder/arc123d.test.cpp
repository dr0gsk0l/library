#define PROBLEM "https://atcoder.jp/contests/arc123/tasks/arc123_d"
#include <bits/stdc++.h>
using namespace std;

#include "datastructure/slopetrick.cpp"

int main(){
  Slope_Trick<long long> f;
  int n;cin>>n;
  int prea=0;
  while(n--){
    int a;cin>>a;

    if(prea-a<0)f.shift(a-prea);
    prea=a;

    f.clear_inc();
    f.add_abs(0);
    f.add_abs(a);
  }
  cout<<f.min_f<<"\n";
}