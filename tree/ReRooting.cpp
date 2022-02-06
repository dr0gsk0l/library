//key_t:辺固有の情報　頂点固有の情報はラムダの方でキャプチャさせる
//sum_t:計算結果
template<typename key_t,typename sum_t=key_t>
struct ReRooting{
  struct Edge {
    int from,to;
    key_t cost;
    sum_t dp1,dp2;
    //dp1:部分木の内容
    //dp2:e=g[idx][i]の時、g[idx][0,i)のdp1の累積が入る
  };
  using F=function<sum_t(sum_t,sum_t)>;
  using G=function<sum_t(sum_t,Edge)>;
 
  vector<vector<Edge>> g;
  const F merge;
  const G score;
  const sum_t id;
  vector<sum_t> dp1,dp2;
  ReRooting(int n,const G &score,const F &merge,const sum_t &id=sum_t{})
    :g(n),merge(merge),score(score),id(id),dp1(n,id),dp2(n,id){}
 
  void add_edge(int u,int v,const key_t &c){
    g[u].emplace_back(Edge{u,v,c,id,id});
    g[v].emplace_back(Edge{v,u,c,id,id});
  }
  void add_directed_edge(int u,int v,const key_t &c){
    g[u].emplace_back(Edge{u,v,c,id,id});
  }
 
  void dfs1(int idx,int pre){
    for(auto &e:g[idx])if(e.to!=pre){
      dfs1(e.to,idx);
      e.dp1=score(dp1[e.to],e);
      dp1[idx]=merge(dp1[idx],e.dp1);
    }
  }
 
  void dfs2(int idx,int pre,sum_t top){
    sum_t now=id;
    for(auto &e:g[idx]){
      e.dp2=now;
      if(e.to==pre)e.dp1=score(top,e);
      now=merge(now,e.dp1);
    }
    dp2[idx]=now;
    now=id;
    reverse(g[idx].begin(),g[idx].end());
    for(auto &e:g[idx]){
      if(e.to!=pre)
        dfs2(e.to,idx,merge(e.dp2,now));
      now=merge(now,e.dp1);
    }
  }
 
  vector<sum_t> build(){
    dfs1(0,-1);
    dfs2(0,-1,id);
    return dp2;
  }
};
//使用例:https://atcoder.jp/contests/abc222/submissions/26517686
