#define PROBLEM "https://atcoder.jp/contests/abc127/tasks/abc127_f"
#include <bits/stdc++.h>
using namespace std;

#include "datastructure/slopetrick.cpp"

int main(){
  Slope_Trick<long long> f;
  int q;cin>>q;
  while(q--){
    int t;cin>>t;
    if(t==1){
      int a,b;cin>>a>>b;
      f.add_abs(a);
      f+=b;
    }
    else{
      auto [L,R,y]=f.get_min_range();
      cout<<L<<" "<<y<<"\n";
    }
  }
}