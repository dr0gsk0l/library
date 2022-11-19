#pragma once
template<typename T>
struct WeightedEdge{
  WeightedEdge()=default;
  WeightedEdge(int from,int to,T cost):from(from),to(to),cost(cost){}
  int from,to;
  T cost;
};

template<typename T>
struct WeightedGraph{
  int n;
  using cost_type=T;
  using edge_type=WeightedEdge<T>;
private:
  vector<edge_type> edges;
  vector<int> in_deg;
  bool prepared;
  class OutgoingEdges{
    const WeightedGraph* g;
    int l,r;
  public:
    OutgoingEdges(const WeightedGraph* g,int l,int r):g(g),l(l),r(r){}
    const edge_type* begin()const{ return &(g->edges[l]); }
    const edge_type* end()const{ return &(g->edges[r]); }
    const edge_type* operator[](int i)const{ return &(g->edges[l+i]); }
    int size()const{ return r-l; }
  };
public:
  OutgoingEdges operator[](int v)const{
    assert(prepared);
    return { this,in_deg[v],in_deg[v+1] };
  }

  bool is_prepared() { return prepared; }

  WeightedGraph():n(0),in_deg(1,0),prepared(false){}
  WeightedGraph(int n):n(n),in_deg(n+1,0),prepared(false){}
  WeightedGraph(int n,int m,bool directed=false,int indexed=1):
    n(n),in_deg(n+1,0),prepared(false){ scan(m,directed,indexed); }

  void resize(int n){n=n;}

  void add_arc(int from,int to,T cost){
    assert(!prepared);
    assert(0<=from and from<n and 0<=to and to<n);
    edges.emplace_back(from,to,cost);
    in_deg[from+1]++;
  }
  void add_edge(int u,int v,T cost){
    add_arc(u,v,cost);
    add_arc(v,u,cost);
  }

  void scan(int m,bool directed=false,int indexed=1){
    edges.reserve(directed?m:2*m);
    while(m--){
      int u,v;cin>>u>>v;u-=indexed;v-=indexed;
      T cost;cin>>cost;
      if(directed)add_arc(u,v,cost);
      else add_edge(u,v,cost);
    }
    build();
  }

  void build(){
    assert(!prepared);prepared=true;
    for(int v=0;v<n;v++)in_deg[v+1]+=in_deg[v];
    vector<edge_type> new_edges(in_deg.back());
    auto counter=in_deg;
    for(auto&&e:edges)new_edges[ counter[e.from]++ ]=e;
    edges=new_edges;
  }

  void graph_debug(){
  #ifndef __LOCAL
    return;
  #endif
    assert(prepared);
    for(int from=0;from<n;from++){
      cerr<<from<<";";
      for(int i=in_deg[from];i<in_deg[from+1];i++)
        cerr<<"("<<edges[i].to<<","<<edges[i].cost<<")";
      cerr<<"\n";
    }
  }
};