cmake_minimum_required(VERSION 3.8...3.14 FATAL_ERROR)
project(Nagi VERSION 0.1 LANGUAGES CXX)

add_compile_options(-march=native -Wall -Wextra -Wpedantic)

find_package(PkgConfig REQUIRED)
pkg_check_modules(ICU REQUIRED icu-uc)
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost 1.69 REQUIRED)

add_subdirectory(src)

add_executable(main
  app/main.cpp
  )


target_link_libraries(main nagi)

target_include_directories(main PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(main ${Boost_LIBRARIES})
target_link_libraries(main Threads::Threads)

target_compile_features(main PRIVATE cxx_std_17)
set_target_properties(main PROPERTIES CXX_EXTENSIONS OFF)
