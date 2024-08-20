

# CMake verilator Verilog

Verilog CMake 集成 verilator测试

## 构建

```bash
sudo apt-get install verilator
```

```bash
cmake -G Ninja -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE='Debug'
ninja -C build
```

## 其他

- 使用 SystemVerilog 和 UVM (Universal Verification Methodology) 创建更复杂的测试平台。
- 使用 Synopsys VCS、Cadence Xcelium 或 Mentor Graphics Questa 进行仿真。
- 形式验证: 使用工具如 Cadence JasperGold 或 Synopsys VC Formal 进行形式属性验证。
- 仿真覆盖率分析: 使用仿真工具的内置覆盖率分析功能。确保代码覆盖率达到预定目标 (通常 > 95%)。
- 电路合成: 使用 Synopsys Design Compiler 或 Cadence Genus 进行逻辑合成。检查合成报告，确保没有时序违例。
- 门级仿真: 对合成后的网表进行仿真，确保功能正确性。
- 静态时序分析: 使用 Synopsys PrimeTime 或 Cadence Tempus 进行静态时序分析。
- 功耗分析: 使用 Synopsys PrimeTime PX 或 Cadence Voltus 进行功耗估算。
- 物理设计和版图: 使用 Cadence Innovus 或 Synopsys IC Compiler 进行布局布线。
- 签核检查: 使用 Mentor Calibre 或 Synopsys IC Validator 进行 DRC 和 LVS 检查。
- 后仿真验证: 对最终版图提取的网表进行仿真，确保功能正确性。
- FPGA 原型验证 (可选): 使用 Xilinx Vivado 或 Intel Quartus 将设计映射到 FPGA 进行原型验证。
- 芯片流片前最终审核: 多个团队 (设计、验证、物理设计等) 进行最终审核。
- 持续集成/持续部署 (CI/CD): 使用 Jenkins 或 GitLab CI 设置自动化测试流程。
- 版本控制和文档: 使用 Git 进行版本控制。

