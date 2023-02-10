#pragma once
#define REP_(i,n) for(int i=0;i<(n);i++)
struct Perm{
  using vi=vector<int>;
  // (v[i],i) で座圧
  template<typename T>
  static vi make_perm(const vector<T>&v){
    vi w=v;
    sort(w.begin(),w.end());
    map<T,int> mp;
    REP_(i,v.size())if(!i or w[i-1]!=w[i])mp[w[i]]=i;
    REP_(i,v.size())w[i]=mp[v[i]]++;
    return w;
  }
  // r[p[i]]=i;
  static vi rev(const vi&p){
    assert(is_permutation(p));
    auto res=p;
    REP_(i,p.size())res[p[i]]=i;
    return res;
  }
  // r[i] = p[q[i]]
  static vi composite(const vi&p, const vi&q){
    assert(p.size()==q.size());
    assert(is_permutation(p));
    assert(is_permutation(q));
    auto res=p;
    REP_(i,p.size())res[i]=p[q[i]];
    return res;
  }
  static vector<vi> divide_cycle(const vi&p){
    assert(is_permutation(p));
    int n=p.size();
    vector<bool> used(n,false);
    vector<vi> res;
    for(int x:p){
      if(used[x])continue;
      used[x]=true;
      res.emplace_back(vi{x});
      int now=p[x];
      while(now != x){
        assert(!used[now]);used[now]=true;
        res.back().push_back(now);
        now = p[now];
      }
    }
    return res;
  }
  static bool is_permutation(const vi&p){
    int n=p.size();
    vector<bool> used(n,false);
    for(int x:p){
      if(used[x])return false;
      used[x]=true;
    }
    return true;
  }
private:
  static void rearrange(const vi&p){}
  template<typename T>
  static void execute_rearrange(const vi&p, vector<T>&v){
    assert(p.size()==v.size());
    auto w=v;
    REP_(i,p.size())w[i]=v[p[i]];
    swap(v,w);
  }
public:
  // v を (p[i],v[i]) での昇順にする
  template<typename Head,typename... Tail>
  static void rearrange(const vi&p, Head&v, Tail&...tail){
    execute_rearrange(p,v);
    rearrange(p,tail...);
  }
};
#undef REP_