#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) v.begin(),v.end()
#define debug(a) cerr<<#a<<":"<<a<<endl;
#define debug2(a,b) cerr<<"("<<#a<<","<<#b<<"):("<<a<<","<<b<<")"<<endl;
#define debug3(a,b,c) cerr<<"("<<#a<<","<<#b<<","<<#c<<"):("<<a<<","<<b<<","<<c<<")"<<endl;
#define debug4(a,b,c,d) cerr<<"("<<#a<<","<<#b<<","<<#c<<","<<d<<"):("<<a<<","<<b<<","<<c<<","<<d<<")"<<endl;

template<typename T>
istream& operator>>(istream&is,vector<T>&v){
  for(T&p:v)is>>p;
  return is;
}
template<typename T>
ostream& operator<<(ostream&os,const vector<T>&v){
  if(&os==&cerr)os<<"[";
  for(int i=0;i<v.size();i++){
    os<<v[i];
    if(i+1<v.size())os<<(&os==&cerr?",":" ");
  }
  if(&os==&cerr)os<<"]";
  return os;
}

#include "../../matrix.cpp"
#include "../../mod/modint.cpp"

using mint=Mint<long long>;
using M=Matrix<mint>;

template<typename T,typename ...Args>
auto make_vector(T x,int arg,Args ...args){
  if constexpr(sizeof...(args)==0)return vector<T>(arg,x);
  else return vector(arg,make_vector<T>(x,args...));
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n,m,k;cin>>n>>m>>k;
  M A(n,m),B(m,k);
  REP(i,n)REP(j,m)cin>>A[i][j];
  REP(j,m)REP(l,k)cin>>B[j][l];
  M C=A*B;
  REP(i,n)cout<<C[i]<<"\n";
}
  


