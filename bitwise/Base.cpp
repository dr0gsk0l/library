#pragma once
#define REP_(i,n) for(int i=0;i<(n);i++)
class Bitwise{
  static int log2(int N){
    int n=__builtin_ffs(N)-1;
    assert((1<<n)==N);
    return n;
  }
  static bool in(int S,int a){ return (S>>a)&1; }
public:
  template<typename T>
  static void superset_zeta(vector<T>& A){
    int n=log2(A.size());
    REP_(k,n)REP_(S,1<<n)if(!in(S,k))A[S]+=A[S^(1<<k)];
  }
  template<typename T>
  static void superset_mobius(vector<T>& A){
    int n=log2(A.size());
    REP_(k,n)REP_(S,1<<n)if(!in(S,k))A[S]-=A[S^(1<<k)];
  }
  template<typename T>
  static void subset_zeta(vector<T>& A){
    int n=log2(A.size());
    REP_(k,n)REP_(S,1<<n)if(in(S,k))A[S]+=A[S^(1<<k)];
  }
  template<typename T>
  static void subset_mobius(vector<T>& A){
    int n=log2(A.size());
    REP_(k,n)REP_(S,1<<n)if(in(S,k))A[S]-=A[S^(1<<k)];
  }
  template<typename T>
  static vector<T> and_convolution(vector<T> A,vector<T> B){
    assert(A.size()==B.size());
    superset_zeta(A);
    superset_zeta(B);
    REP_(i,A.size())A[i]*=B[i];
    superset_mobius(A);
    return A;
  }
  template<typename T>
  static vector<T> or_convolution(vector<T> A,vector<T> B){
    assert(A.size()==B.size());
    subset_zeta(A);
    subset_zeta(B);
    REP_(i,A.size())A[i]*=B[i];
    subset_mobius(A);
    return A;
  }
};
#undef REP_