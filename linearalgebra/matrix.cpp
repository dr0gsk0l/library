#define REP_(i,n) for(int i=0;i<(n);i++)
#define REP2_(i,s,n) for(int i=(s);i<(n);i++)
template<typename K>
struct Matrix{
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
    REP_(i,r)REP_(j,c)M[i][j]+=A[i][j];
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

  int rank() const{
    Matrix A(M);
    int res=0;
    REP_(k,c){
      for(int i=res+1;i<r&&A[res][k]==0;i++)
        if(A[i][k]!=0)swap(A[i],A[res]);
      if(A[res][k]==0)continue;
      REP2_(l,k+1,c)A[res][l]/=A[res][k];
      REP2_(j,res+1,r)REP2_(l,k+1,c)A[j][l]-=A[j][k]*A[res][l];
      res++;
    }
    return res;
  }

  K det() const{
    assert(r==c);
    Matrix A=M;
    K res(1);
    REP_(i,r){
      for(int j=i+1;j<c&&A[i][i]==0;j++)
        if(A[j][i]!=0)swap(A[i],A[j]),res=-res;
      if(A[i][i]==0)return 0;
      res*=A[i][i];
      REP2_(k,i+1,c)A[i][k]/=A[i][i];
      REP2_(j,i+1,r)REP2_(k,i+1,c)A[j][k]-=A[j][i]*A[i][k];
    }
    return res;
  }

  friend ostream& operator<<(ostream&os,const Matrix &M){ os<<M.M; return os; }
  friend istream& operator>>(istream&is,Matrix &M){ REP_(i,M.r)REP_(j,M.c)is>>M.M[i][j]; return is; }
};
#undef REP_
#undef REP2_