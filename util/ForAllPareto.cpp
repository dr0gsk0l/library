template<typename F>
void for_all_pareto(const vector<int>&v, const F&f){
  int n=v.size();
  vector<int> a(n,0);
  while(true){
    f(a);
    int idx=0;
    while(idx<n and a[idx]==v[idx])a[idx++]=0;
    if(idx==n)break;
    a[idx]++;
  }
}