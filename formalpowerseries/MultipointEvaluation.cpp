#pragma once
#include "formalpowerseries/Base.cpp"
#include "formalpowerseries/DivMod.cpp"
template<typename FPS,typename T=typename FPS::value_type>
vector<T> multipoint_evaluation(const FPS&f,vector<T> v){
  int m=v.size();
  int sz;
  for(sz=1;sz<m;sz*=2){}
  vector<FPS> t(sz*2);
  for(int i=0;i<sz;i++)t[sz+i] = {(i<m ? -v[i] : 0), 1};
  for(int i=sz-1;i>0;i--)t[i] = t[2*i]*t[2*i+1];

  t[0]=f;
  for(int i=1;i<sz+m;i++)
    t[i] = div_mod(t[i>>1],t[i]).second;
    
  for(int i=0;i<m;i++)v[i]=t[sz+i][0];
  return v;
}
