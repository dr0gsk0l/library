#pragma once
#include "bitwise/Util.cpp"
#define REP_(i,n) for(int i=0;i<(n);i++)
struct BitwiseOr{
  template<typename T>
  static void zeta(vector<T>& A){
    int n=bitwise::log2(A.size());
    REP_(k,n)REP_(S,1<<n)if(bitwise::in(S,k))A[S]+=A[S^(1<<k)];
  }
  template<typename T>
  static void mobius(vector<T>& A){
    int n=bitwise::log2(A.size());
    REP_(k,n)REP_(S,1<<n)if(bitwise::in(S,k))A[S]-=A[S^(1<<k)];
  }
  template<typename T>
  static vector<T> convolution(vector<T> A,vector<T> B){
    assert(A.size()==B.size());
    zeta(A);
    zeta(B);
    REP_(i,A.size())A[i]*=B[i];
    mobius(A);
    return A;
  }
};
#undef REP_