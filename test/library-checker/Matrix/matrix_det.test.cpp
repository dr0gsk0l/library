#define PROBLEM "matrix_det"
#include <bits/stdc++.h>
using namespace std;

#include "linearalgebra/matrix.cpp"
#include "mod/modint.cpp"

using mint=Mint<long long,998244353>;
using M=Matrix<mint>;

int main(){
	int n;cin>>n;
	M A(n,n);
	cin>>A;
	cout<<A.det()<<endl;
}