#include <atcoder/string>
using namespace atcoder;

#define SIZE_(s) int(s.size())
struct RunEnumerate{
  string s;
  RunEnumerate(string s):s(s){ build(); }

  struct Run{
    int t,l,r;
    Run()=default;
    Run(int t,int l,int r):t(t),l(l),r(r){}
  };
  vector<Run> ans;

  queue<pair<int,int>> que;
  string REV(string s){ reverse(s.begin(),s.end()); return s; }
  void solve(int l,int r){
    int m=(l+r)>>1;
    que.emplace(l,m);que.emplace(m,r);
    string left_s=s.substr(l,m-l), right_s=s.substr(m,r-m), all_s=s.substr(l,r-l);
    {
      // 各 k に対し、left_s の suffix t 文字を周期とする run を探す
      auto Z_left_rev = z_algorithm( REV(left_s) );
      auto Left = [&](int t)->int{
        // [*,m) が周期 t
        if(t==SIZE_(left_s))return l;
        return m-t-Z_left_rev[t];
      };
      auto Z_right = z_algorithm( right_s+"#"+all_s );
      auto Right = [&](int t)->int{
        // [m,*)
        return m+Z_right[r-l-t+1];
      };
      for(int t=1;t<=m-l;t++){
        int L=Left(t),R=Right(t);
        if(R-L>=2*t)ans.emplace_back(t,L,R);
      }
    }
    {
      // [m,r) の prefix t 文字
      auto Z_right = z_algorithm( right_s );
      auto Right = [&](int t)->int{
        if(t==SIZE_(right_s))return r;
        return m+t+Z_right[t];
      };
      auto Z_left = z_algorithm( REV(left_s)+"#"+REV(all_s) );
      auto Left = [&](int t)->int{
        return m-Z_left[ SIZE_(Z_left)-SIZE_(left_s)-t ];
      };
      for(int t=1;t<=r-m;t++){
        int L=Left(t),R=Right(t);
        if(R-L>=2*t)ans.emplace_back(t,L,R);
      }
    }
  }

  void arrangement(){
    vector<Run> fans;
    sort(ans.begin(),ans.end(),[](Run a,Run b){
      if(a.t!=b.t)return a.t<b.t;
      if(a.l!=b.l)return a.l<b.l;
      return a.r>b.r;
    });
    set<pair<int,int>> already;
    int pret=-1,mx;
    for(const auto&[t,l,r]:ans){
      if(pret!=t)pret=t,mx=-1;
      if(already.count({l,r})||mx>=r)continue;
      if( (r<SIZE_(s) and s[r]==s[r-t]) or (l-1>=0 and s[l-1]==s[l-1+t]) )continue;
      fans.emplace_back(t,l,r);
      already.emplace(l,r);
      mx=r;
    }
    ans=fans;
  }

  void build(){
    que.emplace(0,int(s.size()));
    while(que.size()){
      auto[l,r]=que.front();que.pop();
      if(l+1==r)continue;
      solve(l,r);
    }
    arrangement();
  }
};
#undef SIZE_