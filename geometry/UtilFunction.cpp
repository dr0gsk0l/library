#pragma once
#include "geometry/Base.cpp"
namespace geometry{
  double cross(Vector a,Vector b){
    return a.x*b.y-a.y*b.x;
  }

  Point orth(Point p){return Point(-p.y,p.x);}

  Point project(Segment s,Point p){
    Vector base=s.p2-s.p1;
    double r=dot(p-s.p1,base)/base.norm();
    return s.p1+base*r;
  }

  Point reflect(Segment s,Point p){
    return p+(project(s,p)-p)*2.0;
  }

  Polygon convex_hull(Polygon ps){
    int n=ps.size();
    sort(ps.begin(),ps.end(),cmp_y);
    int k=0;
    Polygon qs(n*2);
    for(int i=0;i<n;i++){
      while(k>1 and cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<0) k--;
      qs[k++]=ps[i];
    }
    for(int i=n-2,t=k;i>=0;i--){
      while(k>t and cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<0) k--;
      qs[k++]=ps[i];
    }
    qs.resize(k-1);
    return qs;
  }
}