#pragma once
#include "linearalgebra/Linear.cpp"
namespace insert_convex_hull_trick{
  enum Objective{
    MINIMIZE = +1,
    MAXIMIZE = -1,
  };

  // 最大化の場合は反転して、内部では最小化問題のみを扱う
  // 傾きが狭義単調減少になるように保存
  
  template<typename T,Objective OBJ>
  class InsertConvexHullTrick{
    using L=Line<T>;

    map<T,T> mp1,mp2; //傾き → 切片, 区間の右端 → 傾き
    // f(x)=ax+b に対し r = max_x { f(x) = min_g g(x)} として
    // mp1[a]=b, mp2[r]=a が入っている
    // r = \inf の時は mp2 には入れない

    template<typename IT>
    bool check(const IT it){
      // mp1 の it が要らないなら true を返す
      if(it==mp1.begin() or it==mp1.rbegin().base())return false;
      const auto&[a1,b1] = *prev(it);
      const auto&[a2,b2] = *it;
      const auto&[a3,b3] = *nxt(it);
      // 交点の x 座標はそれぞれ (b2-b1)/(a1-a2), (b3-b2)/(a2-a3)
      // これが <= なら要らない
      return (b2-b1)*(a2-a3) <= (b3-b2)*(a1-a2);
    }

    template<typename IT>
    T r(const IT it){
      // it が最小でいられる最大の r を返す
    }
  public:
    using value_type = L;

    InsertConvexHullTrick()=default;
    InsertConvexHullTrick(const vector<L>&lines){
      for(const auto&l:lines)add(l);
    }

    void add(L l){
      if(OBJ==-1)l=-l;
      if(mp1.count(l.a)){
        if(mp1[l.a]<=l.b)return;
        mp1.erase(l.a);
      }
      auto [it,flag]=mp1.insert(make_pair(l.a,l.b));
      if(check(it)){
        mp1.erase(it);
        return;
      }
      if(it != mp1.begin())
        for(auto l=pre(it);check(l);l=--mp1.erase(l)){}
      if(nxt(it) != mp1.end())
        for(auto r=nxt(it);check(r);r=mp1.erase(r)){}
      
    }
    void add(T a,T b){ add(L(a,b)); }

    T query(T x)const{
      assert(mp1.size());
      if(mp2.begin())
    }
  };
}
template<typename T>
using MinConvexHullTrick = convex_hull_trick::ConvexHullTrick<T,convex_hull_trick::Objective::MINIMIZE>;
template<typename T>
using MaxConvexHullTrick = convex_hull_trick::ConvexHullTrick<T,convex_hull_trick::Objective::MAXIMIZE>;