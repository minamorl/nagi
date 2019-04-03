add_library(nagi
  hello.cpp
  )

target_include_directories(nagi
  PUBLIC "${PROJECT_SOURCE_DIR}/include"
  )
