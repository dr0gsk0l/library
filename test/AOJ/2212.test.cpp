#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2212"
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

#include "sequence/AhoCorasick.cpp"
#include "graph/Grid.cpp"

const map<char,int> mp{{'D',0},{'R',1},{'U',2},{'L',3}};

int solve(int h,int w){
  vector<string> s(h);
  REP(i,h)cin>>s[i];

  Grid<char> GR(s,'#');
  int S=GR.find('S'),T=GR.find('G');
  auto&G=GR.G;

  set<int> ban;
  AhoCorasick<char,4> AC;
  int m;cin>>m;
  REP(_,m){
    string t;cin>>t;
    vector<char> tt(t.size());
    REP(i,t.size())tt[i]=mp.at(t[i]);
    ban.insert(AC.add(tt));
  }
  AC.build();

  vector dp(h*w,vector<int>(AC.size(),-1));
  queue<pair<int,int>> que;
  que.emplace(S,0);
  dp[S][0]=0;
  while(que.size()){
    auto [idx,now]=que.front();que.pop();
    for(auto&e:G[idx]){
      int nxt=AC.nxt(now,e.weight);
      if(ban.count(nxt))continue;
      if(dp[e.to][nxt]<0){
        dp[e.to][nxt]=dp[idx][now]+1;
        que.emplace(e.to,nxt);
      }
      if(e.to==T)return dp[e.to][nxt];
    }
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int h,w;
  while(cin>>h>>w,h)cout<<solve(h,w)<<"\n";
}