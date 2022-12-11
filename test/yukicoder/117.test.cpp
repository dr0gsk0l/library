#define PROBLEM "https://yukicoder.me/problems/no/117"
#include <bits/stdc++.h>
using namespace std;

#include "mod/Modint.cpp"
#include "mod/MintUtility.cpp"

using mint=Mint<long long,1000'000'007>;
MintUtility<mint> M;

mint solve(){
  string s;cin>>s;
  int comma=0;
  while(s[comma]!=',')comma++;
  int n=stoi(s.substr(2,comma-1));
  int k=stoi(s.substr(comma+1,s.size()-comma-1));
  if(s[0]=='C')return M.nCk(n,k);
  if(s[0]=='P')return M.nPk(n,k);
  return M.nHk(n,k);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int testsize;cin>>testsize;
  while(testsize--)cout<<solve()<<'\n';
}