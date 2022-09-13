template<typename T>
struct Multiset:multiset<T>{
  using multiset<T>::size;
  using multiset<T>::begin;
  using multiset<T>::end;
  using multiset<T>::rbegin;
  using multiset<T>::insert;
  using multiset<T>::erase;
  using multiset<T>::find;
  using multiset<T>::lower_bound;
  using multiset<T>::upper_bound;
  
  T mn()const{ assert(size());return *begin(); }
  T mx()const{ assert(size());return *rbegin(); }
  
  T pop_front(){
    assert(size());
    T mn=*begin();
    erase1(mn);
    return mn;
  }
  T pop_back(){
    assert(size());
    T mx=*rbegin();
    erase1(mx);
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

  void erase1(const T&a){ if(find(a)!=end())erase(find(a)); }
  
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