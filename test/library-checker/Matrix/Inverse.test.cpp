#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"
#include <bits/stdc++.h>
using namespace std;

#include "linearalgebra/Matrix.cpp"
#include "mod/Modint.cpp"

using mint=Mint<long long,998244353>;
using M=Matrix<mint>;

#define REP(i,n) for(int i=0;i<(n);i++)

int main(){
	int n;cin>>n;
	M A(n,n);
	cin>>A;
	auto B=A.inv();
	if(B.has_value())
		REP(i,n)REP(j,n)cout<<B.value()[i][j]<<"\n "[j+1<n];
	else
		cout<<-1<<"\n";
}