template<typename T>
class Imos{
  vector<T> data;
public:
  Imos()=default;
  Imos(int n):data(n+1,0){}
  // [0,n] を作る

  //[l,r) に a を追加
  void add(int l,int r,T a=1){
    assert(0<=l and l<=r and r<data.size());
    data[l] += a;
    data[r] -= a;
  }
  
  vector<T> build(){
    for(int i=0;i+1<data.size();i++)data[i+1]+=data[i];
    return data;
  }
};
