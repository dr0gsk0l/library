#define PROBLEM "https://yukicoder.me/problems/no/1332"
#include <bits/stdc++.h>
using namespace std;

#include "datastructure/WaveletMatrix.cpp"
const int INF=1e9;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  WaveletMatrix WM(v);
  
  int q;cin>>q;
  while(q--){
    int l,r,x;cin>>l>>r>>x;l--;
    cout<<min(x-(WM.leq(l,r,x)).value_or(-INF), (WM.geq(l,r,x)).value_or(2*INF)-x)<<"\n"; 
  }
}