#pragma once
#include "formalpowerseries/Base.cpp"
template<typename FPS>
class FPSProd{
  queue<FPS> que;
public:
  void add(const FPS&f){ que.push(f); }
  FPS prod(){
    if(!que.size())return FPS::unit();
    while(que.size()>1){
      FPS f=que.front();que.pop();
      FPS g=que.front();que.pop();
      que.push(f*g);
    }
    FPS res=que.front();que.pop();
    return res;
  }
};

template<typename FPS>
class FPSProdDiversity{
  static constexpr auto cmp=[](const FPS&f,const FPS&g){ return f.size()>g.size(); };
  priority_queue<FPS,vector<FPS>,decltype(cmp)> que{cmp};
public:
  void add(const FPS&f){ que.push(f); }
  FPS prod(){
    if(!que.size())return FPS::unit();
    while(que.size()>1){
      FPS f=que.top();que.pop();
      FPS g=que.top();que.pop();
      que.push(f*g);
    }
    FPS res=que.top();que.pop();
    return res;
  }
};