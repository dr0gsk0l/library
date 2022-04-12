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
  bundledCode: "#line 1 \"data-structure/rangetree.cpp\"\ntemplate<typename T>\nstruct\
    \ RangeTree{\n  typedef vector<T> V;\n  int n;\n   \n  vector<V> dat;\n\n  static\
    \ constexpr auto V_merge=[](const V&a,const V&b){\n    V res;\n    int aid=0,bid=0;\n\
    \    while(aid<a.size() or bid<b.size())\n      if(aid==a.size() or (bid<b.size()\
    \ and a[aid]>b[bid]))\n        res.push_back(b[bid++]);\n      else\n        res.push_back(a[aid++]);\n\
    \    return res;\n  };\n  \n  RangeTree(){}; \n  RangeTree(int n_){\n    n=1;\n\
    \    while(n<n_) n<<=1;\n    dat.assign(n<<1,V());\n  }\n  RangeTree(const V &v){\n\
    \    int n_=v.size();\n    n=1;\n    while(n<n_)n<<=1;\n    dat.assign(n<<1,V());\n\
    \    for(int i=0;i<n_;i++)dat[n+i]=V(1,v[i]);\n    for(int i=n-1;i;i--)dat[i]=V_merge(dat[2*i],dat[2*i+1]);\n\
    \  }\n  \n  void set_val(int idx,T x){\n    dat[idx+=n]=V(1,x);  \n    while(idx>>=1)dat[idx]=V_merge(dat[2*idx],dat[2*idx+1]);\n\
    \  }\n  \n  /*\n  [a,b)\u306E\u7BC4\u56F2\u3067\u306Echeck\u7D50\u679C\u306E\u7DCF\
    \u548C\u3092\u8FD4\u3059 Rmerge\u306F\u7D50\u5408\u6CD5\u5247\u6E80\u305F\u3059\
    \n  \u4F8B\u3048\u3070 Q(v)=v\u5185\u306Ek\u4EE5\u4E0A\u306E\u500B\u6570 , Rmerge(a,b)=a+b\
    \ \u3068\u304B\n  */\n\n  template<typename R>\n  R query(int a,int b,function<R(const\
    \ &V)> Q,function<R(R,R)> Rmerge){\n    R vl,vr;\n    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){\n\
    \      if(l&1)vl=Rmerge(vl,Q(dat[l++]));\n      if(r&1)vr=Rmerge(dat[--r],vr);\n\
    \    }\n    return Rmerge(vl,vr);\n  }\n};\n"
  code: "template<typename T>\nstruct RangeTree{\n  typedef vector<T> V;\n  int n;\n\
    \   \n  vector<V> dat;\n\n  static constexpr auto V_merge=[](const V&a,const V&b){\n\
    \    V res;\n    int aid=0,bid=0;\n    while(aid<a.size() or bid<b.size())\n \
    \     if(aid==a.size() or (bid<b.size() and a[aid]>b[bid]))\n        res.push_back(b[bid++]);\n\
    \      else\n        res.push_back(a[aid++]);\n    return res;\n  };\n  \n  RangeTree(){};\
    \ \n  RangeTree(int n_){\n    n=1;\n    while(n<n_) n<<=1;\n    dat.assign(n<<1,V());\n\
    \  }\n  RangeTree(const V &v){\n    int n_=v.size();\n    n=1;\n    while(n<n_)n<<=1;\n\
    \    dat.assign(n<<1,V());\n    for(int i=0;i<n_;i++)dat[n+i]=V(1,v[i]);\n   \
    \ for(int i=n-1;i;i--)dat[i]=V_merge(dat[2*i],dat[2*i+1]);\n  }\n  \n  void set_val(int\
    \ idx,T x){\n    dat[idx+=n]=V(1,x);  \n    while(idx>>=1)dat[idx]=V_merge(dat[2*idx],dat[2*idx+1]);\n\
    \  }\n  \n  /*\n  [a,b)\u306E\u7BC4\u56F2\u3067\u306Echeck\u7D50\u679C\u306E\u7DCF\
    \u548C\u3092\u8FD4\u3059 Rmerge\u306F\u7D50\u5408\u6CD5\u5247\u6E80\u305F\u3059\
    \n  \u4F8B\u3048\u3070 Q(v)=v\u5185\u306Ek\u4EE5\u4E0A\u306E\u500B\u6570 , Rmerge(a,b)=a+b\
    \ \u3068\u304B\n  */\n\n  template<typename R>\n  R query(int a,int b,function<R(const\
    \ &V)> Q,function<R(R,R)> Rmerge){\n    R vl,vr;\n    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){\n\
    \      if(l&1)vl=Rmerge(vl,Q(dat[l++]));\n      if(r&1)vr=Rmerge(dat[--r],vr);\n\
    \    }\n    return Rmerge(vl,vr);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/rangetree.cpp
  requiredBy: []
  timestamp: '2022-04-12 17:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/rangetree.cpp
layout: document
redirect_from:
- /library/data-structure/rangetree.cpp
- /library/data-structure/rangetree.cpp.html
title: data-structure/rangetree.cpp
---
