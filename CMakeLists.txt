cmake_minimum_required(VERSION 2.6)
project(GEPENGINE)

include_directories(src)


if(WIN32)
  include_directories(
	  contrib/include
  )

	link_directories(${CMAKE_SOURCE_DIR}/contrib/lib/gcc)
endif()


add_library(rend
	src/rend/Exception.cpp
	src/rend/Context.cpp
	src/rend/Texture.cpp
	src/rend/RenderTexture.cpp
	src/rend/Shader.cpp
	src/rend/Buffer.cpp
	src/rend/Mesh.cpp
	src/rend/Util.cpp
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
	src/gepEngine/Component.cpp
	src/gepEngine/Entity.cpp
	src/gepEngine/Keyboard.cpp
	src/gepEngine/Exception.cpp
	src/gepEngine/Transform.cpp
	src/gepEngine/Camera.cpp
	src/gepEngine/Screen.cpp
	src/gepEngine/Environment.cpp
	src/gepEngine/Resource.cpp
	src/gepEngine/Mesh.cpp
	src/gepEngine/Material.cpp
	src/gepEngine/stb_image.h
	src/gepEngine/stb_vorbis.h
	src/gepEngine/Resources.cpp
	src/gepEngine/MeshRenderer.cpp
	src/gepEngine/BoxCollider.cpp
)

target_link_libraries(gepEngine SDL2 rend OpenAL32)


add_executable(sandbox
	src/sandbox/main.cpp
)
target_link_libraries(sandbox gepEngine)
