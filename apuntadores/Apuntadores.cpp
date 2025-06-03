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
    cout << endl << endl;
}

void apuntadores_array() {
    int arr[] = {1, 2, 3, 4, 5};
    int* pointer_arr = arr; // Apuntador al primer elemento del array
    cout << "Direccion de memoria del primer elemento: " << pointer_arr << endl;
    cout << "Valor del apuntador: " << *pointer_arr << endl;
    cout << endl << endl;
}

void Funcion1(int* A){
    cout << "Dirección de memoria de A en Función: " << A << endl;
    cout << "Valor de A: " << *A << endl;
}

void apuntadores_funciones(){
    int A = 4;
    cout << "Dirección de memoria de A en main: " << &A << endl;
    Funcion1(&A);
    cout << "Despues de la funcion es: " << A << endl;
    cout << endl << endl;
}

void Cambio(int* a, int* b) {
    int temp = *b; // Guardar la dirección de 'a' en 'temp'
    *b = *a; // Asignar el valor de 'a' a 'b'
    *a = temp; // Asignar el valor de 'temp' (que es 'a') a 'a'
}

void apuntadores_cambio() {
    int a=97, b=75;
    cout << "Valor de a: " << a << endl;
    cout << "Valor de b: " << b << endl;
    
    Cambio(&a, &b);
    cout << "Valor de a después: " << a << endl;
    cout << "Valor de b después: " << b << endl;
};