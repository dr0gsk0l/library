struct tree{
  struct node{
    vector<int> G,son,ancestor(30,-1);
    int depth,parent;
  };
  vector<node> T;
  vector<int> fromleaf;
  queue<int> que;
  int n,root;

  tree(int n):T(n),fromleaf(n),n(n),root(root){}

  void add_edge(int u,int v){
    T[u].G.push_back(v);
    T[v].G.push_back(u);
  }

  void have_root(int r){
    root=r;
    que.push(r);
    int now=n;
    while(que.size()){
      int p=que.front();que.pop();
      fromleaf[--now]=p;
      for(int q:G[p]){
        if(T[p].parent==q)continue;
        T[p].son.push_back(q);
        T[q].parent=T[q].ancestor[0]=p;
        for(int j=1;j<30;j++)if(~T[q].ancestor[j-1])
          T[q].ancestor[j]=T[ancestor[q][j-1]].ancestor[j-1];
        T[q].depth=T[p].depth+1;
        que.push(q);
      }
    }
  }

  int lca(int u,int v){
    if(depth[u]>depth[v])swap(u,v);
    int diff=depth[v]-depth[u],cnt=0;
    while(diff){
      if(diff&1)v=ancestor[v][cnt];
      cnt++;
      diff>>=1;
    }
    if(u==v)return u;
    for(int k=28;k>=0;k--)
      if(ancestor[u][k]!=ancestor[v][k])
        u=ancestor[u][k],v=ancestor[v][k];
    return ancestor[u][0];
  }
};
