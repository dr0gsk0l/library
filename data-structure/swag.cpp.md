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
  bundledCode: "#line 1 \"data-structure/swag.cpp\"\ntemplate <class Monoid>\nstruct\
    \ SWAG{\n  stack<Monoid> back_stack;\n  Monoid back_value;\n  stack<pair<Monoid,Monoid>>\
    \ front_stack;\n\n  inline Monoid front_value(){\n    if(front_stack.empty())return\
    \ Monoid();\n    return get<1>(front_stack.top());\n  }\n\n  void push_back(Monoid\
    \ a){\n    back_stack.push(a);\n    back_value=back_value+a;\n  }\n  void push_front(Monoid\
    \ a){\n    front_stack.emplace(a,a+front_value());\n  }\n  void pop_front(){\n\
    \    if(front_stack.empty()){\n      if(back_stack.empty())return;\n      while(back_stack.size()){\n\
    \        push_front(back_stack.top());\n        back_stack.pop();\n      }\n \
    \     back_value.v=Monoid();\n    }\n    front_stack.pop();\n  }\n  \n  Monoid\
    \ fold(){\n    return front_value()+back_value;\n  }\n};\n/*\nSWAG<Monoid> \u3067\
    \u4F5C\u6210\npush_back(a),push_front(a) \u304CO(1)\npop_front \u306F\u5E73\u5747\
    O(1)\n\nfold() \u3067\u73FE\u5728\u5165\u3063\u3066\u308B\u5024\u306E\u7A4D\u304C\
    \u51FA\u308B\n*/\n"
  code: "template <class Monoid>\nstruct SWAG{\n  stack<Monoid> back_stack;\n  Monoid\
    \ back_value;\n  stack<pair<Monoid,Monoid>> front_stack;\n\n  inline Monoid front_value(){\n\
    \    if(front_stack.empty())return Monoid();\n    return get<1>(front_stack.top());\n\
    \  }\n\n  void push_back(Monoid a){\n    back_stack.push(a);\n    back_value=back_value+a;\n\
    \  }\n  void push_front(Monoid a){\n    front_stack.emplace(a,a+front_value());\n\
    \  }\n  void pop_front(){\n    if(front_stack.empty()){\n      if(back_stack.empty())return;\n\
    \      while(back_stack.size()){\n        push_front(back_stack.top());\n    \
    \    back_stack.pop();\n      }\n      back_value.v=Monoid();\n    }\n    front_stack.pop();\n\
    \  }\n  \n  Monoid fold(){\n    return front_value()+back_value;\n  }\n};\n/*\n\
    SWAG<Monoid> \u3067\u4F5C\u6210\npush_back(a),push_front(a) \u304CO(1)\npop_front\
    \ \u306F\u5E73\u5747O(1)\n\nfold() \u3067\u73FE\u5728\u5165\u3063\u3066\u308B\u5024\
    \u306E\u7A4D\u304C\u51FA\u308B\n*/"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/swag.cpp
  requiredBy: []
  timestamp: '2022-03-26 14:25:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/swag.cpp
layout: document
redirect_from:
- /library/data-structure/swag.cpp
- /library/data-structure/swag.cpp.html
title: data-structure/swag.cpp
---
