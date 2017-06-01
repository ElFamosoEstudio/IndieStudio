cmake_minimum_required(VERSION 3.7)
project(IndieStudio)

set(CMAKE_CXX_STANDARD 14)
file(GLOB_RECURSE SRCS "src/*.cpp")

#foreach (HEADER_FILES ${HEADERS})
#    get_filename_component(HEADER_DIRECTORY ${HEADERS} DIRECTORY)
#    include_directories(${HEADER_DIRECTORY})
#endforeach (HEADER_FILES)
#set(SOURCE_FILES src/main.cpp)

include_directories(src/ src/ecs src/EventManager)
add_executable(bomber ${SRCS})

#add_library(toto SHARED ${LIB_SRC})
