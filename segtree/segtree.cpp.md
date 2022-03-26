---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/PointSetRangeComposite.test.cpp
    title: test/yosupo/PointSetRangeComposite.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segtree/segtree.cpp\"\ntemplate<typename T>\nstruct SegmentTree{\n\
    \  using F=function<T(T,T)>;\n  int n;\n  F f;\n  T ti;\n  vector<T> dat;\n  SegmentTree(){}\n\
    \  SegmentTree(F f,T ti,int n_=1):f(f),ti(ti){\n    n=1;\n    while(n<n_)n<<=1;\n\
    \    dat.assign(n<<1,ti);\n  }\n  SegmentTree(F f,T ti,const vector<T>&v):f(f),ti(ti){\n\
    \    int n_=v.size();\n    n=1;\n    while(n<n_) n<<=1;\n    dat.assign(n<<1,ti);\n\
    \    for(int i=0;i<n_;i++)dat[n+i]=v[i];\n    for(int i=n-1;i;i--)\n      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);\n\
    \  }\n  \n  void init(int n_){\n    n=1;\n    while(n<n_)n<<=1;\n    dat.assign(n<<1,ti);\n\
    \  }\n  \n  void build(const vector<T>&v){\n    int n_=v.size();\n    init(n_);\n\
    \    for(int i=0;i<n_;i++)dat[n+i]=v[i];\n    for(int i=n-1;i;i--)\n      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);\n\
    \  }\n\n  T operator [](int k) const{return dat[k+n];}\n  \n  void set_val(int\
    \ k,T x){\n    dat[k+=n]=x;  \n    while(k>>=1)\n      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);\n\
    \  }\n  \n  T query(int a,int b){\n    T vl=ti,vr=ti;\n    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1)\
    \ {\n      if(l&1) vl=f(vl,dat[l++]);\n      if(r&1) vr=f(dat[--r],vr);\n    }\n\
    \    return f(vl,vr);\n  }\n};\n"
  code: "template<typename T>\nstruct SegmentTree{\n  using F=function<T(T,T)>;\n\
    \  int n;\n  F f;\n  T ti;\n  vector<T> dat;\n  SegmentTree(){}\n  SegmentTree(F\
    \ f,T ti,int n_=1):f(f),ti(ti){\n    n=1;\n    while(n<n_)n<<=1;\n    dat.assign(n<<1,ti);\n\
    \  }\n  SegmentTree(F f,T ti,const vector<T>&v):f(f),ti(ti){\n    int n_=v.size();\n\
    \    n=1;\n    while(n<n_) n<<=1;\n    dat.assign(n<<1,ti);\n    for(int i=0;i<n_;i++)dat[n+i]=v[i];\n\
    \    for(int i=n-1;i;i--)\n      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);\n  }\n\
    \  \n  void init(int n_){\n    n=1;\n    while(n<n_)n<<=1;\n    dat.assign(n<<1,ti);\n\
    \  }\n  \n  void build(const vector<T>&v){\n    int n_=v.size();\n    init(n_);\n\
    \    for(int i=0;i<n_;i++)dat[n+i]=v[i];\n    for(int i=n-1;i;i--)\n      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);\n\
    \  }\n\n  T operator [](int k) const{return dat[k+n];}\n  \n  void set_val(int\
    \ k,T x){\n    dat[k+=n]=x;  \n    while(k>>=1)\n      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);\n\
    \  }\n  \n  T query(int a,int b){\n    T vl=ti,vr=ti;\n    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1)\
    \ {\n      if(l&1) vl=f(vl,dat[l++]);\n      if(r&1) vr=f(dat[--r],vr);\n    }\n\
    \    return f(vl,vr);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: segtree/segtree.cpp
  requiredBy: []
  timestamp: '2022-03-26 14:25:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/PointSetRangeComposite.test.cpp
documentation_of: segtree/segtree.cpp
layout: document
title: SegmentTree
---

## 概要
数列 $a_0,\dots,a_{n-1}$ に対し、一点代入と区間積をそれぞれ $O(\log n)$ で行うデータ構造  
演算 $f$ は結合法則を満たし、単位元 $ti$ を持つ必要がある（モノイド）  

## 呼び出し

- `SegmentTree<T> seg(function<T(T,T)> f,T ti,int n=1)`
  - 単位元 $ti$ で初期化された長さ $n$ の数列 $a_0,\dots,a_{n-1}$ を生成
  - $O(n)$
- `SegmentTree<T> seg(function<T(T,T)> f,T ti,const vector<T>&v)`
  - 数列 $v$ をコピーした数列 $a$ を生成
  - $v$ の長さを $n$ として $O(n)$
- `void init(int n)`
  - 単位元 $ti$ で初期化された長さ $n$ の数列 $a_0,\dots,a_{n-1}$ を生成
  - $O(n)$
- `void build(const vector<T>&v)`
  - 数列 $v$ をコピーした数列 $a$ を生成
  - $v$ の長さを $n$ として $O(n)$
- `T seg[k]`
  - $a_k$ を返す
- `void set_val(int k,T x)`
  - $a_k$ に $x$ を代入
  - $O(\log n)$
- `T query(int l,int r)`
  - 区間 $[l,r)$ の積を返す
  - つまり、$f(a_l,f(a_{l+1},\dots,f(a_{r-2},a_{r-1})))$ を返す
  - $l>r$ の時は $ti$ を返す
  - $O(\log n)$

## その他
計算量は演算が行われる回数である（$f$ が重い時に注意）  
内部では $dat_{n+k}$ が $a_k$ に対応  
根は $dat_0$ であり、$dat_k$ の子は $dat_{2k},dat_{2k+1}$ である