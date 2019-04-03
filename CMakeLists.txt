cmake_minimum_required(VERSION 3.8...3.14 FATAL_ERROR)

project(Nagi VERSION 0.1
             LANGUAGES CXX)
 #
find_package(Boost 1.69 REQUIRED) 

add_executable(main
  app/main.cpp
  )

include_directories(${Boost_INCLUDE_DIRS})

target_compile_features(main PUBLIC cxx_std_17)
set_target_properties(main PROPERTIES CXX_EXTENSIONS OFF)
