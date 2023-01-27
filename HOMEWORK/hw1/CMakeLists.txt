cmake_minimum_required(VERSION 3.10)
project(example1)
add_executable(success q1.1.cpp)
add_executable(failed q1.2.cpp)
# set C++ standard
set_target_properties(
success failed
PROPERTIES
CXX_STANDARD 17
CXX_STANDARD_REQUIRED YES
CXX_EXTENSIONS NO)
# add more warning to the compiler options
if (MSVC)
target_compile_options(success PRIVATE /Wall /WX)
target_compile_options(failed PRIVATE /Wall /WX)
else()
target_compile_options(success PRIVATE -Wall -Wextra)
target_compile_options(failed PRIVATE -Wall -Wextra)
endif()
set(TARGETS success failed)
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