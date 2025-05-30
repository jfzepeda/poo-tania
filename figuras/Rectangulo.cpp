//
//  Rectangle.cpp
//  poo_codes_TC1030
//
//  Created by Juan Felipe Zepeda on 20/05/25.
//

#include "Shape.hpp"
#include "Rectangulo.hpp"
// MARK: - Rectangulo
Rectangulo::Rectangulo(int X, int Y, int B, int H):Shape(X, Y) {
    b = B;
    h = H;
};

int Rectangulo::getArea() {
    return b*h;
};
