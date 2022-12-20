#pragma once
// set_mod より後で宣言する
template<typename MINT>
class MintUtility{
  vector<vector<MINT>> nCk_{vector<MINT>{1}};
  int S=1;

  void extend(const int n){
    if(n<S)return;
    const int preS=S;
    do{S<<=1;}while(S<=n);

    nCk_.resize(S);
    for(int i=preS;i<S;i++){
      nCk_[i].resize(i/2+1);
      nCk_[i][0]=1;
      for(int j=1;j<=i/2;j++)nCk_[i][j]=nCk_[i-1][min(j,i-1-j)]+nCk_[i-1][min(j-1,i-1-(j-1))];
    }
  }
public:
  MINT nCk(int n,int k){
    if(k<0 || n<k)return 0;
    extend(n);
    return nCk_[n][min(k,n-k)];
  }
};