#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"
#include <bits/stdc++.h>
using namespace std;

#include "sequence/RollingHash.cpp"

int main(){
  string t;cin>>t;
  RollingHash T(t);
  string p;cin>>p;
  auto h=RollingHash::full_hash(p);
  for(int i=0;i+p.size()<=t.size();i++)
    if(T.get_hash(i,i+p.size())==h)
      cout<<i<<"\n";
}