add_library(nagi
  server.cpp
  tcp_connection.cpp
  hpack/constants.cpp
  )

target_include_directories(nagi
  PUBLIC "${PROJECT_SOURCE_DIR}/include"
  )
target_include_directories(nagi PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(nagi ${Boost_LIBRARIES})
