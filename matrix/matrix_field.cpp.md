---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"matrix/matrix_field.cpp\"\n#define REP_(i,n) for(int i=0;i<(n);i++)\n\
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
    \n  Matrix base() const{\n    Matrix A(M);\n    int now=0;\n    REP_(k,c){\n \
    \     for(int i=now+1;i<r&&A[res][k]==0;i++)\n        if(A[i][k]!=0)swap(A[i],A[now]);\n\
    \      if(A[now][k]==0)continue;\n      REP2_(l,k+1,c)A[now][l]/=A[now][k];\n\
    \      A[now][l]=K(1);\n      REP_(j,r)if(j!=now)\n        REP2_(l,k+1,c)A[j][l]-=A[j][k]*A[now][l];\n\
    \      now++;\n    }\n    A.resize(now);\n    return A;\n  }\n\n  K det() const{\n\
    \    assert(r==c);\n    Matrix A=M;\n    K res(1);\n    REP_(i,r){\n      for(int\
    \ j=i+1;j<c&&A[i][i]==0;j++)\n        if(A[j][i]!=0)swap(A[i],A[j]),res=-res;\n\
    \      if(A[i][i]==0)return res;\n      res*=A[i][i];\n      REP2_(k,i+1,c)A[i][k]/=A[i][i];\n\
    \      REP2_(j,i+1,r)REP2_(k,i+1,c)A[j][k]-=A[j][i]*A[i][k];\n    }\n    return\
    \ res;\n  }\n};\n#undef REP_\n#undef REP2_ \n"
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
    \n  Matrix base() const{\n    Matrix A(M);\n    int now=0;\n    REP_(k,c){\n \
    \     for(int i=now+1;i<r&&A[res][k]==0;i++)\n        if(A[i][k]!=0)swap(A[i],A[now]);\n\
    \      if(A[now][k]==0)continue;\n      REP2_(l,k+1,c)A[now][l]/=A[now][k];\n\
    \      A[now][l]=K(1);\n      REP_(j,r)if(j!=now)\n        REP2_(l,k+1,c)A[j][l]-=A[j][k]*A[now][l];\n\
    \      now++;\n    }\n    A.resize(now);\n    return A;\n  }\n\n  K det() const{\n\
    \    assert(r==c);\n    Matrix A=M;\n    K res(1);\n    REP_(i,r){\n      for(int\
    \ j=i+1;j<c&&A[i][i]==0;j++)\n        if(A[j][i]!=0)swap(A[i],A[j]),res=-res;\n\
    \      if(A[i][i]==0)return res;\n      res*=A[i][i];\n      REP2_(k,i+1,c)A[i][k]/=A[i][i];\n\
    \      REP2_(j,i+1,r)REP2_(k,i+1,c)A[j][k]-=A[j][i]*A[i][k];\n    }\n    return\
    \ res;\n  }\n};\n#undef REP_\n#undef REP2_ "
  dependsOn: []
  isVerificationFile: false
  path: matrix/matrix_field.cpp
  requiredBy: []
  timestamp: '2022-05-07 20:31:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/matrix_field.cpp
layout: document
redirect_from:
- /library/matrix/matrix_field.cpp
- /library/matrix/matrix_field.cpp.html
title: matrix/matrix_field.cpp
---
