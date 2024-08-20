#include "VAlu.h"
#include "verilated.h"
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    VAlu* top = new VAlu;
    
    std::vector<std::pair<uint16_t, uint16_t>> testCases = {
        {0b0000001100, 0b0000000011}, // 加法: 1 + 2 = 3
        {0b0100011001, 0b0000000010}, // 减法: 3 - 1 = 2
        {0b1000101110, 0b0000000111}, // 或运算: 5 | 6 = 7
        {0b1100101110, 0b0000000100}  // 与运算: 5 & 6 = 4
    };
    
    for (const auto& [input, expected] : testCases) {
        top->io_a = input;
        top->eval();
        
        if (top->io_b != expected) {
            std::cout << "Test failed! Input: " << input 
                      << ", Expected: " << expected 
                      << ", Got: " << top->io_result << std::endl;
        } else {
            std::cout << "Test passed! Input: " << input 
                      << ", Output: " << top->io_result << std::endl;
        }
    }
    
    delete top;
    return 0;
}