#include <atcoder/fenwicktree>
using namespace atcoder;

#include "util/compress.cpp"

template <typename T>
long long inversion_number(const vector<T> &v){
  Compress cmp(v);
  fenwick_tree<int> ft(cmp.size());
  long long res=0;
  for(int i=int(v.size())-1;i>=0;i--){
    int j=cmp[v[i]];
    res+=ft.sum(0,j);
    ft.add(j,1);
  }
  return res;
}