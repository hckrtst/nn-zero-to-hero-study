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

int main()
{
    spdlog::info("Welcome to micrograd!");
    
    // test xtensor
    xt::xarray<double> arr1
      {{1.0, 2.0, 3.0},
       {2.0, 5.0, 7.0},
       {2.0, 5.0, 7.0}};

    xt::xarray<double> arr2
      {5.0, 6.0, 7.0};

    xt::xarray<double> res = xt::view(arr1, 1) + arr2;

    std::ostringstream ss;
    ss << res;
    spdlog::info("I got this array {}", ss.str());
    
    // test matplot
    std::vector<double> x = mp::linspace(0, 2 * mp::pi);
    std::vector<double> y = mp::transform(x, [](auto x) { return sin(x); });

    mp::plot(x, y, "-o");
    mp::hold(mp::on);
    mp::plot(x, mp::transform(y, [](auto y) { return -y; }), "--xr");
    mp::plot(x, mp::transform(x, [](auto x) { return x / mp::pi - 1.; }), "-:gs");
    mp::plot({1.0, 0.7, 0.4, 0.0, -0.4, -0.7, -1}, "k");

    mp::show();

    return 0;
}