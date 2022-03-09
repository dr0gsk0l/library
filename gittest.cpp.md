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
  bundledCode: "#line 1 \"gittest.cpp\"\n#pragma GCC optimize(\"Ofast\")\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define REP(i,n) for(int i=0;i<(n);i++)\n\
    #define ALL(v) v.begin(),v.end()\n#define debug(a) cerr<<#a<<\":\"<<a<<endl;\n\
    #define debug2(a,b) cerr<<\"(\"<<#a<<\",\"<<#b<<\"):(\"<<a<<\",\"<<b<<\")\"<<endl;\n\
    #define debug3(a,b,c) cerr<<\"(\"<<#a<<\",\"<<#b<<\",\"<<#c<<\"):(\"<<a<<\",\"\
    <<b<<\",\"<<c<<\")\"<<endl;\n#define debug4(a,b,c,d) cerr<<\"(\"<<#a<<\",\"<<#b<<\"\
    ,\"<<#c<<\",\"<<d<<\"):(\"<<a<<\",\"<<b<<\",\"<<c<<\",\"<<d<<\")\"<<endl;\n\n\
    template<typename T>\nistream& operator>>(istream&is,vector<T>&v){\n  for(T&p:v)is>>p;\n\
    \  return is;\n}\ntemplate<typename T>\nostream& operator<<(ostream&os,const vector<T>&v){\n\
    \  if(&os==&cerr)os<<\"[\";\n  for(int i=0;i<v.size();i++){\n    os<<v[i];\n \
    \   if(i+1<v.size())os<<(&os==&cerr?\",\":\" \");\n  }\n  if(&os==&cerr)os<<\"\
    ]\";\n  return os;\n}\n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n"
  code: "#pragma GCC optimize(\"Ofast\")\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define REP(i,n) for(int i=0;i<(n);i++)\n#define ALL(v) v.begin(),v.end()\n\
    #define debug(a) cerr<<#a<<\":\"<<a<<endl;\n#define debug2(a,b) cerr<<\"(\"<<#a<<\"\
    ,\"<<#b<<\"):(\"<<a<<\",\"<<b<<\")\"<<endl;\n#define debug3(a,b,c) cerr<<\"(\"\
    <<#a<<\",\"<<#b<<\",\"<<#c<<\"):(\"<<a<<\",\"<<b<<\",\"<<c<<\")\"<<endl;\n#define\
    \ debug4(a,b,c,d) cerr<<\"(\"<<#a<<\",\"<<#b<<\",\"<<#c<<\",\"<<d<<\"):(\"<<a<<\"\
    ,\"<<b<<\",\"<<c<<\",\"<<d<<\")\"<<endl;\n\ntemplate<typename T>\nistream& operator>>(istream&is,vector<T>&v){\n\
    \  for(T&p:v)is>>p;\n  return is;\n}\ntemplate<typename T>\nostream& operator<<(ostream&os,const\
    \ vector<T>&v){\n  if(&os==&cerr)os<<\"[\";\n  for(int i=0;i<v.size();i++){\n\
    \    os<<v[i];\n    if(i+1<v.size())os<<(&os==&cerr?\",\":\" \");\n  }\n  if(&os==&cerr)os<<\"\
    ]\";\n  return os;\n}\n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);"
  dependsOn: []
  isVerificationFile: false
  path: gittest.cpp
  requiredBy: []
  timestamp: '2022-03-09 13:08:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: gittest.cpp
layout: document
redirect_from:
- /library/gittest.cpp
- /library/gittest.cpp.html
title: gittest.cpp
---
