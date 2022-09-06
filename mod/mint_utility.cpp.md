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
  bundledCode: "#line 1 \"mod/mint_utility.cpp\"\ntemplate<typename MINT>\nclass mint_utility\
    \ {\n  vector<MINT> fact_={MINT::raw(1)};\n  vector<MINT> inv_fact_{MINT::raw(1)};\n\
    \  int S=1;//\u4ECA\u306E\u30B5\u30A4\u30BA\n \n  void extend(const int n){\n\
    \    if(n<S)return;\n    const int preS=S;\n    do{S<<=1}while(S<=n);\n\n    fact_.resize(S);\n\
    \    for(int i=preS;i<S;i++)fact_[i]=fact_[i-1]*MINT::raw(i);\n\n    inv_fact_.resize(S);\n\
    \    inv_fact_.back()=fact_.back().inv();\n    for(int i=S-1;i>preS;i--)inv_fact_[i-1]=inv_fact_[i]*MINT::raw(i);\n\
    \  }\n \npublic:\n  mint_utility() = delete;\n \n  static MINT fact(const int\
    \ n){\n    assert(n>=0);\n    extend(n);\n    return fact_[n];\n  }\n \n  static\
    \ MINT inv_fact(const int n){\n    assert(n>=0);\n    extend(n);\n    return inv_fact_[n];\n\
    \  }\n \n  static MINT nCk(const int n,const int k){\n    if(k<0||n<k)return T::raw(0);\n\
    \    extend(n);\n    return fact_[n] * inv_fact_[k] * inv_fact_[n - k];\n  }\n\
    };\n"
  code: "template<typename MINT>\nclass mint_utility {\n  vector<MINT> fact_={MINT::raw(1)};\n\
    \  vector<MINT> inv_fact_{MINT::raw(1)};\n  int S=1;//\u4ECA\u306E\u30B5\u30A4\
    \u30BA\n \n  void extend(const int n){\n    if(n<S)return;\n    const int preS=S;\n\
    \    do{S<<=1}while(S<=n);\n\n    fact_.resize(S);\n    for(int i=preS;i<S;i++)fact_[i]=fact_[i-1]*MINT::raw(i);\n\
    \n    inv_fact_.resize(S);\n    inv_fact_.back()=fact_.back().inv();\n    for(int\
    \ i=S-1;i>preS;i--)inv_fact_[i-1]=inv_fact_[i]*MINT::raw(i);\n  }\n \npublic:\n\
    \  mint_utility() = delete;\n \n  static MINT fact(const int n){\n    assert(n>=0);\n\
    \    extend(n);\n    return fact_[n];\n  }\n \n  static MINT inv_fact(const int\
    \ n){\n    assert(n>=0);\n    extend(n);\n    return inv_fact_[n];\n  }\n \n \
    \ static MINT nCk(const int n,const int k){\n    if(k<0||n<k)return T::raw(0);\n\
    \    extend(n);\n    return fact_[n] * inv_fact_[k] * inv_fact_[n - k];\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: mod/mint_utility.cpp
  requiredBy: []
  timestamp: '2022-09-06 17:15:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/mint_utility.cpp
layout: document
redirect_from:
- /library/mod/mint_utility.cpp
- /library/mod/mint_utility.cpp.html
title: mod/mint_utility.cpp
---
