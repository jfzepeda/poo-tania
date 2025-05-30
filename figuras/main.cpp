//
//  main.cpp
//  figuras
//
//  Created by Juan Felipe Zepeda on 16/05/25.
//

#include <iostream>
#include "Shape.cpp"
#include "Circulo.hpp"
#include "Rectangulo.hpp"
#include "Poligono.hpp"

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

int main(int argc, const char * argv[]) {
    
    Shape Figura1(4,5);
    Circulo C1(7,7,2);
    Rectangulo R1(1, 1, 2, 4);
    Poligono P1(2, 3, 6, 4, 3);
    
//    print(Figura1.draw());
//    print(C1.draw());
    
    print(C1.draw(), "Con cordenadas X =", C1.getX(), "y Y =", C1.getY());
    print(R1.draw(), "Con area", R1.getArea());
    print(P1.draw(), "Con", P1.getLados(), "lados y area",  P1.getArea());
}
