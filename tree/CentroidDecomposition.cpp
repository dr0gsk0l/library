template<typename TREE>
vector<int> centroid_decomposition(TREE&T){
  assert(T.is_prepared());
  vector<bool> used(T.n,false);
  vector<int> sz(T.n),par(T.n),res;
  res.reserve(T.n);

  auto find_centroid=[&](int v){
    vector<int> S{v};
    for(int i=0;i<S.size();i++){
      sz[S[i]]=1;
      for(const auto&e:T[S[i]]){
        if(e.to==par[S[i]]||used[e.to])continue;
        par[e.to]=S[i];
        S.push_back(e.to);
      }
    }
    reverse(S.begin(),S.end());
    for(int u:S){
      if( S.size()-sz[u] <= S.size()/2 )return u;
      sz[par[u]] += sz[u];
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