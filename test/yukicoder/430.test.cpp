#define PROBLEM "https://yukicoder.me/problems/no/430"
#include <bits/stdc++.h>
using namespace std;

#include "sequence/ForString.cpp"
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
  for(int i=0;i<ss.size();i++){
    int now=0;
    for(int j=i;j<ss.size();j++){
      int nxt=T.nxt(now,ss[j]);
      if(nxt==-1)break;
      now=nxt;
      ans+=T.val(now);
    }
  }
  cout<<ans<<endl;
}