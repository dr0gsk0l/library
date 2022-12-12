#define REP_(i,n) for(int i=0;i<(n);i++)
#define REP2_(i,s,n) for(int i=(s);i<(n);i++)
template<typename K>
struct Matrix{
  using value_type=K;
  using vec=vector<K>;
  using mat=vector<vec>;
  size_t r,c;
  mat M;

  Matrix(size_t r,size_t c):r(r),c(c),M(r,vec(c,K())){}
  Matrix(mat A):M(A),r(A.size()),c(A[0].size()){}

  vec& operator[](size_t k){return M[k];}
  const vec& operator[](size_t k)const{return M[k];}

  
  Matrix& operator+=(const Matrix &A){
    assert(r==A.r&&c==A.c);
    REP_(i,r)REP_(j,c)M[i][j]+=A[i][j];
    return *this;
  }
  Matrix& operator-=(const Matrix &A){
    assert(r==A.r&&c==A.c);
    REP_(i,r)REP_(j,c)M[i][j]-=A[i][j];
    return *this;
  }
  Matrix operator+(const Matrix &A){ return Matrix(M)+=A; }
  Matrix operator-(const Matrix &A){ return Matrix(M)-=A; }

  friend Matrix operator*(const Matrix &A,const Matrix &B){
    assert(A.c==B.r);
    Matrix res(A.r,B.c);
    REP_(i,A.r)REP_(k,A.c)REP_(j,B.c)res[i][j]+=A[i][k]*B[k][j];
    return res;
  }
  Matrix& operator*=(const Matrix &A){
    M=((*this)*A).M;
    return *this;
  }

  bool operator==(const Matrix &A){
    if(r!=A.r||c!=A.c)return false;
    REP_(i,r)REP_(j,c)if(M[i][j]!=A[i][j])return false;
    return true;
  }
  bool operator!=(const Matrix &A){ return !((*this)==A); }
  
  static Matrix I(size_t n){
    Matrix res(n,n);
    REP_(i,n)res[i][i]=K(1);
    return res;
  }
  
  Matrix pow(long long n)const{
    assert(n>=0&&r==c);
    Matrix A(M),res=I(r);
    while(n){
      if(n&1)res*=A;
      A*=A;
      n>>=1;
    }
    return res;
  }

  pair<int,int> GaussJordan(){
    int rnk=0,cnt=0;
    REP_(k,c){
      if(M[rnk][k]==0)
        REP2_(i,rnk+1,r)
          if(M[i][k]!=0){
            swap(M[i],M[rnk]);
            cnt^=1;
            break;
          }
      if(M[rnk][k]==0)continue;
      REP_(i,r)if(i!=rnk){
        K x=M[i][k]/M[rnk][k];
        REP_(j,c)M[i][j]-=M[rnk][j]*x;
      }
      if(++rnk==r)break;
    }
    return {rnk,cnt};
  }

  K det()const{
    assert(r==c);
    Matrix A(M);
    const auto&[rnk,cnt]=A.GaussJordan();
    if(rnk!=r)return 0;
    K res=1;
    REP_(i,r)res*=A[i][i];
    return (cnt?-res:res);
  }

  optional<Matrix> inv()const{
    assert(r==c);
    Matrix A(r,c+c);
    REP_(i,r)REP_(j,c)A[i][j]=M[i][j];
    REP_(i,r)REP_(j,c)A[i][c+j]=K(i==j);
    A.GaussJordan();
    REP_(i,r)if(A[i][i]==0)return nullopt;
    Matrix res(r,c);
    REP_(i,r)REP_(j,c)res[i][j]=A[i][c+j]/A[i][i];
    return res;
  }
  
  friend ostream& operator<<(ostream&os,const Matrix &M){ os<<M.M; return os; }
  friend istream& operator>>(istream&is,Matrix &M){ REP_(i,M.r)REP_(j,M.c)is>>M.M[i][j]; return is; }
};
#undef REP_
#undef REP2_
