class LCA{
  Tree T;
  int n,root;
  vector<vector<int>> ancestor;
  vector<int> depth;

  void dfs(int idx,int pre){
    for(const int&p:T[idx])if(p!=pre){
      depth[p]=depth[idx]+1;
      ancestor[p][0]=idx;
      for(int i=1;i<30;i++)
        ancestor[p][i]=ancestor[ancestor[p][i-1]][i-1];
      dfs(p,idx);
    }
  }
public:
  LCA(const Tree&T,int root=0):T(T),root(root){
    n=T.size();
    ancestor.resize(n,vector<int>(30,root));
    depth.resize(n,0);
    dfs(root,-1);
    debug(ancestor);
  }

  int lca(int u,int v){
    if(depth[u]>depth[v])swap(u,v);
    for(int diff=depth[v]-depth[u],cnt=0;diff;cnt++,diff>>=1)
      if(diff&1)v=ancestor[v][cnt];
    if(u==v)return u;
    for(int k=29;k>=0;k--)
      if(ancestor[u][k]!=ancestor[v][k])
        u=ancestor[u][k],v=ancestor[v][k];
    return ancestor[u][0];
  }
};
