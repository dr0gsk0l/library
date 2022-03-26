struct Grid{
  vector<string> field;
  int h,w;
  int dy[8]={-1,0,1,0,-1,-1,1,1};
  int dx[8]={0,1,0,-1,-1,1,1,-1};
  Grid():{}
  Grid(int h,int w):h(h),w(w),field(h){}
  void scan(){
    for(auto &s:field)cin>>s;
  }
  bool in(int y,int x){
    return 0<=y&&y<h&&0<=x&&x<w;
  }
};