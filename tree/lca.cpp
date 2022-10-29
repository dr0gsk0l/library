#include "tree/tree.cpp"

struct LCA{
  Tree T;
  int n,root,log;
  vector<vector<int>> ancestor;
  
public:
  LCA(const Tree&T_,int root_=0):T(T_),root(root_){
    n=T.n;
    for(log=0;(1<<log)<=n;log++){}
    ancestor.resize(n, vector<int>(log,root) );

    T.build(root);
    reverse(T.DFS.begin(),T.DFS.end());
    for(int p:T.DFS)if(p!=root){
      ancestor[p][0]=T.parent[p];
      for(int i=1;i<log;i++)ancestor[p][i]=ancestor[ancestor[p][i-1]][i-1];
    }
  }

  int lca(int u,int v){
    if(T.depth[u]>T.depth[v])swap(u,v);
    for(int diff=T.depth[v]-T.depth[u],cnt=0;diff;cnt++,diff>>=1)
      if(diff&1)v=ancestor[v][cnt];
    if(u==v)return u;
    for(int k=log-1;k>=0;k--)
      if(ancestor[u][k]!=ancestor[v][k])
        u=ancestor[u][k],v=ancestor[v][k];
    return ancestor[u][0];
  }

  int diameter(int u,int v){
    int w=lca(u,v);
    return T.depth[u]+T.depth[v]-2*T.depth[w];
  }
};
