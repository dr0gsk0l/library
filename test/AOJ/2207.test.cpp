#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2207"
#include <bits/stdc++.h>
using namespace std;

#include "datastructure/unionfind/PotentialUnionFind.cpp"
#include "algebra/group/Add.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  while(cin>>n,n){
    PotentialUnionFind<GroupAdd<int>> uf(2*n);
    map<string,int> id;
    string ans="Yes\n";
    while(n--){
      int x;
      string a,b;
      char c;
      cin>>x>>a>>c>>x>>c>>x>>b;
      if(!id.count(a))id[a]=id.size();
      if(!id.count(b))id[b]=id.size();
      if( !uf.merge(id[a],id[b],x) ) ans="No\n";
    }
    cout<<ans;
  }
}
