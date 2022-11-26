---
title: 部分列の種類数
documentation_of: //util/Subsequence.cpp
---

配列の（非連続を許す）部分列の種類数を求める
* ```<T,SIZE> T subsequence(const vector<int>&v)```  
要素が $[0,SIZE)$ であるような配列 $v$ に対して求める  
時間 $O(|v|)$  
空間 $O(SIZE)$

* ```<T> T subsequence_alphabet(const string&s)```  
英子文字のみ or 英大文字のみからなる文字列 $s$ に対して求める
時間 $O(|s|)$  
空間 $O(1)$

* ```<T,U> T sparse_subsequence(const vector<U>&v)```  
一般の配列 $v$ に対して求める  
時間 $O(|v|\log|v|)$  
空間 $O(|v|)$  
map を使うので $U$ に $<$ が定義されている必要がある  
あらかじめ $v$ の要素を座圧して ```subsequence``` に投げるのと本質的には同じ