//
//  Texto.cpp
//  poo_codes_TC1030
//
//  Created by Juan Felipe Zepeda on 16/05/25.
//

#include "Texto.hpp"

// Función auxiliar que convierte una cadena a mayúsculas
string upper(string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str; // Retorna la cadena convertida a mayúsculas
}

// MARK: - Texto
// Método que convierte un texto a mayúsculas
string Texto::formatear(string textoMinusculas) {
    return upper(textoMinusculas); // Llama a la función upper para hacer la conversión
};

// Método que concatena dos textos con un espacio entre ellos
string Texto::formatear(string texto_1, string texto_2) {
    return texto_1 + " " + texto_2; // Retorna la concatenación
};

// Método que repite un texto 'times' veces, separado por espacios
string Texto::formatear(string texto, int times) {
    string result;
    for (int i = 0; i < times; i++) {
        result += " " + texto; // Agrega el texto a la cadena resultado
    }
    return result; // Retorna el resultado final
};