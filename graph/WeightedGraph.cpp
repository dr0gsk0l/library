#pragma once
template<typename T>
struct WeightedEdge{
  WeightedEdge()=default;
  WeightedEdge(int from,int to,T weight):from(from),to(to),weight(weight){}
  int from,to;
  T weight;
};

template<typename T>
struct WeightedGraph{
  int n;
  using weight_type=T;
  using edge_type=WeightedEdge<T>;
  vector<edge_type> edges;
protected:
  vector<int> in_deg;
  bool prepared;
  class OutgoingEdges{
    WeightedGraph* g;
    int l,r;
  public:
    OutgoingEdges(WeightedGraph* g,int l,int r):g(g),l(l),r(r){}
    edge_type* begin(){ return &(g->edges[l]); }
    edge_type* end(){ return &(g->edges[r]); }
    edge_type& operator[](int i){ return g->edges[l+i]; }
    int size()const{ return r-l; }
  };
public:
  OutgoingEdges operator[](int v){
    assert(prepared);
    return { this,in_deg[v],in_deg[v+1] };
  }

  bool is_prepared()const{ return prepared; }

  WeightedGraph():n(0),in_deg(1,0),prepared(false){}
  WeightedGraph(int n):n(n),in_deg(n+1,0),prepared(false){}
  WeightedGraph(int n,int m,bool directed=false,int indexed=1):
    n(n),in_deg(n+1,0),prepared(false){ scan(m,directed,indexed); }

  void resize(int n){n=n;}

  void add_arc(int from,int to,T weight){
    assert(!prepared);
    assert(0<=from and from<n and 0<=to and to<n);
    edges.emplace_back(from,to,weight);
    in_deg[from+1]++;
  }
  void add_edge(int u,int v,T weight){
    add_arc(u,v,weight);
    add_arc(v,u,weight);
  }

  void scan(int m,bool directed=false,int indexed=1){
    edges.reserve(directed?m:2*m);
    while(m--){
      int u,v;cin>>u>>v;u-=indexed;v-=indexed;
      T weight;cin>>weight;
      if(directed)add_arc(u,v,weight);
      else add_edge(u,v,weight);
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

  void graph_debug()const{
  #ifndef __LOCAL
    return;
  #endif
    assert(prepared);
    for(int from=0;from<n;from++){
      cerr<<from<<";";
      for(int i=in_deg[from];i<in_deg[from+1];i++)
        cerr<<"("<<edges[i].to<<","<<edges[i].weight<<")";
      cerr<<"\n";
    }
  }
};
