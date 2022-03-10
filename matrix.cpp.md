---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/DeterminantOfMatrix.test.cpp
    title: test/yosupo/DeterminantOfMatrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/MatrixProduct.test.cpp
    title: test/yosupo/MatrixProduct.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: //docs/matrix.md
    links: []
  bundledCode: "#line 1 \"matrix.cpp\"\n#define REP_(i,n) for(int i=0;i<(n);i++)\n\
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
    \        if(A[j][i]!=0)swap(A[i],A[j]),res*=-1;\n      res*=A[i][i];\n      if(A[i][i]==0)return\
    \ res;\n      REP2_(k,i+1,c)A[i][k]/=A[i][i];\n      REP2_(j,i+1,r)REP2_(k,i+1,c)A[j][k]-=A[j][i]*A[i][k];\n\
    \    }\n    return res;\n  }\n};\n#undef REP_\n#undef REP2_\n\n/**\n* @docs //docs/matrix.md\n\
    */\n"
  code: "#define REP_(i,n) for(int i=0;i<(n);i++)\n#define REP2_(i,s,n) for(int i=(s);i<(n);i++)\n\
    template<typename K>\nstruct Matrix{\n  typedef vector<K> vec;\n  typedef vector<vec>\
    \ mat;\n  size_t r,c;\n  mat M;\n\n  Matrix(size_t r,size_t c):r(r),c(c),M(r,vec(c,K())){}\n\
    \  Matrix(mat A):M(A),r(A.size()),c(A[0].size()){}\n\n  vec& operator[](size_t\
    \ k){return M[k];}\n  const vec& operator[](size_t k)const{return M[k];}\n\n \
    \ friend Matrix operator+(const Matrix &A,const Matrix &B){\n    assert(A.r==B.r&&A.c==B.c);\n\
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
    \        if(A[j][i]!=0)swap(A[i],A[j]),res*=-1;\n      res*=A[i][i];\n      if(A[i][i]==0)return\
    \ res;\n      REP2_(k,i+1,c)A[i][k]/=A[i][i];\n      REP2_(j,i+1,r)REP2_(k,i+1,c)A[j][k]-=A[j][i]*A[i][k];\n\
    \    }\n    return res;\n  }\n};\n#undef REP_\n#undef REP2_\n\n/**\n* @docs //docs/matrix.md\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: matrix.cpp
  requiredBy: []
  timestamp: '2022-03-10 13:30:32+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/DeterminantOfMatrix.test.cpp
  - test/yosupo/MatrixProduct.test.cpp
documentation_of: matrix.cpp
layout: document
title: Matrix
---

- `Matrix<K> M(size_t r,size_t c)`
  - 体$K$上の$r\times c$行列を生成
- `Matrix<K> M(vector<vector<K>> A)`
  - 二次元ベクトルAから行列を生成
- `+,+=,*,*=`
  - 行列同士の各種演算
- `Matrix I(size_t n)`
  - サイズ$n$の単位行列を返す
- `Matrix pow(long long n)`
  - $M$が正方行列のとき$M^n$を返す
  - サイズ$r\times r$として$O(r^3 log(n))$
- `int rank()`
  - 行列のランクを返す`
  - $O(rc^2)$
- `K det()`
  - $M$が正方行列のとき行列式を返す
  - $O(r^3)$
