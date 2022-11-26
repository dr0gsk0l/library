#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D&lang=ja"
#include <bits/stdc++.h>
using namespace std;

#include "util/InversionNumber.cpp"

int main(){
  int n;cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  cout<<inversion_number(v)<<endl;
}