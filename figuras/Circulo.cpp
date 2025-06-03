//
//  Circulo.cpp
//  poo_codes_TC1030
//
//  Created by Juan Felipe Zepeda on 20/05/25.
//

#include "Shape.hpp"
#include "Circulo.hpp"
// MARK: - Circulo
Circulo::Circulo(int X, int Y, int R):Shape(X, Y) {
    r = R;
}

string Circulo::draw() {
    return "soy un circulo";
}
