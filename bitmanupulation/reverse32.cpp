#include <iostream>

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; ++i) {
        // Extract the least significant bit
        uint32_t bit = n & 1;
        // Shift the result to the left and add the extracted bit
        result = (result << 1) | bit;
        // Shift the input number to the right
        n >>= 1;
    }
    return result;
}

int main() {
    uint32_t n = 43261596;  // Example input
    uint32_t reversed = reverseBits(n);
    std::cout << "Original: " << n << std::endl;
    std::cout << "Reversed: " << reversed << std::endl;
    return 0;
}
