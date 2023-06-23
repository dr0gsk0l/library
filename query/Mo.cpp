class Mo{
  int n;
  vector<pair<int,int>> lr;
public:
  Mo()=default;
  Mo(const vector<pair<int,int>>&lr):lr(lr){
    for(const auto&[l,r]:lr){
      assert(0<=l and l<=r);
      n=max(n,r);
    }
  }
  void add(int l,int r){
    assert(0<=l and l<=r);
    lr.emplace_back(l,r);
    n=max(n,r);
  }

  template<typename AL,typename AR,typename EL,typename ER,typename F>
  void calc(const AL&add_left,const AR&add_right,const EL&erase_left,const ER&erase_right,const F&f){
    int q=lr.size();
    int B=max(1,n/int(sqrt(q)));
    vector<int> ord(q);
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),[&](int a,int b)->bool{
      int Ba=lr[a].first/B, Bb=lr[b].first/B;
      if(Ba!=Bb)return Ba<Bb;
      return (Ba&1) ^ (lr[a].second<lr[b].second);
    });
    int l=0,r=0;
    for(int idx:ord){
      while(l > lr[idx].first) add_left(--l);
      while(r < lr[idx].second) add_right(r++);
      while(l < lr[idx].first) erase_left(l++);
      while(r > lr[idx].second) erase_right(--r);
      f(idx);
    }
  }

  template< typename A,typename E,typename F>
  void calc(const A&add,const E&erase,const F&f) {
    calc(add,add,erase,erase,f);
  }
};