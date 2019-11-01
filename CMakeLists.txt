cmake_minimum_required(VERSION 2.6)
project(GEPENGINE)

include_directories(src)

add_library(rend
	src/rend/Exception.cpp
	src/rend/Context.cpp
	src/rend/Texture.cpp
	src/rend/RenderTexture.cpp
	src/rend/Shader.cpp
	src/rend/Buffer.cpp
)
if(MSVC)
	target_link_libraries(rend glew32 opengl32)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	target_link_libraries(rend glew32 opengl32)
else()
	target_link_libraries(rend GLEW GL)
endif()

add_library(gepEngine
	src/gepEngine/Core.cpp
	src/gepEngine/Core.h
	src/gepEngine/Component.cpp
	src/gepEngine/Component.h
	src/gepEngine/Entity.cpp
	src/gepEngine/Entity.h
	src/gepEngine/Keyboard.cpp
	src/gepEngine/Keyboard.h
	src/gepEngine/GepEngine.h
	src/gepEngine/Exception.cpp
	src/gepEngine/Exception.h
	src/gepEngine/TriangleRenderer.cpp
	src/gepEngine/TriangleRenderer.h
	src/gepEngine/Transform.cpp
	src/gepEngine/Transform.h
	src/gepEngine/Camera.cpp
	src/gepEngine/Camera.h
	src/gepEngine/Screen.cpp
	src/gepEngine/Screen.h
	src/gepEngine/Environment.cpp
	src/gepEngine/Environment.h
)

target_link_libraries(gepEngine SDL2 rend)



add_executable(sandbox
	src/sandbox/main.cpp
)
target_link_libraries(sandbox gepEngine)
