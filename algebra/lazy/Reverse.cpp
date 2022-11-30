#pragma once
#include "algebra/Reverse.cpp"
template<typename Lazy>
struct LazyReverse:Lazy{
  using MX=AlgebraReverse<typename Lazy::MX>;
};
