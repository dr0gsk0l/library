template<typename T>
struct Multiset:map<T,int>{
  using map<T,int>::size;
  using map<T,int>::begin;
  using map<T,int>::rbegin;
  using map<T,int>::erase;
  using map<T,int>::lower_bound;
  using map<T,int>::upper_bound;

  void insert(const T&a){ (*this)[a]++; }
  void erase1(const T&a){ if((*this)[a] and !--(*this)[a])erase(a); }
 
  T mn()const{ assert(size()); return begin()->first; }
  T mx()const{ assert(size()); return rbegin()->first; }
  T pick_mn(){ // ピクミン
    T res=mn();
    erase1(res);
    return res;
  }
  T pick_mx(){
    T res=mx();
    erase1(res);
    return res;
  }

  T lt(const T&a)const{
    assert(mn()<a);
    if(mx()<a)return mx();
    return (--lower_bound(a))->first;
  }
  T leq(const T&a)const{
    assert(mn()<=a);
    if(mx()<=a)return mx();
    return (--upper_bound(a))->first;
  }
  T gt(const T&a)const{
    assert(mx()>a);
    return upper_bound(a)->first;
  }
  T geq(const T&a){
    assert(mx()>=a);
    return lower_bound(a)->first;
  }

  Multiset()=default;
  Multiset(const vector<T>&v){ for(const auto&p:v)insert(p); }
  
  void scan(int n){
    while(n--){
      T a;cin>>a;
      insert(a);
    }
  }
  
  void banpei(){
    insert(numeric_limits<T>::max()/2);
    insert(numeric_limits<T>::min()/2);
  }
};