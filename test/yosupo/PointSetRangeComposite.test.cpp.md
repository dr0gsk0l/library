---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/modint.cpp
    title: mod/modint.cpp
  - icon: ':heavy_check_mark:'
    path: segtree/segtree.cpp
    title: SegmentTree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/yosupo/PointSetRangeComposite.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n\n#pragma GCC\
    \ optimize(\"Ofast\")\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line\
    \ 1 \"segtree/segtree.cpp\"\ntemplate<typename T>\nstruct SegmentTree{\n  using\
    \ F=function<T(T,T)>;\n  int n;\n  F f;\n  T ti;\n  vector<T> dat;\n  SegmentTree(){}\n\
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
    \    return f(vl,vr);\n  }\n};\n#line 1 \"mod/modint.cpp\"\ntemplate<typename\
    \ T,T MOD=998244353>\nstruct Mint{\n  inline static constexpr T mod = MOD;\n \
    \ T v;\n  Mint():v(0){}\n  Mint(signed v):v(v){}\n  Mint(long long t){v=t%MOD;if(v<0)v+=MOD;}\n\
    \n  Mint pow(long long k){\n    Mint res(1),tmp(v);\n    while(k){\n      if(k&1)res*=tmp;\n\
    \      tmp*=tmp;\n      k>>=1;\n    }\n    return res;\n  }\n\n  static Mint add_identity(){return\
    \ Mint(0);}\n  static Mint mul_identity(){return Mint(1);}\n\n  Mint inv(){return\
    \ pow(MOD-2);}\n\n  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}\n\
    \  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}\n  Mint&\
    \ operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}\n  Mint& operator/=(Mint a){return\
    \ (*this)*=a.inv();}\n\n  Mint operator+(Mint a) const{return Mint(v)+=a;}\n \
    \ Mint operator-(Mint a) const{return Mint(v)-=a;}\n  Mint operator*(Mint a) const{return\
    \ Mint(v)*=a;}\n  Mint operator/(Mint a) const{return Mint(v)/=a;}\n\n  Mint operator+()\
    \ const{return *this;}\n  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}\n\
    \n  bool operator==(const Mint a)const{return v==a.v;}\n  bool operator!=(const\
    \ Mint a)const{return v!=a.v;}\n\n  static Mint comb(long long n,int k){\n   \
    \ Mint num(1),dom(1);\n    for(int i=0;i<k;i++){\n      num*=Mint(n-i);\n    \
    \  dom*=Mint(i+1);\n    }\n    return num/dom;\n  }\n};\ntemplate<typename T,T\
    \ MOD>\nostream& operator<<(ostream&os,Mint<T,MOD> m){os<<m.v;return os;}\ntemplate<typename\
    \ T,T MOD>\nistream& operator>>(istream&is,Mint<T,MOD>&m){is>>m.v;m.v%=MOD;if(m.v<0)m.v+=MOD;return\
    \ is;}\n//END CUT HERE\n#line 9 \"test/yosupo/PointSetRangeComposite.test.cpp\"\
    \n\nusing mint=Mint<long long>;\nstruct Linear{\n  mint a,b;\n};\n\nint main(){\n\
    \  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int n,q;cin>>n>>q;\n\
    \n  vector<Linear> v(n);\n  for(int i=0;i<n;i++)cin>>v[i].a>>v[i].b;\n  SegmentTree<Linear>\
    \ seg([](Linear f,Linear g){\n    return Linear{f.a*g.a,g.a*f.b+g.b};\n  },{1,0},v);\n\
    \n  while(q--){\n    int t,l,r,x;cin>>t>>l>>r>>x;\n    if(t){\n      auto [a,b]=seg.query(l,r);\n\
    \      cout<<a*x+b<<\"\\n\";\n    }\n    else seg.set_val(l,Linear{r,x});\n  }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#pragma GCC optimize(\"Ofast\")\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#include \"../../segtree/segtree.cpp\"\n#include \"../../mod/modint.cpp\"\
    \n\nusing mint=Mint<long long>;\nstruct Linear{\n  mint a,b;\n};\n\nint main(){\n\
    \  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int n,q;cin>>n>>q;\n\
    \n  vector<Linear> v(n);\n  for(int i=0;i<n;i++)cin>>v[i].a>>v[i].b;\n  SegmentTree<Linear>\
    \ seg([](Linear f,Linear g){\n    return Linear{f.a*g.a,g.a*f.b+g.b};\n  },{1,0},v);\n\
    \n  while(q--){\n    int t,l,r,x;cin>>t>>l>>r>>x;\n    if(t){\n      auto [a,b]=seg.query(l,r);\n\
    \      cout<<a*x+b<<\"\\n\";\n    }\n    else seg.set_val(l,Linear{r,x});\n  }\n\
    }"
  dependsOn:
  - segtree/segtree.cpp
  - mod/modint.cpp
  isVerificationFile: true
  path: test/yosupo/PointSetRangeComposite.test.cpp
  requiredBy: []
  timestamp: '2022-03-26 14:25:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/PointSetRangeComposite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/PointSetRangeComposite.test.cpp
- /verify/test/yosupo/PointSetRangeComposite.test.cpp.html
title: test/yosupo/PointSetRangeComposite.test.cpp
---
