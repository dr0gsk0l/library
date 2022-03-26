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
  bundledCode: "#line 1 \"grid.cpp\"\nstruct Grid{\n  vector<string> field;\n  int\
    \ h,w;\n  int dy[8]={-1,0,1,0,-1,-1,1,1};\n  int dx[8]={0,1,0,-1,-1,1,1,-1};\n\
    \  Grid():{}\n  Grid(int h,int w):h(h),w(w),field(h){}\n  void scan(){\n    for(auto\
    \ &s:field)cin>>s;\n  }\n  bool in(int y,int x){\n    return 0<=y&&y<h&&0<=x&&x<w;\n\
    \  }\n};\n"
  code: "struct Grid{\n  vector<string> field;\n  int h,w;\n  int dy[8]={-1,0,1,0,-1,-1,1,1};\n\
    \  int dx[8]={0,1,0,-1,-1,1,1,-1};\n  Grid():{}\n  Grid(int h,int w):h(h),w(w),field(h){}\n\
    \  void scan(){\n    for(auto &s:field)cin>>s;\n  }\n  bool in(int y,int x){\n\
    \    return 0<=y&&y<h&&0<=x&&x<w;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: grid.cpp
  requiredBy: []
  timestamp: '2022-03-26 14:25:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: grid.cpp
layout: document
redirect_from:
- /library/grid.cpp
- /library/grid.cpp.html
title: grid.cpp
---
