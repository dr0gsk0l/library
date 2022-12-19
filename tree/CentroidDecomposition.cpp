template<typename TREE>
vector<int> centroid_decomposition(TREE&T){
  assert(T.is_prepared());
  vector<bool> used(T.n,false);
  vector<int> sz(T.n),pre(T.n),res;
  res.reserve(T.n);

  auto find_centroid=[&](int v){
    vector<int> S{v};
    pre[v]=-1;
    for(int i=0;i<S.size();i++){
      const int u=S[i];
      sz[u]=1;
      for(const auto&e:T[u]){
        if(e.to==pre[u]||used[e.to])continue;
        pre[e.to]=u;
        S.push_back(e.to);
      }
    }
    int SZ=S.size();
    reverse(S.begin(),S.end());
    for(int u:S){
      if( SZ-sz[u] <= SZ/2 )return u;
      sz[pre[u]] += sz[u];
    }
    assert(false);
    return -1;
  };

  queue<int> que;
  que.push(0);
  while(que.size()){
    int c=find_centroid(que.front());que.pop();
    used[c]=true;
    res.push_back(c);
    for(const auto&e:T[c])
      if(!used[e.to])
        que.push(e.to);
  }
  
  return res;
}