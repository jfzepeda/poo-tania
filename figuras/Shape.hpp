//
//  Shape.hpp
//  poo_codes_TC1030
//
//  Created by Juan Felipe Zepeda on 16/05/25.
//

#ifndef Shape_hpp

#include <stdio.h>

#include <iostream>
#include <string>
using namespace std;

// MARK: - Clase padre Shape
class Shape {
private:
    int x;
    int y;
    
public:
    virtual string draw();
    Shape(int, int);
    int getX();
    int getY();
};

#endif /* Shape_hpp */
