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
    REP(i,v.size())if(!i or w[i-1]!=w[i])mp[w[i]]=i;
    REP(i,v.size())w[i]=mp[v[i]]++;
    return res;
  }
  // r[p[i]]=i;
  static vi rev(const vi&p){
    auto res=p;
    REP(i,p.size())res[p[i]]=i;
    return res;
  }
  // r[i] = p[q[i]]
  static vi composite(const vi&p, const vi&q){
    assert(p.size();==q.size());
    auto res=p;
    REP(i,p.size())res[i]=p[q[i]];
    return res;
  }
private:
  static void rearrange(const vi&p){}
  template<typename T>
  static void execute_rearrange(const vi&p, vector<T>&v){
    assert(p.size()==v.size());
    auto w=v;
    REP(i,p.size())w[i]=v[p[i]];
    swap(v,w);
  }
public:
  // v を (p[i],v[i]) での昇順にする
  template<typename Head,typename... Tail>
  static void rearrange(const vi&p, Head&v, Tail&...tail){
    execute_rearrange(p,v);
    rearrange(p,tail...);
  }
}
#undef REP_