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
  bundledCode: "#line 1 \"data-structure/fenwicktree.cpp\"\ntemplate<typename T>\n\
    struct BIT{\n  int n;\n  vector<T> bit;\n  //1-indexed\n  BIT():n(-1){}\n  BIT(int\
    \ n_,T d):n(n_),bit(n_+1,d){}\n  \n  //bit[i]\u306F\u9577\u3055\u306Fi\u306E\u6700\
    \u5F8C\u306Ebit\u5206\u3067\u3001\u30B9\u30BF\u30FC\u30C8\u306F\u305D\u308C\u4EE5\
    \u5916\u306Ebit \u5408\u8A08\u3067\u3061\u3087\u3046\u3069i\u307E\u3067\u306E\u60C5\
    \u5831\n  //\u6700\u5F8C\u306Ebit\u304C\u8868\u3059\u7269\u3092k,\u305D\u308C\u4EE5\
    \u5916\u306Ebit\u304C\u8868\u3059\u7269\u3092l\u3068\u3059\u308B\u3068bit[i]=(l,l+k]\u3067\
    l+k=i\n\n  T sum(int i){\n    T s=bit[0];\n    for(int x=i;x>0;x-=(x&-x))//x&-x:(x\u306E\
    \u6700\u5F8C\u306Ebit) \u4E0A\u306E\u8A00\u8449\u3067x\u3092l+k\u304B\u3089l\u306B\
    \u3057\u3066\u308B\n      s+=bit[x];\n    return s;\n  }\n  \n  void add(int i,T\
    \ a){\n    if(i==0) return;\n    for(int x=i;x<=n;x+=(x&-x))//k,l+k\u306F\u81EA\
    \u660E\u306B\u5897\u3048\u308B l\u306F\u5897\u3048\u306A\u3044(l\u3068k\u306E\u9593\
    \u306B0\u304C\u51FA\u6765\u306A\u3044)\n      bit[x]+=a;\n  }\n\n  int lower_bound(int\
    \ w){//w\u4EE5\u4E0A\u3068\u306A\u308B\u6700\u5C0F\u306E\u5834\u6240\u3092\u8FD4\
    \u3059 \u5358\u8ABF\u6027\u3092\u4EEE\u5B9A\u3057\u3066\u308B(bit[i]>=0)\n   \
    \ if(w<=0) return 0;\n    int x=0,r=1;\n    while(r<n) r<<=1;\n    for(int k=r;k>0;k>>=1){//x\u306B\
    2\u306E\u3079\u304D\u4E57\u3092\u5927\u304D\u3044\u65B9\u304B\u3089\u8DB3\u305B\
    \u308B\u306A\u3089\u8DB3\u3059\u3060\u3051\n      if(x+k<=n&&bit[x+k]<w){\n  \
    \      w-=bit[x+k];\n        x+=k;\n      }\n    }\n    return x+1;//x\u306Fw\u672A\
    \u6E80\u3092\u6E80\u305F\u3059\u6700\u5927\u306E\u5834\u6240\u306A\u306E\u3067\
    1\u5927\u304D\u3044\u5024\u3092\u8FD4\u3059\n  }\n\n  T sum0(int i){\n    return\
    \ sum(i+1);\n  }\n  \n  void add0(int i,T a){\n    add(i+1,a);\n  }\n\n  T query(int\
    \ l,int r){\n    return sum(r-1)-sum(l-1);\n  }\n\n  T query0(int l,int r){\n\
    \    return sum(r)-sum(l);\n  }\n};\n//END CUT HERE\n"
  code: "template<typename T>\nstruct BIT{\n  int n;\n  vector<T> bit;\n  //1-indexed\n\
    \  BIT():n(-1){}\n  BIT(int n_,T d):n(n_),bit(n_+1,d){}\n  \n  //bit[i]\u306F\u9577\
    \u3055\u306Fi\u306E\u6700\u5F8C\u306Ebit\u5206\u3067\u3001\u30B9\u30BF\u30FC\u30C8\
    \u306F\u305D\u308C\u4EE5\u5916\u306Ebit \u5408\u8A08\u3067\u3061\u3087\u3046\u3069\
    i\u307E\u3067\u306E\u60C5\u5831\n  //\u6700\u5F8C\u306Ebit\u304C\u8868\u3059\u7269\
    \u3092k,\u305D\u308C\u4EE5\u5916\u306Ebit\u304C\u8868\u3059\u7269\u3092l\u3068\
    \u3059\u308B\u3068bit[i]=(l,l+k]\u3067l+k=i\n\n  T sum(int i){\n    T s=bit[0];\n\
    \    for(int x=i;x>0;x-=(x&-x))//x&-x:(x\u306E\u6700\u5F8C\u306Ebit) \u4E0A\u306E\
    \u8A00\u8449\u3067x\u3092l+k\u304B\u3089l\u306B\u3057\u3066\u308B\n      s+=bit[x];\n\
    \    return s;\n  }\n  \n  void add(int i,T a){\n    if(i==0) return;\n    for(int\
    \ x=i;x<=n;x+=(x&-x))//k,l+k\u306F\u81EA\u660E\u306B\u5897\u3048\u308B l\u306F\
    \u5897\u3048\u306A\u3044(l\u3068k\u306E\u9593\u306B0\u304C\u51FA\u6765\u306A\u3044\
    )\n      bit[x]+=a;\n  }\n\n  int lower_bound(int w){//w\u4EE5\u4E0A\u3068\u306A\
    \u308B\u6700\u5C0F\u306E\u5834\u6240\u3092\u8FD4\u3059 \u5358\u8ABF\u6027\u3092\
    \u4EEE\u5B9A\u3057\u3066\u308B(bit[i]>=0)\n    if(w<=0) return 0;\n    int x=0,r=1;\n\
    \    while(r<n) r<<=1;\n    for(int k=r;k>0;k>>=1){//x\u306B2\u306E\u3079\u304D\
    \u4E57\u3092\u5927\u304D\u3044\u65B9\u304B\u3089\u8DB3\u305B\u308B\u306A\u3089\
    \u8DB3\u3059\u3060\u3051\n      if(x+k<=n&&bit[x+k]<w){\n        w-=bit[x+k];\n\
    \        x+=k;\n      }\n    }\n    return x+1;//x\u306Fw\u672A\u6E80\u3092\u6E80\
    \u305F\u3059\u6700\u5927\u306E\u5834\u6240\u306A\u306E\u30671\u5927\u304D\u3044\
    \u5024\u3092\u8FD4\u3059\n  }\n\n  T sum0(int i){\n    return sum(i+1);\n  }\n\
    \  \n  void add0(int i,T a){\n    add(i+1,a);\n  }\n\n  T query(int l,int r){\n\
    \    return sum(r-1)-sum(l-1);\n  }\n\n  T query0(int l,int r){\n    return sum(r)-sum(l);\n\
    \  }\n};\n//END CUT HERE"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/fenwicktree.cpp
  requiredBy: []
  timestamp: '2022-04-12 17:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/fenwicktree.cpp
layout: document
redirect_from:
- /library/data-structure/fenwicktree.cpp
- /library/data-structure/fenwicktree.cpp.html
title: data-structure/fenwicktree.cpp
---
