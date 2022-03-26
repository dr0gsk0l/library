//using ll=long long;
struct SegmentMap{
  map<ll,ll> mp;//mp[l]=r:[l,r)
  //[l,m) [m,r) は[l,r)になる　連続する黒の区間を持つみたいなイメージ
  const ll LINF=4e18;

  SegmentMap(){
    mp[-LINF]=-LINF;
    mp[LINF]=LINF;
  }

  inline auto get_it(ll a){//aを含む[l,r)のiterator
    auto it=--mp.upper_bound(a);
    if(a<(it->second))return it;
    return mp.end();
  }

  tuple<ll,ll> get(ll a){
    auto it=get_it(a);
    if(it==mp.end())return {LINF,-LINF};
    return {it->first,it->second};
  }

  bool same(ll a,ll b){
    auto it=get_it(a);
    return it!=mp.end() && (it->first)<=b && b<(it->second);
  }

  tuple<ll,ll> insert(ll l,ll r){//[l,r)を挿入
    auto it=--mp.upper_bound(l);
    if((it->second)>=l)l=it->first;
    else ++it;
    while((it->first)<=r){
      r=max(r,it->second);
      it=mp.erase(it);
    }
    mp[l]=r;
    return {l,r};
  }

  void remove(ll l,ll r){//[l,r)と共通部分を持つ区間全削除
    auto it=--mp.upper_bound(l);
    if((it->second)<=l)++it;
    while((it->first)<r)it=mp.erase(it);
  }
};