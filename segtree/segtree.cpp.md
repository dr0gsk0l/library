---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/PointSetRangeComposite.test.cpp
    title: test/yosupo/PointSetRangeComposite.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segtree/segtree.cpp\"\ntemplate <typename Monoid>\nstruct\
    \ SegmentTree{\n  int n;\n  vector<Monoid> dat;\n  SegmentTree(int n_){\n    n=1;\n\
    \    while(n<n_)n<<=1;\n    dat.assign(n<<1,{});\n  }\n  SegmentTree(const vector<Monoid>\
    \ &v){\n    int n_=v.size();\n    n=1;\n    while(n<n_) n<<=1;\n    dat.assign(n<<1,{});\n\
    \    for(int i=0;i<n_;i++)dat[n+i]=v[i];\n    for(int i=n-1;i;i--)\n      dat[i]=dat[(i<<1)|0]+dat[(i<<1)|1];\n\
    \  }\n  \n  Monoid operator [](int k) const{return dat[k+n];}\n  \n  void init(int\
    \ n_){\n    n=1;\n    while(n<n_)n<<=1;\n    dat.assign(n<<1,{});\n  }\n  \n \
    \ void build(const vector<Monoid>&v){\n    int n_=v.size();\n    init(n_);\n \
    \   for(int i=0;i<n_;i++)dat[n+i]=v[i];\n    for(int i=n-1;i;i--)\n      dat[i]=dat[(i<<1)|0]+dat[(i<<1)|1];\n\
    \  }\n  \n  void set_val(int k,Monoid x){\n    dat[k+=n]=x;  \n    while(k>>=1)\n\
    \      dat[k]=dat[(k<<1)|0]+dat[(k<<1)|1];\n  }\n\n  Monoid query(int a,int b){\n\
    \    Monoid vl{},vr{};\n    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {\n      if(l&1)\
    \ vl=vl+dat[l++];\n      if(r&1) vr=dat[--r]+vr;\n    }\n    return vl+vr;\n \
    \ } \n};\n"
  code: "template <typename Monoid>\nstruct SegmentTree{\n  int n;\n  vector<Monoid>\
    \ dat;\n  SegmentTree(int n_){\n    n=1;\n    while(n<n_)n<<=1;\n    dat.assign(n<<1,{});\n\
    \  }\n  SegmentTree(const vector<Monoid> &v){\n    int n_=v.size();\n    n=1;\n\
    \    while(n<n_) n<<=1;\n    dat.assign(n<<1,{});\n    for(int i=0;i<n_;i++)dat[n+i]=v[i];\n\
    \    for(int i=n-1;i;i--)\n      dat[i]=dat[(i<<1)|0]+dat[(i<<1)|1];\n  }\n  \n\
    \  Monoid operator [](int k) const{return dat[k+n];}\n  \n  void init(int n_){\n\
    \    n=1;\n    while(n<n_)n<<=1;\n    dat.assign(n<<1,{});\n  }\n  \n  void build(const\
    \ vector<Monoid>&v){\n    int n_=v.size();\n    init(n_);\n    for(int i=0;i<n_;i++)dat[n+i]=v[i];\n\
    \    for(int i=n-1;i;i--)\n      dat[i]=dat[(i<<1)|0]+dat[(i<<1)|1];\n  }\n  \n\
    \  void set_val(int k,Monoid x){\n    dat[k+=n]=x;  \n    while(k>>=1)\n     \
    \ dat[k]=dat[(k<<1)|0]+dat[(k<<1)|1];\n  }\n\n  Monoid query(int a,int b){\n \
    \   Monoid vl{},vr{};\n    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {\n      if(l&1)\
    \ vl=vl+dat[l++];\n      if(r&1) vr=dat[--r]+vr;\n    }\n    return vl+vr;\n \
    \ } \n};"
  dependsOn: []
  isVerificationFile: false
  path: segtree/segtree.cpp
  requiredBy: []
  timestamp: '2022-02-07 17:45:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/PointSetRangeComposite.test.cpp
documentation_of: segtree/segtree.cpp
layout: document
redirect_from:
- /library/segtree/segtree.cpp
- /library/segtree/segtree.cpp.html
title: segtree/segtree.cpp
---
