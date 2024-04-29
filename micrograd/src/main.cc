// std
#include <cmath>

// deps
#include "spdlog/spdlog.h"
#include <matplot/matplot.h>

namespace mp = matplot;

int main()
{
    spdlog::info("Welcome to micrograd!");
    
    
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