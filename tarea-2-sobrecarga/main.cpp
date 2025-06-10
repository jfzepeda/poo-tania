//
//  main.cpp
//  tarea-2-sobrecarga}
//
//  Created by Juan Felipe Zepeda on 25/05/25.
//

#include <iostream>
#include "Conversor.hpp"
#include "Texto.hpp"
#include "Tiempo.hpp"
#include "Fraccion.hpp"
#include <string>
using namespace std;

int main() {
    // -------------------------------
    // Sección de pruebas para la clase Conversor
    // Realiza conversiones de temperatura, longitud y tiempo
    // -------------------------------
    // Conversor
    Conversor conversor;
        float temperatura;
        cout << "Ingrese n Celsius: ";
        cin >> temperatura;
        cout << "Celsius a Fahrenheit: " << conversor.convertir(temperatura) << "°F" << endl;

        int metros;
        cout << "Ingrese metros: ";
        cin >> metros;
        cout << "Metros a centimetros: " << conversor.convertir(metros) << " cm" << endl;

        float horas;
        cout << "Ingrese horas: ";
        int tipo;
        cin >> horas;
        cout << "tipo de conversión (1: horas a minutos, 2: horas a segundos): ";
        cin >> tipo;
        if (tipo == 1) {
            cout << "Horas a minutos: " << conversor.convertir(horas, tipo) << " minutos" << endl;
        } else if (tipo == 2) {
            cout << "Horas a segundos: " << conversor.convertir(horas, tipo) << " segundos" << endl;
        } else {
            cout << "Tipo no válido" << endl;
        }
    
    // -------------------------------
    // Sección de pruebas para la clase Texto
    // Formatea cadenas: mayúsculas, concatenación y repetición
    // -------------------------------
    // Texto
    Texto texto;
        string cadena;
        cout << "Ingrese un texto: ";
        cin >> cadena;
        cout << "Texto en mayusculas: " << texto.formatear(cadena) << endl;

        string cadena_2;
        cout << "Ingrese otro texto para concatenar: ";
        cin >> cadena_2;
        cout << "Texto concatenado: " << texto.formatear(cadena, cadena_2) << endl;

        int n;
        cout << "Ingrese un número para repetir el texto: ";
        cin >> n;
        cout << "Texto repetido: " << texto.formatear(cadena, n) << endl;
    

    // Salto de linea
    cout << endl;
    cout << "------------------------" << endl;
    cout << endl;
    // -------------------------------
    // Sección de pruebas para la clase Fraccion
    // Opera fracciones: suma, multiplicación y división
    // -------------------------------
    // Fraccion
    Fraccion fraccion1(5, 6);
        cout << "Fracción 1: " << endl;
        fraccion1.print();
        
        Fraccion fraccion2(1, 2);
        cout << "Fracción 2: " << endl;
        fraccion2.print();
        
        Fraccion resultadoFraccion = fraccion1 + fraccion2;
        cout << "Suma de fracciones: " << endl;
        resultadoFraccion.print();

        Fraccion resultadoMultiplicacion = fraccion1 * fraccion2;
        cout << "Multiplicación de fracciones: " << endl;
        resultadoMultiplicacion.print();

        Fraccion resultadoDivision = fraccion1 / fraccion2;
        cout << "División de fracciones: " << endl;
        resultadoDivision.print();

    // -------------------------------
    // Sección de pruebas para la clase Tiempo
    // Suma tiempos y verifica si son iguales
    // -------------------------------
    // Tiempo
    Tiempo tiempo(2, 15, 50);
        cout << "Tiempo inicial: ";
        tiempo.print();
        
        Tiempo tiempo2(1, 20, 20);
        cout << "Tiempo a sumar: ";
        tiempo2.print();
        
        Tiempo resultado = tiempo + tiempo2;
        cout << "Resultado de la suma: ";
        resultado.print();

        if (tiempo == tiempo2) {
            cout << "Los tiempos son iguales." << endl;
        } else {
            cout << "Los tiempos son diferentes." << endl;
        }

    return 0;
}
