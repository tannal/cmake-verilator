add_library(alu_rtl STATIC)

verilate(alu_rtl
  SOURCES Alu.v  # 注意：这里应该是你的 Verilog 文件名
  TRACE
  TOP_MODULE Alu  # 确保这里是你的顶层模块名
  VERILATOR_ARGS -Wall
)

target_include_directories(alu_rtl PUBLIC 
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/alu_rtl.dir/VAlu.dir
    ${VERILATOR_INCLUDE_DIR}
)