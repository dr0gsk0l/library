#pragma once
#include "graph/WeightedGraph.cpp"
#define REP_(i,n) for(int i=0;i<(n);i++)
template<typename T>
class Grid{
  const int h,w;
  optional<T> ban;
  // D,R,U,L
  static constexpr pair<int,int> d4[4]={{1,0},{0,1},{-1, 0},{0, -1}};
  template<typename vecvecT> void build(const vecvecT&grid){
    REP_(y,h)REP_(x,w){
      int p=id(y,x);
      v[p]=grid[y][x];
      if(ban and v[p]==ban.value())continue;
      REP_(d,4){
        int y2=y+d4[d].first,x2=x+d4[d].second;
        if(in(y2,x2) and (!ban or ban.value()!=grid[y2][x2]))
          G.add_arc(p,id(y2,x2),d);
      }
    }
    G.build();
  }
public:
  vector<T> v;
  WeightedGraph<int> G;
  bool in(int y,int x)const{
    return 0<=y and y<h and 0<=x and x<w;
  }
  int id(int y,int x)const{
    assert(in(y,x));
    return y*w+x;
  }
  pair<int,int> r2(int a)const{
    assert(0<=a and a<h*w);
    return {a/w,a%w};
  }

  Grid(const vector<vector<T>>&grid,const optional<T>&ban=nullopt):h(grid.size()),w(grid[0].size()),ban(ban),v(h*w),G(h*w){ build(grid); }
  Grid(const vector<string>&s,const optional<T>&ban=nullopt):h(s.size()),w(s[0].size()),ban(ban),v(h*w),G(h*w){
    static_assert(is_same<T,char>::value,"value_type==char");
    build(s);
  }
  
  int find(const T&c)const{
    REP_(i,h*w)if(v[i]==c)return i;
    return -1;
  }
};
#undef REP_