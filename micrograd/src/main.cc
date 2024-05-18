// std
#include <cmath>
#include <sstream>

// deps
#include "spdlog/spdlog.h"
#include <matplot/matplot.h>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>
namespace mp = matplot;

namespace mg{

template <typename T>
T f(T x)
{
  return 3*pow(x,2) - 4*x + 5;
}

template <>
xt::xarray<float> f(xt::xarray<float> x)
{
  auto res = x;
  for (auto it = res.begin(); it != res.end(); it++)
  {
    *it = 3*pow(*it,2) - 4*(*it) + 5.0;
  }
  return res;
}

#define DBG spdlog::info

}; // namespace

int main()
{
    spdlog::info("Welcome to the micrograd playground!");
    

    DBG("I got this value {}", mg::f(3.0));
    auto xs = xt::arange<float>(-5.0, 5.0, 0.25);

    std::ostringstream oss;
    oss << xs;
    DBG("range {}", oss.str());

    auto ys = mg::f<xt::xarray<float>>(xs);
    { 
      std::ostringstream oss;
      oss << ys;
      DBG("resulting range {}", oss.str());
    }


    mp::plot(xt::xarray<float>(xs), xt::xarray<float>(ys), "-o");
    mp::hold(mp::on);
    mp::show();
    return 0;
}

