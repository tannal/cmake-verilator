#include "VAlu.h"
#include "verilated.h"
#include <iostream>
#include <vector>
#include <iomanip>

void printBinary(uint8_t value) {
    for (int i = 3; i >= 0; i--) {
        std::cout << ((value >> i) & 1);
    }
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    VAlu* top = new VAlu;
    
    std::vector<std::pair<std::pair<uint8_t, uint8_t>, uint8_t>> testCases = {
        {{0, 0}, 0},    // 0 + 0 = 0
        {{1, 2}, 3},    // 1 + 2 = 3
        {{7, 8}, 15},   // 7 + 8 = 15 (最大值)
        {{15, 1}, 0},   // 15 + 1 = 0 (溢出)
        {{10, 5}, 15},  // 10 + 5 = 15
        {{3, 3}, 6},    // 3 + 3 = 6
        {{12, 4}, 0}    // 12 + 4 = 0 (溢出)
    };
    
    for (const auto& test : testCases) {
        top->io_a = test.first.first;
        top->io_b = test.first.second;
        top->eval();
        
        uint8_t expected = test.second;
        uint8_t result = top->io_result;
        
        std::cout << "Test case: ";
        printBinary(top->io_a);
        std::cout << " + ";
        printBinary(top->io_b);
        std::cout << " = ";
        printBinary(result);
        std::cout << " (Expected: ";
        printBinary(expected);
        std::cout << ") ";
        
        if (result == expected) {
            std::cout << "PASSED";
        } else {
            std::cout << "FAILED";
        }
        std::cout << std::endl;
    }
    
    delete top;
    return 0;
}