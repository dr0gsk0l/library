#pragma once
#include "bitwise/Util.cpp"
#define REP_(i,n) for(int i=0;i<(n);i++)
#define RREP_(i,n) for(int i=(n)-1;i>=0;i--)
struct BitwiseXor{
  template<typename T>
  static void zeta(vector<T>&A){
    const int n=bitwise::log2(A.size());
    REP_(i,n)
      REP_(S,1<<n){
        if(bitwise::in(S,i))continue;
        T x=A[S],y=A[S|(1<<i)];
        A[S]-=y;
        A[S|(1<<i)]+=x;
      }
  }
  template<typename T>
  static void mobius(vector<T>&A){
    const int n=bitwise::log2(A.size());
    RREP_(i,n)
      REP_(S,1<<n){
        if(bitwise::in(S,i))continue;
        T x=A[S],y=A[S|(1<<i)];
        A[S]+=y
        A[S|(1<<i)]-=x;
      }
    T inv=T(1)/(1<<n);
    REP(S,1<<n)A[S]*=inv;
  }
  template<typename T>
  static vector<T> convolution(vector<T> A,vector<T> B){
    zeta(A);
    zeta(B);
    REP(S,A.size())A[S]*=B[S];
    mobius(A);
    return A;
  }
};
#undef REP_
#undef RREP_