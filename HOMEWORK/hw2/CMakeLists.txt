cmake_minimum_required(VERSION 3.10)
project(example1)
add_executable(q2.1 q2.1.cpp)
add_executable(q2.2 q2.2.cpp)
# set C++ standard
set_target_properties(
    q2.1
    q2.2
    PROPERTIES
CXX_STANDARD 17
CXX_STANDARD_REQUIRED YES
CXX_EXTENSIONS NO)
# add more warning to the compiler options
if (MSVC)
target_compile_options(q2.1 PRIVATE /Wall /WX)
target_compile_options(q2.2 PRIVATE /Wall /WX)
else()
target_compile_options(q2.1 PRIVATE -Wall -Wextra)
target_compile_options(q2.2 PRIVATE -Wall -Wextra)
endif()
set(TARGETS q2.1)
set(TARGETS q2.2)
set_target_properties(
${TARGETS}
PROPERTIES
CXX_STANDARD 17
CXX_STANDARD_REQUIRED YES
CXX_EXTENSIONS NO)
foreach(T ${TARGETS})
if (MSVC)
target_compile_options(${T} PRIVATE /Wall /WX)
else()
target_compile_options(${T} PRIVATE -Wall -Wextra)
endif()
endforeach()