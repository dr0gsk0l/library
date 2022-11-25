#include "algebra/group_cntsum.cpp"
#include "algebra/group_linear.cpp"
template<typename X>
struct Lazy_Range_Affine_Range_Sum{
  using MX=Group_CntSum<X>;
  using MF=Group_Affine<X>;
  using P=typename MX::value_type;
  using F=typename MF::value_type;
  static constexpr P mapping(const F&f,const P&x){
    return {f.first*x.first+f.second*x.second, x.second};
  }
};