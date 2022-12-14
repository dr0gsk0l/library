#define PROBLEM "https://yukicoder.me/problems/no/430"
#include <bits/stdc++.h>
using namespace std;

#include "sequence/AhoCorasick.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string s;cin>>s;
  auto ss=FSA::change(s);

  AhoCorasick<char,26> T;
  
  int m;cin>>m;
  while(m--){
    string c;cin>>c;
    auto cc=FSA::change(c);
    T.add(cc);
  }
  T.build();
  
  cout<< T.path_prod(ss) <<endl;
}