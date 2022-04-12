template<typename T>
struct BIT{
  int n;
  vector<T> bit;
  //1-indexed
  BIT():n(-1){}
  BIT(int n_,T d):n(n_),bit(n_+1,d){}
  
  //bit[i]は長さはiの最後のbit分で、スタートはそれ以外のbit 合計でちょうどiまでの情報
  //最後のbitが表す物をk,それ以外のbitが表す物をlとするとbit[i]=(l,l+k]でl+k=i

  T sum(int i){
    T s=bit[0];
    for(int x=i;x>0;x-=(x&-x))//x&-x:(xの最後のbit) 上の言葉でxをl+kからlにしてる
      s+=bit[x];
    return s;
  }
  
  void add(int i,T a){
    if(i==0) return;
    for(int x=i;x<=n;x+=(x&-x))//k,l+kは自明に増える lは増えない(lとkの間に0が出来ない)
      bit[x]+=a;
  }

  int lower_bound(int w){//w以上となる最小の場所を返す 単調性を仮定してる(bit[i]>=0)
    if(w<=0) return 0;
    int x=0,r=1;
    while(r<n) r<<=1;
    for(int k=r;k>0;k>>=1){//xに2のべき乗を大きい方から足せるなら足すだけ
      if(x+k<=n&&bit[x+k]<w){
        w-=bit[x+k];
        x+=k;
      }
    }
    return x+1;//xはw未満を満たす最大の場所なので1大きい値を返す
  }

  T sum0(int i){
    return sum(i+1);
  }
  
  void add0(int i,T a){
    add(i+1,a);
  }

  T query(int l,int r){
    return sum(r-1)-sum(l-1);
  }

  T query0(int l,int r){
    return sum(r)-sum(l);
  }
};
//END CUT HERE