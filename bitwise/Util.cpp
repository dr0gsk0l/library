#pragma once
namespace bitwise{
  static int log2(int N){
    int n=__builtin_ffs(N)-1;
    assert((1<<n)==N);
    return n;
  }
  static bool in(int S,int a){ return (S>>a)&1; }
}