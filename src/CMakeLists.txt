add_library(ArithmeticLib STATIC arithmetic.cpp)
target_include_directories(ArithmeticLib PRIVATE ${IncludeDir})

add_library(SupaLib STATIC supa.cpp)
target_include_directories(SupaLib PUBLIC ${IncludeDir})
target_link_libraries(SupaLib PUBLIC ArithmeticLib)

add_library(FractionLib STATIC factors.cpp fraction.cpp)
target_include_directories(FractionLib PUBLIC ${IncludeDir})

add_executable(SupaMega main.cpp)
target_link_libraries(SupaMega PRIVATE SupaLib FractionLib)
