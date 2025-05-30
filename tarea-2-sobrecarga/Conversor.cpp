//
//  Conversor.cpp
//  poo_codes_TC1030
//
//  Created by Juan Felipe Zepeda on 16/05/25.
//

// La clase Conversor proporciona métodos sobrecargados para convertir entre diferentes unidades: temperatura, longitud y tiempo.

#include "Conversor.hpp"

// MARK: - Conversor
// Convierte grados Celsius a grados Fahrenheit.
float Conversor:: convertir(float gradosCelsius) {
    return (gradosCelsius * 9.0 / 5.0) + 32.0; // Celsius a Fahrenheit
};
// Convierte metros a centímetros.
int Conversor::convertir(int metros) {
    return metros * 100; // Metros a Centímetros
};
// Convierte horas a minutos o segundos dependiendo del valor de 'tipo'.
// Si tipo == 1, convierte a minutos. De lo contrario, convierte a segundos.
float Conversor::convertir(float horas, int tipo) {
    if (tipo == 1) {
        return horas * 60;
    } else {
        return horas * 3600;
    } 
};
