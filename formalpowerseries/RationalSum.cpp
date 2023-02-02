#pragma once
#include "formalpowerseries/Base.cpp"
template<typename FPS>
class RationalSum{
  queue<pair<FPS,FPS>> que;
public:
  void add(const FPS&f,const FPS&g){ que.emplace(f,g); }
  FPS sum(){
    if(!que.size())return FPS(0);
    while(que.size()>1){
      auto [a1,b1]=que.front();que.pop();
      auto [a2,b2]=que.front();que.pop();
      que.emplace(a1*b2+a2*b1,b1*b2);
    }
    auto [a,b]=que.front();que.pop();
    return a/b;
  }
};
