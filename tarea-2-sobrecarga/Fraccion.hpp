//
//  Shape.hpp
//  poo_codes_TC1030
//
//  Created by Juan Felipe Zepeda on 16/05/25.
//

#ifndef Fraccion_hpp

#include <stdio.h>

#include <iostream>
#include <string>
using namespace std;

// MARK: - Clase padre Shape
class Fraccion {
private:
    int numerador, denominador;
public:
    Fraccion(int, int);
    Fraccion operator+(Fraccion);
    Fraccion operator*(Fraccion);
    Fraccion operator/(Fraccion);
    void print();
};

#endif /* Fraccion_hpp */
