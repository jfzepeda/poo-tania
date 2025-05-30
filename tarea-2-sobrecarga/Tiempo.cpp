//
//  Tiempo.cpp
//  poo_codes_TC1030
//
//  Created by Juan Felipe Zepeda on 16/05/25.
//

#include "Tiempo.hpp"

// Formatea las horas, minutos y segundos de un objeto Tiempo
void Tiempo::formatear() {
    int total = horas * 3600 + minutos * 60 + segundos;
    horas = total / 3600;
    minutos = (total % 3600) / 60;
    segundos= total % 60;
};

// Crear objeto
Tiempo::Tiempo(int h, int m, int s) {
    horas = h;    
    minutos = m;
    segundos = s;
    formatear();
};

// Sobrecarga del operador suma para sumar dos objetos Tiempo
Tiempo Tiempo::operator+(Tiempo time) {
    time.horas += horas;
    time.minutos += minutos;
    time.segundos += segundos;
    time.formatear();
    return time;
};

// Sobrecarga del operador resta para restar dos objetos Tiempo
bool Tiempo::operator==(Tiempo time) {
    formatear();
    time.formatear();
    if (horas == time.horas && minutos == time.minutos && segundos == time.segundos) {
        return true;
    } else {
        return false;
    }
};