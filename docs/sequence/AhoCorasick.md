---
title: AhoCorasick
documentation_of: //sequence/AhoCorasick.cpp
---
* ```add(const vector<CHAR>&v,int num=1)```  
数列 $v$ を $num$ 個追加
$O(|v|)$

* ```void build()```  
数列の追加後ちょうど一回だけ呼び出す  
計算量は Trie 木の Node の個数（SIGMA 程度の定数倍がかかる）

* ```vector<int> suffix```  
```suffix[v]:```Trie 木内に存在する文字列であって、 Node $v$ の表す数列の suffix である最長のもの（の Node のインデックス）

* ```int match_count(const string&v)```  
$ \sum_{(l,r)} v[l,r)$ の個数 

## 概要
文字列集合 $S$ から、「 $t$ の部分文字列に $S$ の元はあるか」と言うクエリに答えられるデータ構造を作りたい  

### 例
>$S=\{abcdt,bcdfg,cdefg\}$  
>$t_1=abcdefgh$ (Yes)  
>$t_2=abcdefh$ (No)  


$S$ から自然に Trie 木を作ると、各 $t.substr(i)$ について Trie 木を辿ることでクエリを $O(|t|^2)$ で捌く事ができる  

例で $t_1$ を探索する場合 ```abcd``` まで行って ```e``` で諦めることになるが、ここで AhoCorasick は ```cde``` から探索を再開させる

より一般には、文字列 $t$ の Node が存在しなかった場合、**存在する Node のうち $t$ の最長 suffix から再開する**  

これを実現するようなオートマトンを作ればよく、Trie 木上で BFS 順に必要な情報を埋めていくことで簡単に達成できる