cmake_minimum_required(VERSION 2.6)
project(GEPENGINE)

add_library(gepEngine
  src/gepEngine/Core.cpp
)

add_executable(sandbox
  src/sandbox/main.cpp
)
target_link_libraries(sandbox gepEngine)