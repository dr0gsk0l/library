#define PROBLEM "https://yukicoder.me/problems/no/430"
#include <bits/stdc++.h>
using namespace std;

#include "sequence/Trie.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string s;cin>>s;
  auto ss=FSA::change(s);

  Trie<char,26> T;
  
  int m;cin>>m;
  while(m--){
    string c;cin>>c;
    auto cc=FSA::change(c);
    T.add(cc);
  }

  int ans=0;
  for(int i=0;i<ss.size();i++)
    T.query(ss,[&](int id){ans+=T.val(id);},i);
  cout<<ans<<endl;
}