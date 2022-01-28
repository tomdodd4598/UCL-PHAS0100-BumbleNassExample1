add_library(ArgsLib STATIC args.cpp)
target_include_directories(ArgsLib PUBLIC ${IncludeDir})

add_library(CollectionsLib STATIC collections.cpp)
target_include_directories(CollectionsLib PUBLIC ${IncludeDir})

add_library(PointersLib STATIC pointers.cpp foo.cpp friends.cpp)
target_include_directories(PointersLib PUBLIC ${IncludeDir})

add_library(LambdasLib STATIC lambdas.cpp)
target_include_directories(LambdasLib PUBLIC ${IncludeDir})

add_library(ExceptionsLib STATIC exceptions.cpp)
target_include_directories(ExceptionsLib PUBLIC ${IncludeDir})

add_executable(BumbleNass main.cpp)
target_link_libraries(BumbleNass PRIVATE ArgsLib CollectionsLib PointersLib LambdasLib ExceptionsLib)
