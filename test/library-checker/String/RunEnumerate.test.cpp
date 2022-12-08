#define PROBLEM "https://judge.yosupo.jp/problem/runenumerate"
#include <bits/stdc++.h>
using namespace std;

#include "sequence/RunEnumerate.cpp"

int main(){
  string s;cin>>s;
  RunEnumerate RE(s);
  cout<<RE.ans.size()<<"\n";
  for(const auto&[t,l,r]:RE.ans)cout<<t<<" "<<l<<" "<<r<<"\n";
}