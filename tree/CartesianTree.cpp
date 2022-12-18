#include "tree/WeightedTree.cpp"

// 最小値で分割 根付き木を渡す 根が最小値のindex
// 等しい値に関しては index の大小を比較する
// 辺の重みは子の部分木が担当する半開区間
template<typename T>
WeightedTree<pair<int,int>> cartesian_tree(const vector<T>&v){
  int n=v.size();
  vector<pair<int,int>> interval(n);
  for(int i=0;i<n;i++)interval[i]={0,n};
  stack<int> sta;
  for(int i=0;i<n;i++){
    int pre=-1;
    while(sta.size() and v[i]<v[sta.top()]){
      pre=sta.top();
      interval[pre].second=i;
      sta.pop();
    }
    if(sta.size())interval[i].first=sta.top()+1;
    sta.push(i);
  }
  WeightedTree<pair<int,int>> t(n);
  int root;
  for(int i=0;i<n;i++){
    const auto&[l,r]=interval[i];
    if(l==0 and r==n)
      root=i;
    else{
      if(l==0)t.add_edge(r,i,{l,r});
      if(r==n)t.add_edge(l-1,i,{l,r});
      if(l!=0 and r!=n)
        if(v[l-1]>v[r])t.add_edge(l-1,i,{l,r});
        else t.add_edge(r,i,{l,r});
    }
  }
  t.build(root);
  return t;
}