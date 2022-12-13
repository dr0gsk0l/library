#define PROBLEM ""
#include <bits/stdc++.h>
using namespace std;

#include "datastructure/WaveletMatrix.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;cin>>n>>q;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  WaveletMatrix WM(v);
  
  while(q--){
    int l,r,x;cin>>l>>r>>x;
    cout<<WM.rank(l,r,x)<<"\n";
  }
}