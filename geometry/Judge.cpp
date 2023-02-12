#pragma once
#include "geometry/Base.cpp"
#include "geometry/UtilFunction.cpp"
namespace geometry{
  bool is_orthogonal(Vector a,Vector b){
    return is_equal(dot(a,b),0.0);
  }
  bool is_orthogonal(Point a1,Point a2,Point b1,Point b2){
    return is_orthogonal(a1-a2,b1-b2);
  }
  bool is_orthogonal(Segment s1,Segment s2){
    return is_equal(dot(s1.p2-s1.p1,s2.p2-s2.p1),0.0);
  }

  bool is_parallel(Vector a,Vector b){
    return is_equal(cross(a,b),0.0);
  }
  bool is_parallel(Point a1,Point a2,Point b1,Point b2){
    return is_parallel(a1-a2,b1-b2);
  }
  bool is_parallel(Segment s1,Segment s2){
    return is_equal(cross(s1.p2-s1.p1,s2.p2-s2.p1),0.0);
  }
  
  //bool is_intersect(Point p1,Point p2,Point p3,Point p4){
  //  return (ccw(p1,p2,p3)*ccw(p1,p2,p4) <= 0 and
  //          ccw(p3,p4,p1)*ccw(p3,p4,p2) <= 0 );
  //}
  //bool is_intersect(Segment s1,Segment s2){
  //  return is_intersect(s1.p1,s1.p2,s2.p1,s2.p2);
  //}
  //bool is_intersect(Polygon p,Segment l){
  //  int n=p.size();
  //  for(int i=0;i<n;i++)
  //    if(is_intersect(Segment(p[i],p[(i+1)%n]),l)) return 1;
  //  return 0;
  //}
//
  //bool is_convex(Polygon p){
  //  bool f=1;
  //  int n=p.size();
  //  for(int i=0;i<n;i++){
  //    int t=ccw(p[(i+n-1)%n],p[i],p[(i+1)%n]);
  //    f&=t!=CCW_CLOCKWISE;
  //  }
  //  return f;
  //}
}