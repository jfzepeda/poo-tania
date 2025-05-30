//
//  Shape.hpp
//  poo_codes_TC1030
//
//  Created by Juan Felipe Zepeda on 16/05/25.
//

#ifndef Tiempo_hpp

#include <stdio.h>

#include <iostream>
#include <string>
using namespace std;

// MARK: - Clase padre Shape
class Tiempo {
private:
    int horas, minutos, segundos;
public:
    Tiempo(int, int, int);
    void formatear();
    Tiempo operator+(Tiempo);
    bool operator==(Tiempo);
    void print() {
        cout << horas << " horas, " << minutos << " minutos, " << segundos << " segundos" << endl;
    }
};

#endif /* Tiempo_hpp */