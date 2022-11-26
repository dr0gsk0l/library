template<typename T,typename U>
T sparse_subsequence(const vector<U>&v){
  map<U,T> mp;
  T res=1;
  for(U p:v){
    T tmp=res;
    res=res*2-mp[p];
    mp[p]=tmp;
  }
  return res;
}

template<typename T,typename SIZE>
T subsequence(const vector<int>&v){
  vector<T> memo(SIZE,0);
  T res=1;
  for(int p:v){
    T tmp=res;
    res=res*2-memo[p];
    memo[p]=tmp;
  }
  return res;
}

template<typename T>
T subsequence_alphabet(const string&s){
  vector<int> v;v.reserve(s.size());
  for(char c:s)v.push_back(c-(c<='Z'?'A':'a'));
  return subsequence<T,26>(v);
}