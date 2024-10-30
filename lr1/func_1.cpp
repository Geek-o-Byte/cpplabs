#include <iostream>
#include <cmath>
int main() {
    int var1 = 2;
    int var2 = 2;
    std::cout << "===========================================" << std::endl;
    std::cout << "var1 (int): " << var1 << std::endl;
    std::cout << "var2 (int): " << var2 << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << "Result (int + int): " << (var1 + var2) << std::endl;
    std::cout << "Result (int - int): " << (var1 - var2) << std::endl;
    std::cout << "Result (int * int): " << (var1 * var2) << std::endl;
    if (var2 != 0) { std::cout << "Result (int / int): " << (var1 / var2) << std::endl; } else { std::cout << "Error: Division by zero!" << std::endl; }
    if (var2 != 0) { std::cout << "Result (int // int): " << (var1 / var2) << std::endl; } else { std::cout << "Error: Division by zero!" << std::endl; }
    if (var2 != 0) { std::cout << "Result (int % int): " << (var1 % var2) << std::endl; } else { std::cout << "Error: Division by zero!" << std::endl; }
    std::cout << "Result (int ** int): " << pow(var1, var2) << std::endl;
    std::cout << "Warning: Unsupported operation '&' skipped." << std::endl;
    std::cout << "===========================================" << std::endl;
    return 0;
}
