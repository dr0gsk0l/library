template<typename T>
ostream& operator<<(ostream&os,const set<T>&se){
  if(se.size){
    os<<"{";
    for(const auto&p:se)os<<p<<",}"[p==*se.rbegin()];
  }
  else os<<"{}";
  return os;
}

template<typename T>
ostream& operator<<(ostream&os,const unordered_set<T>&se){
  os<<"{";
  for(const auto&p:se)os<<p<<",";
  os<<"}";
  return os;
}

template<typename T,typename U>
ostream& operator<<(ostream&os,const map<T,U>&mp){
  for(const auto&[key,val]:mp)os<<"["<<key<<":"<<val<<"]";
  return os;
}
template<typename T,typename U>
ostream& operator<<(ostream&os,const unordered_map<T,U>&mp){
  for(const auto&[key,val]:mp)os<<"["<<key<<":"<<val<<"]";
  return os;
}

template<typename T,typename U>
ostream& operator<<(ostream&os,const pair<T,U>&P){
  os<<"["<<P.first<<","<<P.second<<"]";
  return os;
}

#  define debug(...) debug_internal(#__VA_ARGS__, __VA_ARGS__)

template <class T, class... Args>
void debug_internal(const char* s, T&& first, Args&&... args) {
    constexpr const char* open_brakets = sizeof...(args) == 0 ? "" : "(";
    constexpr const char* close_brakets = sizeof...(args) == 0 ? "" : ")";
    std::cerr << open_brakets << s << close_brakets << ": "
              << open_brakets << std::forward<T>(first);
    ((std::cerr << ", " << std::forward<Args>(args)), ...);
    std::cerr << close_brakets << endl;
}