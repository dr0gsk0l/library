#define PROBLEM "https://yukicoder.me/problems/no/2109"
#include <bits/stdc++.h>
using namespace std;

#include "datetime/DateTime.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m,d,k;cin>>m>>d>>k;

  DateTime now(1,m,d);
  set<char> se;
  for(int i=0;i<7;i++,now++){
    string s=now.to_string();
    for(int i=5;i<s.size();i++)se.insert(s[i]);
  }
  cout<<(se.size()<=k?"No\n":"Yes\n");
}