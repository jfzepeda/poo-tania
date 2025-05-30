//
//  Shape.hpp
//  poo_codes_TC1030
//
//  Created by Juan Felipe Zepeda on 16/05/25.
//

#ifndef Texto_hpp

#include <stdio.h>

#include <iostream>
#include <string>
using namespace std;

// MARK: - Clase padre Shape
class Texto {
private:
    
public:
    string formatear(string);
    string formatear(string, string);
    string formatear(string, int);
};

#endif /* Texto_hpp */
