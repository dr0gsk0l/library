#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include <bits/stdc++.h>
using namespace std;

#include "../../matrix.cpp"
#include "../../mod/modint.cpp"

using mint=Mint<long long>;
using M=Matrix<mint>;

#define REP(i,n) for(int i=0;i<(n);i++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;cin>>n;
  M A(n,n);
  REP(i,n)REP(j,n)cin>>A[i][j];
  cout<<A.det()<<endl;
}
  


