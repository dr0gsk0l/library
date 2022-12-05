#define PROBLEM "https://yukicoder.me/problems/no/1077"
#include <bits/stdc++.h>
using namespace std;

#include "datastructure/SlopeTrick.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;
  SlopeTrick<int> ST;
  while(n--){
    int v;cin>>v;
    ST.clear_inc();
    ST.add_abs(v);
  }
  cout<<ST.min_f<<endl;
}