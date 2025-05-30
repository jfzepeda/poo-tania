//
//  main.cpp
//  funciones
//
//  Created by Juan Felipe Zepeda on 20/05/25.
//

#include <iostream>
#include "SO.hpp"

template<typename T>
void print_one(const T& value) {
    std::cout << value << std::endl;
}

template<typename T, typename... Args>
void print(const T& first, const Args&... args) {
    std::cout << first;
    ((std::cout << " " << args), ...);
    std::cout << std::endl;
}

// int main(int argc, const char * argv[]) {
//     // insert code here...
//     int array[] = {3, 4, 6, 8, 4, 7, 2};
//     int size = sizeof(array)/sizeof(array[0]);
//     int promedio_val = promedio(array, size);
//     print("Promedio:", promedio_val);
//     return 0;
// }

int main() {
    // Calculadora calc;
    // print("Promedio de 2 enteros: " + to_string(calc.promedio(10, 20)));
    Calculadora Im1(3, 4), Im2 (5,6);
    Calculadora Im3 = Im1 + Im2;
    print("Promedio de 2 enteros: " + to_string(Im3.getReal()) + " + " + to_string(Im3.getImaginaria()) + "i");
    
    return 0;
}
