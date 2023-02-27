#pragma once
namespace R2{
  pair<int,int> direction(const char&c){
    if(c=='R')return {1,0};
    if(c=='L')return {-1,0};
    if(c=='U')return {0,-1};
    if(c=='D')return {0,1};
    return {0,0};
  }
}