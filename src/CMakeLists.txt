project(QuizProjec)

set(QUIZ_TARGET "QuizProject")

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
find_package(TGUI 0.8 REQUIRED)

if(UNIX)
	find_package(OpenGL REQUIRED)
	find_package(GLUT REQUIRED)
	list(APPEND INCLUDES ${GLUT_INCLUDE_DIRS})
	list(APPEND LIBS stdc++fs)
endif()

list(APPEND INCLUDES ${CMAKE_CURRENT_SOURCE_DIR} ${OPENGL_INCLUDE_DIRS})
list(APPEND LIBS sfml-graphics tgui ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})


file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(${QUIZ_TARGET} ${SOURCES})
target_include_directories(${QUIZ_TARGET} PRIVATE ${INCLUDES})
target_link_libraries(${QUIZ_TARGET} PRIVATE ${LIBS})
