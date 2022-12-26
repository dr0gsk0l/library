#pragma once
template<typename T>
class Vector{
  int m;
  vector<T> v;

  Vector()=default;
  Vector(int n,T x={}):v(n,x),m(0){}
  Vector(int L,int R,T x):v(L+R,x),m(L){}
};