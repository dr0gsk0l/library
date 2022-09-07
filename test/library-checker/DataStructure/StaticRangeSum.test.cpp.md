---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: datastructure/cumulaitvesum.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"datastructure/cumulaitvesum.cpp\"\
    \n\nint main() {\n  int n,q;cin>>n>>q;\n  vector<int> v(n);\n  for(int i=0;i<n;i++)cin>>v[i];\n\
    \  auto wa=CumulativeSum(v);\n  while(q--){\n    int l,r;cin>>l>>r;\n    cout<<wa.sum(l,r)<<'\\\
    n';\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/DataStructure/StaticRangeSum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/StaticRangeSum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/StaticRangeSum.test.cpp
- /verify/test/library-checker/DataStructure/StaticRangeSum.test.cpp.html
title: test/library-checker/DataStructure/StaticRangeSum.test.cpp
---
