---
title: Matrix
documentation_of: //matrix.cpp
---

- `Matrix<K> M(size_t r,size_t c)`
  - 体$K$上の$r\times c$行列を生成
- `Matrix<K> M(vector<vector<K>> A)`
  - 二次元ベクトルAから行列を生成
- `+,+=,*,*=`
  - 行列同士の各種演算
- `Matrix I(size_t n)`
  - サイズ$n$の単位行列を返す
- `Matrix pow(long long n)`
  - $M$が正方行列のとき$M^n$を返す
  - サイズ$r\times r$として$O(r^3 log(n))$
- `int rank()`
  - 行列のランクを返す`
  - $O(rc^2)$
- `K det()`
  - $M$が正方行列のとき行列式を返す
  - $O(r^3)$
