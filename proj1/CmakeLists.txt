cmake_minimum_required(VERSION 3.10) 
project(project1) 
add_executable(hello hello.cpp) 

# directory wide options for compiler warnings 
if (MSVC) 
    add_compile_options(/Wall /WX) 
else() 
    add_compile_options(-Wall -Wextra) 
endif() 

# select C++ standard and extensions 
set_target_properties( 
    hello 
    PROPERTIES 
    CXX_STANDARD 17 
    CXX_STANDARD_REQUIRED YES 
    CXX_EXTENSIONS NO) 
