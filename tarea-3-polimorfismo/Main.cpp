// === MAIN DE PRUEBA ===
#include <iostream>
#include "Envio.cpp"
#include "Empleado.cpp"
#include "Punto.cpp"
using namespace std;
    
int main() {
    // Ej1
    Paquete paq("Alice", "Calle 1", "CDMX", "CDMX", "01000", 
                "Bob", "Av.2", "Puebla", "PUE", "72000", 
                40, 30, 20, 2.5, 80);
    Sobre env("Alice", "Calle 1", "CDMX", "CDMX", "01000", 
              "Bob", "Av.2", "Puebla", "PUE", "72000", 
              30, 26, 10);

    cout << "Costo paquete: " << paq.calculaCosto() << endl;
    cout << "Costo sobre:   " << env.calculaCosto() << endl;

    // Ej2
    EmpleadoBase    e1(30000, "Laura", 35);
    EmpleadoPorHora e2(160, 180, "Carlos", 22);
    EmpleadoPorComision e3(10000, 0.05, "Sofia", 27);

    cout << "Laura < Sofia? " << (e1 < e3) << endl;

    // Ej3
    Punto2D p2a(2, 3), p2b(5, 7);
    cout << "Dist 2D: " << p2a.distancia(p2b) << endl;

    Punto3D p3a(1, 2, 3), p3b(4, 5, 6);
    cout << "Dist 3D: " << p3a.distancia(p3b) << endl;

    Punto3D suma = p3a + p3b;
    cout << "Suma 3D: (" << suma.getX() << ", " << suma.getY() << ", " << suma.getZ() << ")" << endl;

    return 0;
}