#define PROBLEM "https://yukicoder.me/problems/no/755"
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,s,n) for(int i=(s);i<(n);i++)

#include "datastructure/2D/CumulativeSum.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n,m;cin>>n>>m;
  vector v(m,vector<int>(m));
  REP(i,m)REP(j,m)cin>>v[i][j];
  CumulativeSum2D C(v);

  REP(_,n){
    int y,x;cin>>y>>x;y--;x--;
    int ans=0;
    REP(u,y+1)REP2(d,y+1,m+1)REP(l,x+1)REP2(r,x+1,m+1)
      ans += !C.sum(u,d,l,r);
    cout<< ans <<"\n";
  }
}