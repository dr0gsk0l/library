template<typename Key,typename Val>
struct Map:map<Key,Val>{
  using map<Key,Val>::erase;

  void operator()(Key key,Val val){
    if(!((*this)[key]+=val))erase(key);
  }
};