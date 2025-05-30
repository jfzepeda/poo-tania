//
//  Fraccion.cpp
//  poo_codes_TC1030
//
//  Created by Juan Felipe Zepeda on 16/05/25.
//

#include "Fraccion.hpp"

// MARK: - Fraccion
// Constructor que inicializa una fracción con numerador y denominador dados
Fraccion::Fraccion(int num, int den) {
    numerador = num;
    denominador = den;
};

// Sobrecarga del operador suma: suma dos fracciones y regresa el resultado como una nueva fracción
Fraccion Fraccion::operator+(Fraccion frac) {
    return Fraccion(frac.numerador*denominador + numerador*frac.denominador, frac.denominador*denominador);
};
// Sobrecarga del operador multiplicación: multiplica dos fracciones y regresa el resultado
Fraccion Fraccion::operator*(Fraccion frac) {
    return Fraccion(frac.numerador*numerador, frac.denominador*denominador);
};
// Sobrecarga del operador división: divide esta fracción entre otra y regresa el resultado
Fraccion Fraccion::operator/(Fraccion frac) {
    return Fraccion(frac.denominador*numerador, frac.numerador*denominador);
};
// Imprime la fracción en formato "numerador/denominador"
void Fraccion::print() {
    cout << numerador << "/" << denominador << endl;
};