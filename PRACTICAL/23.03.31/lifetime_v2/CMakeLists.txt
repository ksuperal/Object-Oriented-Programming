cmake_minimum_required(VERSION 3.10)

project(lifetime_v2)

find_package(fmt CONFIG REQUIRED)

add_executable(test_lifetime lifetime.cpp)

target_link_libraries(test_lifetime PRIVATE fmt::fmt-header-only)

set(TARGETS test_lifetime)

set_target_properties(
    ${TARGETS}
    PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO)

foreach(T ${TARGETS})
    if (MSVC)
        target_compile_options(${T} PRIVATE /Wall /WX)
    else()
        target_compile_options(${T} PRIVATE -Wall -Wextra)
    endif()
endforeach()