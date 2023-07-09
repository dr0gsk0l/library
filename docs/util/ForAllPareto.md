---
title: for_all_pareto
documentation_of: library///util/ForAllPareto.cpp
---

長さ $n$ の配列 $v$ と関数 $f$ を引数に取り、$0\leq a_i\leq v_i　\forall i\in[n]$ を満たす各 $a$ に対して、$f(a)$ を行う

例えば、$0\leq i\leq 2$, $0\leq j \leq 3$, $0\leq k\leq 1$ を満たす各 $i,j,k$ に対して $2^i 3^j 5^k$ を列挙したい時は

```cpp
vector<int> base={2,3,1};

auto f=[&](vector<int>a){
  int x=1;
  for(int i=0;i<3;i++)while(a[i]--)x*=base[i];
  cout<<x<<endl;
};
for_all_pareto({2,3,5},f);
```

のように書くと良い