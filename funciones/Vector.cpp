#include <iostream>
#include <string>
#include "Vector.hpp"

Vector::Vector() {
    x = 0;
    y = 0;
}

Vector::Vector(int _x, int _y) {
    x = _x;
    y = _y;
}

Vector Vector::operator+(Vector Objeto2) {
    return Vector(x + Objeto2.x, y + Objeto2.y);
}

bool Vector::operator==(Vector Objeto2) {
    return (x == Objeto2.x && y == Objeto2.y);
}

using namespace std;