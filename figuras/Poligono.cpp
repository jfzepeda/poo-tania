//
//  Poligono.cpp
//  poo_codes_TC1030
//
//  Created by Juan Felipe Zepeda on 20/05/25.
//
#include "Shape.hpp"
#include "Poligono.hpp"

// MARK: - Poligono
Poligono::Poligono(int X, int Y, int L, int B, int A):Shape(X, Y) {
    l = L;
    b = B;
    a = A;
};

int Poligono::getLados() {
    return l;
};

int Poligono::getArea() {
    return l*b*a/2;
};

string Poligono::draw() {
    return "soy un poligono";
}
