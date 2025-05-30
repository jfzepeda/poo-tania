//
//  SO.cpp
//  poo_codes_TC1030
//
//  Created by Juan Felipe Zepeda on 23/05/25.
//
#ifndef Vector_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Vector{
private: 
    int x,y;
public:
    Vector();
    Vector(int, int);
    Vector operator+(Vector);
    bool operator==(Vector);
    int operator*(Vector);
    Vector operator*(int);


};

#endif /* Vector_hpp */