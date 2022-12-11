template<typename MINT>
class MintUtility{
  vector<MINT> fact_={MINT::raw(1)};
  vector<MINT> inv_fact_{MINT::raw(1)};
  int S=1;//今のサイズ

  void extend(const int n){
    if(n<S)return;
    const int preS=S;
    do{S<<=1;}while(S<=n);

    fact_.resize(S);
    for(int i=preS;i<S;i++)fact_[i]=fact_[i-1]*MINT::raw(i);

    inv_fact_.resize(S);
    inv_fact_.back()=fact_.back().inv();
    for(int i=S-1;i>preS;i--)inv_fact_[i-1]=inv_fact_[i]*MINT::raw(i);
  }
public:
  MINT fact(const int n){
    assert(n>=0);
    extend(n);
    return fact_[n];
  }
  MINT inv_fact(const int n){
    assert(n>=0);
    extend(n);
    return inv_fact_[n];
  }
  MINT nCk(const int n,const int k){
    if(k<0||n<k)return MINT::raw(0);
    extend(n);
    return fact_[n] * inv_fact_[k] * inv_fact_[n - k];
  }
  MINT nPk(const int n,const int k){
    if(k<0||n<k)return MINT::raw(0);
    extend(n);
    return fact_[n] * inv_fact_[n-k];
  }
  MINT nHk(const int n,const int k){
    return (n==0 and k==0?1:nCk(n+k-1,k));
  }
};