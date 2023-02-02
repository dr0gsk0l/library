#pragma once
#include "formalpowerseries/Base.cpp"
#include "formalpowerseries/RationalSum.cpp"
// f(e^x)
template<typename FPS>
void compose_exp(FPS&f){
  f.shrink();
  if(f.size()<=1)return;
  RationalSum<FPS> RS;
  for(int n=0;n<f.size();n++)
    RS.add(FPS{f[n]},FPS{1,-n});
  f=RS.sum();
  typename FPS::value_type fact=1;
  for(int n=1;n<f.size();fact*=++n)
    f[n]/=fact;
}