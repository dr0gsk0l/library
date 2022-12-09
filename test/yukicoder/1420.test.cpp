#define PROBLEM "https://yukicoder.me/problems/no/1420"
#include <bits/stdc++.h>
using namespace std;

#include "datastructure/unionfind/PotentialUnionFind.cpp"
#include "algebra/group/Xor.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;cin>>n>>m;
  PotentialUnionFind< GroupXor< int > > UF(n);
  while(m--){
    int a,b,y;cin>>a>>b>>y;a--;b--;
    if(!UF.merge(a,b,y)){
      cout<<-1<<"\n";
      return 0;
    }
  }
  for(int i=0;i<n;i++)
    cout<< UF.from_root(i).second <<"\n";
}