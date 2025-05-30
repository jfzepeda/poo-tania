//
//  SO.cpp
//  poo_codes_TC1030
//
//  Created by Juan Felipe Zepeda on 23/05/25.
//
#include <iostream>
#include <string>
#include "SO.hpp"

using namespace std;

Calculadora::Calculadora() {
    real = 0;
    imaginaria = 0;
}

Calculadora::Calculadora(int _real, int _imaginario) {
    real = _real;
    imaginaria = _imaginario;
}
float Calculadora::promedio(int a, int b) {
    return (a + b) / 2.0;
}
double Calculadora::promedio(double a, double b) {
    return (a + b) / 2.0;
}
float Calculadora::promedio(int a, int b, int c, int d) {
    return (a + b + c + d) / 4.0;
}
float Calculadora::promedio(int arr[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}
int Calculadora::getReal() {
    return real;
}
int Calculadora::getImaginaria() {
    return imaginaria;
}

Calculadora Calculadora::operator+(Calculadora Objeto2) {
    return Calculadora((real + Objeto2.real)/2, (imaginaria + Objeto2.imaginaria)/2);
}
