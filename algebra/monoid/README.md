```cpp
template<typename X>
struct MonoidHoge{
  using value_type=X;
  static constexpr X op(const X& x, const X& y){}
  static constexpr void Rchop(X&x, const X&y){ x=op(x,y); }
  static constexpr void Lchop(const X&x, X&y){ y=op(x,y); }
  static constexpr X power(const X& x, const long long n){}
  static constexpr X unit(){}
  static constexpr bool commute;
};
```

* ```value_type``` は必ずしも ```X``` と一致するとは限らない  
* ```Rchop``` は右からチョップするイメージ 名前の由来は「```min```→```chmin``` なら ```op```→```chop``` だよね！」と言う感じ  
* 実際に速くなるのかは分かってないが ```chop``` は ```x=op(x,y)``` では無く ```x+=y``` のように書けるならそう書きたい気がする  
* ```power``` は別に実装しなくても良い maspypy にあったので残しているだけ
* ```commute``` と同じように ```idempotency``` （冪等性）なんかも書いてもいいのかも？と思ったが、max,min,gcd,lcm 程度しかないので保留 
