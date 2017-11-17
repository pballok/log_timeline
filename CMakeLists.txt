cmake_minimum_required(VERSION 3.6)

project(LogTimeline)

include(ExternalProject)
find_package(Git REQUIRED)

set(CMAKE_CXX_FLAGS "-std=c++1z -Wall -Wextra -Werror")

if(ENABLE_ASAN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=gold")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")
endif()

list(APPEND ASTYLE_ARGS
    --style=1tbs
    --lineend=linux
    --suffix=none
    --pad-oper
    --unpad-paren
    --break-closing-brackets
    --align-pointer=type
    --align-reference=type
    --indent-preproc-define
    --indent-switches
    --indent-col1-comments
    --keep-one-line-statements
    --keep-one-line-blocks
    --pad-header
    --convert-tabs
    --min-conditional-indent=0
    --indent=spaces=2
    --close-templates
    --add-brackets
    --break-after-logical
)

add_custom_target(
    format
    COMMAND astyle ${ASTYLE_ARGS} ${CMAKE_SOURCE_DIR}/include/*.h ${CMAKE_SOURCE_DIR}/src/*.cpp ${CMAKE_SOURCE_DIR}/tests/*.cpp
    COMMENT "running astyle"
)

if(NOT ENABLE_ASAN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()

enable_testing()

add_subdirectory(tests)
