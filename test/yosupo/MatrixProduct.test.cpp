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

  int n,m,k;cin>>n>>m>>k;
  M A(n,m),B(m,k);
  REP(i,n)REP(j,m)cin>>A[i][j];
  REP(j,m)REP(l,k)cin>>B[j][l];
  M C=A*B;
  REP(i,n)REP(l,k)cout<<C[i][l]<<"\n "[l+1<k];
}
  


