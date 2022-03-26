---
title: SegmentTree
documentation_of: //segtree/segtree.cpp
---

## 概要
数列 $a_0,\dots,a_{n-1}$ に対し、一点代入と区間積をそれぞれ $O(\log n)$ で行うデータ構造  
演算 $f$ は結合法則を満たし、単位元 $ti$ を持つ必要がある（モノイド）  

## 呼び出し

- `SegmentTree<T> seg(function<T(T,T)> f,T ti,int n=1)`
  - 単位元 $ti$ で初期化された長さ $n$ の数列 $a_0,\dots,a_{n-1}$ を生成
  - $O(n)$
- `SegmentTree<T> seg(function<T(T,T)> f,T ti,const vector<T>&v)`
  - 数列 $v$ をコピーした数列 $a$ を生成
  - $v$ の長さを $n$ として $O(n)$
- `void init(int n)`
  - 単位元 $ti$ で初期化された長さ $n$ の数列 $a_0,\dots,a_{n-1}$ を生成
  - $O(n)$
- `void build(const vector<T>&v)`
  - 数列 $v$ をコピーした数列 $a$ を生成
  - $v$ の長さを $n$ として $O(n)$
- `T seg[k]`
  - $a_k$ を返す
- `void set_val(int k,T x)`
  - $a_k$ に $x$ を代入
  - $O(\log n)$
- `T query(int l,int r)`
  - 区間 $[l,r)$ の積を返す
  - つまり、$f(a_l,f(a_{l+1},\dots,f(a_{r-2},a_{r-1})))$ を返す
  - $l>r$ の時は $ti$ を返す
  - $O(\log n)$

## その他
計算量は演算が行われる回数である（$f$ が重い時に注意）  
内部では $dat_{n+k}$ が $a_k$ に対応  
根は $dat_0$ であり、$dat_k$ の子は $dat_{2k},dat_{2k+1}$ である