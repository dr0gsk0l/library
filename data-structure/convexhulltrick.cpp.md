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
  bundledCode: "#line 1 \"data-structure/convexhulltrick.cpp\"\nenum Objective{\n\
    \  MINIMIZE = +1,\n  MAXIMIZE = -1,\n};\n\ntemplate<typename T>\nstruct Line{\n\
    \  T a,b;\n  T operator()(const T x)const{return a*x+b;}\n};\n\ntemplate<typename\
    \ T,Objective objective>\nstruct ConvexHullTrick:deque<Line<T>>{\n  inline int\
    \ sgn(T x){return x==0?0:(x<0?-1:1);}//\u7B26\u53F7\n\n  using D=long double;\n\
    \  inline bool check(const Line<T>&l1,const Line<T>&l2,const Line<T>&l3){\n  \
    \  if(l1.b==l2.b or l2.b==l3.b)\n      return sgn(l2.a-l1.a)*sgn(l3.b-l2.b) >=\
    \ sgn(l3.a-l2.a)*sgn(l2.b-l1.b);\n    // return (b.a-a.a)*(c.b-b.b) >= (b.b-a.b)*(c.a-b.a);\n\
    \    return\n      D(b.a-a.a)*sgn(c.b-b.b)/D(abs(b.b-a.b)) >=\n      D(c.a-b.a)*sgn(b.b-a.b)/D(abs(c.b-b.b));\n\
    \  }\n\n  using super = deque<Line<T>>;\n  using super::empty,super::size,super::front,super::back;\n\
    \  using super::emplace_front,super::emplace_back;\n  using super::pop_front,super::pop_back;\n\
    \  const Line<T> at(int i) const{return (*this)[i];}\n\n  void add(T a,T b){\n\
    \    Line<T> l({a*objective,b*objective});\n    if(empty()){\n      emplace_front(l);\n\
    \      return;\n    }\n    if(front().a<=l.a){\n      if(front().a==l.a){\n  \
    \      if(front().b<=l.b) return;\n        pop_front();\n      }\n      while(size()>=2\
    \ and check(l,at(0),at(1))) pop_front();\n      emplace_front(l);\n    }else{\n\
    \      assert(l.a<=back().a);\n      if(back().a==l.a){\n        if(back().b<=l.b)\
    \ return;\n        pop_back();\n      }\n      while(size()>=2 and check(at(size()-2),at(size()-1),l))\
    \ pop_back();\n      emplace_back(l);\n    }\n  }\n\n  T query(T x){\n    assert(!empty());\n\
    \    int l=-1,r=size()-1;\n    while(l+1<r){\n      int m=(l+r)>>1;\n      if(at(m)(x)>=at(m+1)(x))\
    \ l=m;\n      else r=m;\n    }\n    return at(r)(x)*objective;\n  }\n\n  T queryMonotoneInc(T\
    \ x){\n    assert(!empty());\n    while(size()>=2 and at(0)(x)>=at(1)(x)) pop_front();\n\
    \    return front()(x)*objective;\n  }\n\n  T queryMonotoneDec(T x){\n    assert(!empty());\n\
    \    while(size()>=2 and at(size()-1)(x)>=at(size()-2)(x)) pop_back();\n    return\
    \ back()(x)*objective;\n  }\n\n  vector<pair<T, T>> getVertices(){\n    vector<pair<T,\
    \ T>> res;\n    for(int i=0;i+1<(int)size();i++){\n      auto l0=at(i+0),l1=at(i+1);\n\
    \      assert(l0.a!=l1.a);\n      T x=(l1.b-l0.b)/(l0.a-l1.a);\n      res.emplace_back(x,at(i)(x)*objective);\n\
    \    }\n    return res;\n  }\n};\ntemplate<typename T>\nusing MinConvexHullTrick\
    \ = ConvexHullTrick<T, Objective::MINIMIZE>;\ntemplate<typename T>\nusing MaxConvexHullTrick\
    \ = ConvexHullTrick<T, Objective::MAXIMIZE>;\n\ntemplate<typename T>\nvoid chmin(optional<T>\
    \ &a,const T& b){if(!a or *a>b) a=b;}\n\n// O(n \\log n) (n = as.size())\ntemplate<typename\
    \ T, Objective objective>\noptional<T> solve_lp(T p0,T p1,vector<T> as,vector<T>\
    \ bs,vector<T> cs){\n  auto calc=[&](T y0,T y1){return y0*p0+y1*p1;};\n  using\
    \ P = pair<T, T>;\n  vector<P> vp;\n  for(int i=0;i<(int)as.size();i++)\n    vp.emplace_back(-bs[i]/as[i],cs[i]/as[i]);\n\
    \  sort(vp.begin(),vp.end());\n\n  ConvexHullTrick<T, objective> cht;\n  for(auto[k,m]:vp)\
    \ cht.add(k,m);\n\n  optional<T> res;\n  for(auto[y1,y0]:cht.getVertices())\n\
    \    if(y0>=0 and y1>=0) chmin(res,calc(y0,y1));\n  return res;\n}\n\n// minimize_{y0,\
    \ y1 >=0} p0 y0 + p1 y1\n// s.t. as[i] * y0 + bs[i] * y1 >= cs[i]\n// assume as[i],\
    \ bs[i] >0\ntemplate<typename T>\nT solve_lp_min(T p0,T p1,vector<T> as,vector<T>\
    \ bs,vector<T> cs){\n  T y0=0,y1=0;\n  for(int i=0;i<(int)as.size();i++){\n  \
    \  y0=max(y0,cs[i]/as[i]);\n    y1=max(y1,cs[i]/bs[i]);\n  }\n  auto res=solve_lp<T,\
    \ Objective::MAXIMIZE>(+p0,+p1,as,bs,cs);\n  chmin(res,p0*y0);\n  chmin(res,p1*y1);\n\
    \  return *res;\n}\n\n// maximize_{y0, y1 >=0} p0 y0 + p1 y1\n// s.t. as[i] *\
    \ y0 + bs[i] * y1 <= cs[i]\n// assume as[i], bs[i] >0, cs[i] >=0\ntemplate<typename\
    \ T>\nT solve_lp_max(T p0,T p1,vector<T> as,vector<T> bs,vector<T> cs){\n  T y0=cs[0]/as[0],y1=cs[0]/bs[0];\n\
    \  for(int i=0;i<(int)as.size();i++){\n    y0=min(y0,cs[i]/as[i]);\n    y1=min(y1,cs[i]/bs[i]);\n\
    \    as[i]=-as[i];bs[i]=-bs[i];cs[i]=-cs[i];\n  }\n  auto res=solve_lp<T, Objective::MINIMIZE>(-p0,-p1,as,bs,cs);\n\
    \  chmin(res,-p0*y0);\n  chmin(res,-p1*y1);\n  return -*res;\n}\n"
  code: "enum Objective{\n  MINIMIZE = +1,\n  MAXIMIZE = -1,\n};\n\ntemplate<typename\
    \ T>\nstruct Line{\n  T a,b;\n  T operator()(const T x)const{return a*x+b;}\n\
    };\n\ntemplate<typename T,Objective objective>\nstruct ConvexHullTrick:deque<Line<T>>{\n\
    \  inline int sgn(T x){return x==0?0:(x<0?-1:1);}//\u7B26\u53F7\n\n  using D=long\
    \ double;\n  inline bool check(const Line<T>&l1,const Line<T>&l2,const Line<T>&l3){\n\
    \    if(l1.b==l2.b or l2.b==l3.b)\n      return sgn(l2.a-l1.a)*sgn(l3.b-l2.b)\
    \ >= sgn(l3.a-l2.a)*sgn(l2.b-l1.b);\n    // return (b.a-a.a)*(c.b-b.b) >= (b.b-a.b)*(c.a-b.a);\n\
    \    return\n      D(b.a-a.a)*sgn(c.b-b.b)/D(abs(b.b-a.b)) >=\n      D(c.a-b.a)*sgn(b.b-a.b)/D(abs(c.b-b.b));\n\
    \  }\n\n  using super = deque<Line<T>>;\n  using super::empty,super::size,super::front,super::back;\n\
    \  using super::emplace_front,super::emplace_back;\n  using super::pop_front,super::pop_back;\n\
    \  const Line<T> at(int i) const{return (*this)[i];}\n\n  void add(T a,T b){\n\
    \    Line<T> l({a*objective,b*objective});\n    if(empty()){\n      emplace_front(l);\n\
    \      return;\n    }\n    if(front().a<=l.a){\n      if(front().a==l.a){\n  \
    \      if(front().b<=l.b) return;\n        pop_front();\n      }\n      while(size()>=2\
    \ and check(l,at(0),at(1))) pop_front();\n      emplace_front(l);\n    }else{\n\
    \      assert(l.a<=back().a);\n      if(back().a==l.a){\n        if(back().b<=l.b)\
    \ return;\n        pop_back();\n      }\n      while(size()>=2 and check(at(size()-2),at(size()-1),l))\
    \ pop_back();\n      emplace_back(l);\n    }\n  }\n\n  T query(T x){\n    assert(!empty());\n\
    \    int l=-1,r=size()-1;\n    while(l+1<r){\n      int m=(l+r)>>1;\n      if(at(m)(x)>=at(m+1)(x))\
    \ l=m;\n      else r=m;\n    }\n    return at(r)(x)*objective;\n  }\n\n  T queryMonotoneInc(T\
    \ x){\n    assert(!empty());\n    while(size()>=2 and at(0)(x)>=at(1)(x)) pop_front();\n\
    \    return front()(x)*objective;\n  }\n\n  T queryMonotoneDec(T x){\n    assert(!empty());\n\
    \    while(size()>=2 and at(size()-1)(x)>=at(size()-2)(x)) pop_back();\n    return\
    \ back()(x)*objective;\n  }\n\n  vector<pair<T, T>> getVertices(){\n    vector<pair<T,\
    \ T>> res;\n    for(int i=0;i+1<(int)size();i++){\n      auto l0=at(i+0),l1=at(i+1);\n\
    \      assert(l0.a!=l1.a);\n      T x=(l1.b-l0.b)/(l0.a-l1.a);\n      res.emplace_back(x,at(i)(x)*objective);\n\
    \    }\n    return res;\n  }\n};\ntemplate<typename T>\nusing MinConvexHullTrick\
    \ = ConvexHullTrick<T, Objective::MINIMIZE>;\ntemplate<typename T>\nusing MaxConvexHullTrick\
    \ = ConvexHullTrick<T, Objective::MAXIMIZE>;\n\ntemplate<typename T>\nvoid chmin(optional<T>\
    \ &a,const T& b){if(!a or *a>b) a=b;}\n\n// O(n \\log n) (n = as.size())\ntemplate<typename\
    \ T, Objective objective>\noptional<T> solve_lp(T p0,T p1,vector<T> as,vector<T>\
    \ bs,vector<T> cs){\n  auto calc=[&](T y0,T y1){return y0*p0+y1*p1;};\n  using\
    \ P = pair<T, T>;\n  vector<P> vp;\n  for(int i=0;i<(int)as.size();i++)\n    vp.emplace_back(-bs[i]/as[i],cs[i]/as[i]);\n\
    \  sort(vp.begin(),vp.end());\n\n  ConvexHullTrick<T, objective> cht;\n  for(auto[k,m]:vp)\
    \ cht.add(k,m);\n\n  optional<T> res;\n  for(auto[y1,y0]:cht.getVertices())\n\
    \    if(y0>=0 and y1>=0) chmin(res,calc(y0,y1));\n  return res;\n}\n\n// minimize_{y0,\
    \ y1 >=0} p0 y0 + p1 y1\n// s.t. as[i] * y0 + bs[i] * y1 >= cs[i]\n// assume as[i],\
    \ bs[i] >0\ntemplate<typename T>\nT solve_lp_min(T p0,T p1,vector<T> as,vector<T>\
    \ bs,vector<T> cs){\n  T y0=0,y1=0;\n  for(int i=0;i<(int)as.size();i++){\n  \
    \  y0=max(y0,cs[i]/as[i]);\n    y1=max(y1,cs[i]/bs[i]);\n  }\n  auto res=solve_lp<T,\
    \ Objective::MAXIMIZE>(+p0,+p1,as,bs,cs);\n  chmin(res,p0*y0);\n  chmin(res,p1*y1);\n\
    \  return *res;\n}\n\n// maximize_{y0, y1 >=0} p0 y0 + p1 y1\n// s.t. as[i] *\
    \ y0 + bs[i] * y1 <= cs[i]\n// assume as[i], bs[i] >0, cs[i] >=0\ntemplate<typename\
    \ T>\nT solve_lp_max(T p0,T p1,vector<T> as,vector<T> bs,vector<T> cs){\n  T y0=cs[0]/as[0],y1=cs[0]/bs[0];\n\
    \  for(int i=0;i<(int)as.size();i++){\n    y0=min(y0,cs[i]/as[i]);\n    y1=min(y1,cs[i]/bs[i]);\n\
    \    as[i]=-as[i];bs[i]=-bs[i];cs[i]=-cs[i];\n  }\n  auto res=solve_lp<T, Objective::MINIMIZE>(-p0,-p1,as,bs,cs);\n\
    \  chmin(res,-p0*y0);\n  chmin(res,-p1*y1);\n  return -*res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/convexhulltrick.cpp
  requiredBy: []
  timestamp: '2022-03-10 13:03:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/convexhulltrick.cpp
layout: document
redirect_from:
- /library/data-structure/convexhulltrick.cpp
- /library/data-structure/convexhulltrick.cpp.html
title: data-structure/convexhulltrick.cpp
---
