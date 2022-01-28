cmake_minimum_required(VERSION 3.5)

set(MyProject BumbleNassExample1)
project(MyProject)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()

set(IncludeDir ${MyProject_SOURCE_DIR}/include)
set(TestDir ${MyProject_SOURCE_DIR}/test)

set(BinDir ${CMAKE_BINARY_DIR}/bin)
set(LibDir ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LibDir})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LibDir})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BinDir})

add_subdirectory(src)
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(test)
endif()
