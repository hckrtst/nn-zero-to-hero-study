

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()


project (micrograd)
add_executable(mugrad src/main.cc)

target_link_libraries(mugrad PRIVATE spdlog::spdlog_header_only)