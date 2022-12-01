template<typename TREE,typename Data>
class ReRooting{
  int n;
  TREE T;
public:
  ReRooting(TREE&T):T(T),n(T.n){}

  template<typename F1,typename F2>
  vector<Data> build(const F1&score,const F2&merge,const Data&unit){
    if(!~T.root)T.build(0);
    vector<Data> dp1(n,unit),dp2(n);
    for(int v:T.DFS)
      for(const auto&e:T.son(v)){
        dp2[e.to]=score(dp1[e.to],e);
        merge(dp1[v],dp2[e.to]);
      }
    vector<Data> top(n,unit),res(n);
    for(int v:T.BFS){
      Data now=(T.root==v?unit:score(top[v],T.parent(v)));
      for(const auto&e:T.son(v)){
        top[e.to]=now;
        merge(now,dp2[e.to]);
      }
      res[v]=now;
      now=unit;
      for(int i=T.son(v).size()-1;i>=0;i--){
        const auto&e=T.son(v)[i];
        merge(top[e.to],now);
        merge(now,dp2[e.to]);
      }
    }
    return res;
  }
};