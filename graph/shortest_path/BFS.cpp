#pragma once
template<typename GRAPH>
pair<vector<int>,vector<int>> BFS(const GRAPH&g,int s=0){
  assert(g.is_prepared());
  vector<int> d(g.n,-1),pre(g.n,-1);
  queue<int> que;
  d[s]=0;
  que.push(s);
  while(que.size()){
    int v=que.front();que.pop();
    for(int to:g[v])
      if(d[to]<0){
        d[to]=d[v]+1;
        que.push(to);
      }
  }
  return {d,pre};
}