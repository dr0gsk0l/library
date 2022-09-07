#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include <bits/stdc++.h>
using namespace std;

#include <atcoder/twosat>
using namespace atcoder;

int main(){
  string hoge;cin>>hoge>>hoge;
  int n,m;cin>>n>>m;
  two_sat ts(n);
  while(m--){
    int a,b,c;cin>>a>>b>>c;
    bool f_a=a>0,f_b=b>0;
    ts.add_clause(abs(a)-1,f_a,abs(b)-1,f_b);
  }
  if(ts.satisfiable()){
    cout<<"s SATISFIABLE\n";
    cout<<"v ";
    auto A=ts.answer();
    for(int i=0;i<n;i++)cout<<(A[i]?i+1:-(i+1))<<" ";
    cout<<"0\n";
  }
  else cout<<"s UNSATISFIABLE\n";
}