set(Tests Test1 Test2 Test3)

foreach(test ${Tests})
    string(TOLOWER ${test} test_lower)
    add_executable(${test} main.cpp ${test_lower}.cpp)
    target_include_directories(${test} PUBLIC ${IncludeDir})
    target_include_directories(${test} PUBLIC ${TestDir})
    target_link_libraries(${test} PUBLIC ArithmeticLib FractionLib)
endforeach()

add_test(NAME Test1 COMMAND ${BinDir}/Test1)
add_test(NAME Test2 COMMAND ${BinDir}/Test2 380 264 696 444 4)
add_test(NAME Test3 COMMAND ${BinDir}/Test3 5240 648 8)
