
project (micrograd)

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
    find_package(matplotplusplus REQUIRED)
endif()

add_executable(micrograd src/main.cc)

target_link_libraries(micrograd PRIVATE spdlog::spdlog_header_only)
target_link_libraries(micrograd PRIVATE matplot)
