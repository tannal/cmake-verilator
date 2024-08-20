cmake_minimum_required(VERSION 3.15)
project(AluTopProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(verilator REQUIRED)
set(VERILATOR_INCLUDE_DIR ${VERILATOR_ROOT}/include)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(rtl)
add_subdirectory(tests)