#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2427"
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

#include "datastructure/unionfind/PotentialUnionFind.cpp"
#include "algebra/group/Add.cpp"

int pw(int n,int k){
  assert(k>=0);
  int res=1;
  while(k){
    if(k&1)res*=n;
    n*=n;
    k>>=1;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int dist,n,m;cin>>dist>>n>>m;
  vector<int> s(n),d(m);
  REP(i,n)cin>>s[i];
  REP(j,m)cin>>t[j];

  int ans=1e9;
  REP(S,n*(n-1))
}
