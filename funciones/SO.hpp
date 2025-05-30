//
//  SO.h
//  poo_codes_TC1030
//
//  Created by Juan Felipe Zepeda on 23/05/25.
//
#ifndef SO_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Calculadora {
private:
    int real, imaginaria;

public:
    Calculadora();
    Calculadora(int, int);
    float promedio(int, int);
    double promedio(double, double);
    float promedio(int, int, int, int);
    float promedio(int[], int);
    int getReal();
    int getImaginaria();
    Calculadora operator+(Calculadora);
};
#endif /* Shape_hpp */
