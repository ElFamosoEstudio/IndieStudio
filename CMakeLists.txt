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

#set(CMAKE_CXX_FLAGS "-g3")

include_directories(src/ src/ecs src/indie src/indie/systems src/indie/components ${IRRLICHT_DIR}/include)
link_directories(${IRRLICHT_DIR}/linux)
add_executable(${BIN_NAME} ${SRCS})
target_link_libraries(${BIN_NAME} Irrlicht GL Xxf86vm Xext X11 Xcursor)
