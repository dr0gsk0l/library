---
title: ReRooting
documentation_of: tree/ReRooting.cpp
---

$n$ 頂点無向グラフ $T$ を入力にとる  
各頂点 $r\in[n]$ に対して $r$ を根とした時の以下の $dp[r]$ を返す

$$
dp[v] = \oplus_{c\in C(v)} f(dp[v],e_{vc})
$$
### 補足
$C(v)$ : $v$ の子  
$\oplus$ : 可換 monoid

---
* ```ReRooting<TREE,Data>(const TREE&T)```
コンストラクタ  
```Data``` は dp の型

* ```vector<Data> build(const F1&score,const F2&merge, const Data&unit)```  
  演算回数 $O(n)$
  * ```Data score(Data d,Edge e)```  
  $f(d,e)$ を返す
  * ```void merge(Data&d,const Data&add)```  
  $d \leftarrow d\oplus add$
  * ```Data unit```  
  Data の（$\oplus$ での）単位元
