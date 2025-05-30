//
//  Shape.cpp
//  poo_codes_TC1030
//
//  Created by Juan Felipe Zepeda on 16/05/25.
//

#include "Shape.hpp"

// MARK: - Shape
Shape::Shape(int X, int Y) {
    x = X;
    y = Y;
};

string Shape::draw() {
    return "Soy una figura";
};

int Shape::getX() {
    return x;
};

int Shape::getY() {
    return y;
};
