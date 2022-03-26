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
  bundledCode: "#line 1 \"SegmentMap.cpp\"\n//using ll=long long;\nstruct SegmentMap{\n\
    \  map<ll,ll> mp;//mp[l]=r:[l,r)\n  //[l,m) [m,r) \u306F[l,r)\u306B\u306A\u308B\
    \u3000\u9023\u7D9A\u3059\u308B\u9ED2\u306E\u533A\u9593\u3092\u6301\u3064\u307F\
    \u305F\u3044\u306A\u30A4\u30E1\u30FC\u30B8\n  const ll LINF=4e18;\n\n  SegmentMap(){\n\
    \    mp[-LINF]=-LINF;\n    mp[LINF]=LINF;\n  }\n\n  inline auto get_it(ll a){//a\u3092\
    \u542B\u3080[l,r)\u306Eiterator\n    auto it=--mp.upper_bound(a);\n    if(a<(it->second))return\
    \ it;\n    return mp.end();\n  }\n\n  tuple<ll,ll> get(ll a){\n    auto it=get_it(a);\n\
    \    if(it==mp.end())return {LINF,-LINF};\n    return {it->first,it->second};\n\
    \  }\n\n  bool same(ll a,ll b){\n    auto it=get_it(a);\n    return it!=mp.end()\
    \ && (it->first)<=b && b<(it->second);\n  }\n\n  tuple<ll,ll> insert(ll l,ll r){//[l,r)\u3092\
    \u633F\u5165\n    auto it=--mp.upper_bound(l);\n    if((it->second)>=l)l=it->first;\n\
    \    else ++it;\n    while((it->first)<=r){\n      r=max(r,it->second);\n    \
    \  it=mp.erase(it);\n    }\n    mp[l]=r;\n    return {l,r};\n  }\n\n  void remove(ll\
    \ l,ll r){//[l,r)\u3068\u5171\u901A\u90E8\u5206\u3092\u6301\u3064\u533A\u9593\u5168\
    \u524A\u9664\n    auto it=--mp.upper_bound(l);\n    if((it->second)<=l)++it;\n\
    \    while((it->first)<r)it=mp.erase(it);\n  }\n};\n"
  code: "//using ll=long long;\nstruct SegmentMap{\n  map<ll,ll> mp;//mp[l]=r:[l,r)\n\
    \  //[l,m) [m,r) \u306F[l,r)\u306B\u306A\u308B\u3000\u9023\u7D9A\u3059\u308B\u9ED2\
    \u306E\u533A\u9593\u3092\u6301\u3064\u307F\u305F\u3044\u306A\u30A4\u30E1\u30FC\
    \u30B8\n  const ll LINF=4e18;\n\n  SegmentMap(){\n    mp[-LINF]=-LINF;\n    mp[LINF]=LINF;\n\
    \  }\n\n  inline auto get_it(ll a){//a\u3092\u542B\u3080[l,r)\u306Eiterator\n\
    \    auto it=--mp.upper_bound(a);\n    if(a<(it->second))return it;\n    return\
    \ mp.end();\n  }\n\n  tuple<ll,ll> get(ll a){\n    auto it=get_it(a);\n    if(it==mp.end())return\
    \ {LINF,-LINF};\n    return {it->first,it->second};\n  }\n\n  bool same(ll a,ll\
    \ b){\n    auto it=get_it(a);\n    return it!=mp.end() && (it->first)<=b && b<(it->second);\n\
    \  }\n\n  tuple<ll,ll> insert(ll l,ll r){//[l,r)\u3092\u633F\u5165\n    auto it=--mp.upper_bound(l);\n\
    \    if((it->second)>=l)l=it->first;\n    else ++it;\n    while((it->first)<=r){\n\
    \      r=max(r,it->second);\n      it=mp.erase(it);\n    }\n    mp[l]=r;\n   \
    \ return {l,r};\n  }\n\n  void remove(ll l,ll r){//[l,r)\u3068\u5171\u901A\u90E8\
    \u5206\u3092\u6301\u3064\u533A\u9593\u5168\u524A\u9664\n    auto it=--mp.upper_bound(l);\n\
    \    if((it->second)<=l)++it;\n    while((it->first)<r)it=mp.erase(it);\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: SegmentMap.cpp
  requiredBy: []
  timestamp: '2022-03-26 14:25:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegmentMap.cpp
layout: document
redirect_from:
- /library/SegmentMap.cpp
- /library/SegmentMap.cpp.html
title: SegmentMap.cpp
---
