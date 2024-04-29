
project (micrograd)

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)    
    find_package(matplotplusplus REQUIRED)
endif()

find_package(xtl REQUIRED)
find_package(xtensor REQUIRED)

add_executable(micrograd src/main.cc)

target_link_libraries(micrograd PRIVATE spdlog::spdlog_header_only)
target_link_libraries(micrograd PUBLIC matplot)
target_link_libraries(micrograd PUBLIC xtensor xtensor::optimize xtensor::use_xsimd)
