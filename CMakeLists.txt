cmake_minimum_required(VERSION 3.0)
project(IndieStudio)

set(CMAKE_CXX_STANDARD 14)
file(GLOB_RECURSE SRCS "src/*.cpp")
set(IRRLICHT_VERSION "1.8.4")
set(IRRLICHT_DIR "irrlicht-${IRRLICHT_VERSION}")
set(BIN_NAME "bomber")

#foreach (HEADER_FILES ${HEADERS})
#    get_filename_component(HEADER_DIRECTORY ${HEADERS} DIRECTORY)
#    include_directories(${HEADER_DIRECTORY})
#endforeach (HEADER_FILES)
#set(SOURCE_FILES src/main.cpp)

set(CMAKE_CXX_FLAGS "-g3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfatal-errors")

include_directories(src/ src/ecs src/indie/core src/indie/systems src/indie/components src/indie/entities src/indie/contexts src/indie/events ${IRRLICHT_DIR}/include /usr/include/lua5.1/)
link_directories(${IRRLICHT_DIR}/linux)
add_executable(${BIN_NAME} ${SRCS})
target_link_libraries(${BIN_NAME} Irrlicht GL Xxf86vm Xext X11 Xcursor lua5.1 sfml-graphics sfml-window sfml-system sfml-audio)
