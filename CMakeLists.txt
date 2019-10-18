cmake_minimum_required(VERSION 2.6)
project(GEPENGINE)

include_directories(src)

add_library(gepEngine
  src/gepEngine/Core.cpp
  src/gepEngine/Core.h
	src/gepEngine/Component.cpp
  src/gepEngine/Component.h
  src/gepEngine/Entity.cpp
  src/gepEngine/Entity.h
  src/gepEngine/Keyboard.cpp
  src/gepEngine/Keyboard.h
)

add_executable(sandbox
  src/sandbox/main.cpp
)
target_link_libraries(sandbox gepEngine)
