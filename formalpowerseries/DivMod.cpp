#pragma once
#include "formalpowerseries/Base.cpp"
#define REVERSE_(f) reverse(f.begin(),f.end());
template<typename FPS>
pair<FPS,FPS> div_mod(FPS f,FPS g){
  f.shrink();
  g.shrink();
  assert(g.size());
  if(f.size()<g.size())return {FPS(0),f};
  REVERSE_(f);
  REVERSE_(g);
  int d=f.size()-g.size()+1;
  FPS q = (f.pre(d) * g.inv(d)).pre(d);
  if(q.size()<d)q.resize(d,0);
  REVERSE_(q);
  REVERSE_(f);
  REVERSE_(g);
  return {q,f-q*g};
}
#undef REVERSE_