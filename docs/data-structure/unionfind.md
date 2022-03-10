---
title: UnionFind
documentation_of: ./unionfind.cpp
---

## UnionFind

- `UnionFind uf(int n)`
  - $n$頂点$0$辺の無向グラフを作成
  - $O(n)$
- `void merge(int u,int v)`
  - 辺$(u,v)$を足す
  - ならし $O(\alpha(n))$
- `int leader(int v)`
  - 頂点$v$の属する連結成分の代表元を返す
  - ならし $O(\alpha(n))$
- `bool same(int u,int v)`
  - 頂点$u,v$が連結かどうかを返す
  - ならし $O(\alpha(n))$
- `int size(int v)`
  - 頂点$v$の属する連結成分のサイズを返す
- `int count()`
  - 連結成分の個数を返す