#pragma once
#define REP_(i,n) for(int i=0;i<(n);i++)
class RankedBitwise{
  static int log2(int N){
    int n=__builtin_ffs(N)-1;
    assert((1<<n)==N);
    return n;
  }
  static bool in(int S,int a){ return (S>>a)&1; }
  static int popcount(int S){ return __builtin_popcount(S); }
public:
  template<typename T>
  static vector<vector<T>> ranked_zeta(const vector<T>&A){
    int n=log2(A.size());
    vector<vector<T>> RA(1<<n,vector<T>(n+1,0));
    REP_(S,1<<n)RA[S][popcount(S)]=A[S];
    REP_(i,n)REP_(S,1<<n)if(!in(S,i))
      REP_(d,n+1)RA[S|(1<<i)][d]+=RA[S][d];
    return RA;
  }
  template<typename T>
  static vector<T> ranked_mobius(vector<vector<T>> RA){
    int n=log2(RA.size());
    REP_(i,n)REP_(S,1<<n)if(!in(S,i))
      REP_(d,n+1)RA[S|(1<<i)][d]-=RA[S][d];
    vector<T> A(1<<n);
    REP(S,1<<n)A[S]=RA[S][popcount(S)];
    return A;
  }
  template<typename T>
  static vector<T> subset_convolution(const vector<T>&A,const vector<T>&B){
    int n=log2(A.size());
    auto RA=ranked_zeta(A);
    auto RB=ranked_zeta(B);
    REP(S,1<<n){
      auto&ra=RA[S],rb=RB[S];
      for(int d=n;d>=0;d--){
        T x=0;
        REP(i,d+1)x+=ra[i]*rb[d-i];
        ra[d]=x;
      }
    }
    return ranked_mobius(RA);
  }
};
#undef REP_