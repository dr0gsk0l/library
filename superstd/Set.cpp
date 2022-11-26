template<typename T>
struct Set:set<T>{
  using set<T>::size;
  using set<T>::begin;
  using set<T>::rbegin;
  using set<T>::insert;
  using set<T>::erase;
  using set<T>::lower_bound;
  using set<T>::upper_bound;
  
  T mn()const{ assert(size());return *begin(); }
  T mx()const{ assert(size());return *rbegin(); }
  
  T pop_front(){
    assert(size());
    T mn=*begin();
    erase(begin());
    return mn;
  }
  T pop_back(){
    assert(size());
    T mx=*rbegin();
    erase(mx);
    return mx;
  }

  T lt(const T&a)const{
    assert(mn()<a);
    if(mx()<a)return mx();
    return *--lower_bound(a);
  }
  T leq(const T&a)const{
    assert(mn()<=a);
    if(mx()<=a)return mx();
    return *--upper_bound(a);
  }
  T gt(const T&a)const{
    assert(mx()>a);
    return *upper_bound(a);
  }
  T geq(const T&a){
    assert(mx()>=a);
    return *lower_bound(a);
  }
  
  Set()=default;
  Set(const vector<T>&v){ for(const auto&p:v)insert(p); }
  
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