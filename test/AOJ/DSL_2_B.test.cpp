#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
#include <bits/stdc++.h>
using namespace std;

#include "algebra/group/Add.cpp"
#include "datastructure/FenwickTree.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;cin>>n>>q;
  FenwickTree<GroupAdd<int>> ft(n);
  while(q--){
    int c,s,t;cin>>c>>s>>t;s--;
    if(c){
      assert(s<=t);
      cout<<ft.prod(s,t)<<"\n";
    }
    else ft.multiply(s,t);
  }
}