---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: matrix.cpp
    title: Matrix
  - icon: ':heavy_check_mark:'
    path: mod/modint.cpp
    title: mod/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/yosupo/DeterminantOfMatrix.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"matrix.cpp\"\n#define REP_(i,n) for(int i=0;i<(n);i++)\n\
    #define REP2_(i,s,n) for(int i=(s);i<(n);i++)\ntemplate<typename K>\nstruct Matrix{\n\
    \  typedef vector<K> vec;\n  typedef vector<vec> mat;\n  size_t r,c;\n  mat M;\n\
    \n  Matrix(size_t r,size_t c):r(r),c(c),M(r,vec(c,K())){}\n  Matrix(mat A):M(A),r(A.size()),c(A[0].size()){}\n\
    \n  vec& operator[](size_t k){return M[k];}\n  const vec& operator[](size_t k)const{return\
    \ M[k];}\n\n  friend Matrix operator+(const Matrix &A,const Matrix &B){\n    assert(A.r==B.r&&A.c==B.c);\n\
    \    Matrix res(A);\n    REP_(i,A.r)REP_(j,A.c)res[i][j]+=B[i][j];\n    return\
    \ res;\n  }\n\n  Matrix& operator+=(const Matrix &B){\n    assert(r==B.r&&c==B.c);\n\
    \    REP_(i,r)REP_(j,c)M[i][j]+=B[i][j];\n    return *this;\n  }\n\n  friend Matrix\
    \ operator*(const Matrix &A,const Matrix &B){\n    assert(A.c==B.r);\n    Matrix\
    \ res(A.r,B.c);\n    REP_(i,A.r)REP_(k,A.c)REP_(j,B.c)res[i][j]+=A[i][k]*B[k][j];\n\
    \    return res;\n  }\n\n  Matrix& operator*=(const Matrix &B){\n    M=((*this)*B).M;\n\
    \    return *this;\n  }\n\n  static Matrix I(size_t n){\n    Matrix res(n,n);\n\
    \    REP_(i,n)res[i][i]=K(1);\n    return res;\n  }\n\n  Matrix pow(long long\
    \ n)const{\n    assert(n>=0&&r==c);\n    Matrix A(M),res=I(r);\n    while(n){\n\
    \      if(n&1)res*=A;\n      A*=A;\n      n>>=1;\n    }\n    return res;\n  }\n\
    \n  int rank() const{\n    Matrix A(M);\n    int res=0;\n    REP_(k,c){\n    \
    \  for(int i=res+1;i<r&&A[res][k]==0;i++)\n        if(A[i][k]!=0)swap(A[i],A[res]);\n\
    \      if(A[res][k]==0)continue;\n      REP2_(l,k+1,c)A[res][l]/=A[res][k];\n\
    \      REP2_(j,res+1,r)REP2_(l,k+1,c)A[j][l]-=A[j][k]*A[res][l];\n      res++;\n\
    \    }\n    return res;\n  }\n\n  K det() const{\n    assert(r==c);\n    Matrix\
    \ A=M;\n    K res(1);\n    REP_(i,r){\n      for(int j=i+1;j<c&&A[i][i]==0;j++)\n\
    \        if(A[j][i]!=0)swap(A[i],A[j]),res=-res;\n      if(A[i][i]==0)return 0;\n\
    \      res*=A[i][i];\n      REP2_(k,i+1,c)A[i][k]/=A[i][i];\n      REP2_(j,i+1,r)REP2_(k,i+1,c)A[j][k]-=A[j][i]*A[i][k];\n\
    \    }\n    return res;\n  }\n};\n#undef REP_\n#undef REP2_\n\n/**\n* @docs //docs/matrix.md\n\
    */\n#line 1 \"mod/modint.cpp\"\ntemplate<typename T,T MOD=998244353>\nstruct Mint{\n\
    \  inline static constexpr T mod = MOD;\n  T v;\n  Mint():v(0){}\n  Mint(signed\
    \ v):v(v){}\n  Mint(long long t){v=t%MOD;if(v<0)v+=MOD;}\n\n  Mint pow(long long\
    \ k){\n    Mint res(1),tmp(v);\n    while(k){\n      if(k&1)res*=tmp;\n      tmp*=tmp;\n\
    \      k>>=1;\n    }\n    return res;\n  }\n\n  static Mint add_identity(){return\
    \ Mint(0);}\n  static Mint mul_identity(){return Mint(1);}\n\n  Mint inv(){return\
    \ pow(MOD-2);}\n\n  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}\n\
    \  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}\n  Mint&\
    \ operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}\n  Mint& operator/=(Mint a){return\
    \ (*this)*=a.inv();}\n\n  Mint operator+(Mint a) const{return Mint(v)+=a;}\n \
    \ Mint operator-(Mint a) const{return Mint(v)-=a;}\n  Mint operator*(Mint a) const{return\
    \ Mint(v)*=a;}\n  Mint operator/(Mint a) const{return Mint(v)/=a;}\n\n  Mint operator+()\
    \ const{return *this;}\n  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}\n\
    \n  bool operator==(const Mint a)const{return v==a.v;}\n  bool operator!=(const\
    \ Mint a)const{return v!=a.v;}\n\n  static Mint comb(long long n,int k){\n   \
    \ Mint num(1),dom(1);\n    for(int i=0;i<k;i++){\n      num*=Mint(n-i);\n    \
    \  dom*=Mint(i+1);\n    }\n    return num/dom;\n  }\n\n  friend ostream& operator<<(ostream&os,const\
    \ Mint &m){os<<m.v;return os;}\n  friend istream& operator>>(istream&is,Mint &m){is>>m.v;m.v%=MOD;if(m.v<0)m.v+=MOD;return\
    \ is;}\n};\n\n#line 8 \"test/yosupo/DeterminantOfMatrix.test.cpp\"\n\nusing mint=Mint<long\
    \ long>;\nusing M=Matrix<mint>;\n\n#define REP(i,n) for(int i=0;i<(n);i++)\n\n\
    int main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  \n  int n;cin>>n;\n\
    \  M A(n,n);\n  REP(i,n)REP(j,n)cin>>A[i][j];\n  cout<<A.det()<<endl;\n}\n  \n\
    \n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../matrix.cpp\"\n#include\
    \ \"../../mod/modint.cpp\"\n\nusing mint=Mint<long long>;\nusing M=Matrix<mint>;\n\
    \n#define REP(i,n) for(int i=0;i<(n);i++)\n\nint main(){\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  \n  int n;cin>>n;\n  M A(n,n);\n  REP(i,n)REP(j,n)cin>>A[i][j];\n\
    \  cout<<A.det()<<endl;\n}\n  \n\n\n"
  dependsOn:
  - matrix.cpp
  - mod/modint.cpp
  isVerificationFile: true
  path: test/yosupo/DeterminantOfMatrix.test.cpp
  requiredBy: []
  timestamp: '2022-05-08 10:53:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/DeterminantOfMatrix.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/DeterminantOfMatrix.test.cpp
- /verify/test/yosupo/DeterminantOfMatrix.test.cpp.html
title: test/yosupo/DeterminantOfMatrix.test.cpp
---
