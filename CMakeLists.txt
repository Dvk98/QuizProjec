cmake_minimum_required(VERSION 3.12.0)
project(QuizProjec)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

if(MSVC)
	add_definitions(/std:c++latest /MP /DWIN32_LEAN_AND_MEAN /D_CRT_SECURE_NO_WARNINGS)
else()
	add_compile_options(-std=c++17 -Wno-unused-variable)
endif()
	

add_subdirectory(src)
