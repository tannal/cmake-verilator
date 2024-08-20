add_executable(alu_app main.cpp)
target_link_libraries(alu_app PRIVATE alu_rtl)
target_include_directories(alu_app PRIVATE 
    ${CMAKE_BINARY_DIR}/rtl
    ${CMAKE_BINARY_DIR}/rtl/CMakeFiles/alu_rtl.dir/VAlu.dir
    ${VERILATOR_INCLUDE_DIR}
)