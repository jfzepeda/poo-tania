//
//  Shape.hpp
//  poo_codes_TC1030
//
//  Created by Juan Felipe Zepeda on 16/05/25.
//

#ifndef Conversor_hpp

#include <stdio.h>

#include <iostream>
#include <string>
using namespace std;

// MARK: - Clase padre Shape
class Conversor {
private:
    
public:
    float convertir(float gradosCelsius);
    int convertir(int metros);
    float convertir(float horas, int tipo);
};

#endif /* Conversor_hpp */
