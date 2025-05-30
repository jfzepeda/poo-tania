#include <iostream>
using namespace std;

void apuntadores_enteros() {
    int Entero = 6;
    cout << "La direccion de memoria de Entero es: " << &Entero << endl;
    int* pointer=&Entero;
    cout << "Valor almacenado del apuntador: " << pointer << endl;
    cout << "Valor al que apunta: " << *pointer << endl;
    *pointer = 10; // Cambiando el valor al que apunta
    cout << "Valor al que apunta: " << *pointer << endl;
    cout << sizeof(pointer) << endl; // Tamaño del apuntador
}

void apuntadores_array() {
    int arr[] = {1, 2, 3, 4, 5};
    int* pointer_arr = arr; // Apuntador al primer elemento del array
    cout << "Direccion de memoria del primer elemento: " << pointer_arr << endl;
    cout << "Valor del apuntador: " << *pointer_arr << endl;
    
}
