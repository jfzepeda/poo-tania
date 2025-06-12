// === MAIN DE PRUEBA ===
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

bool escribirJson(int id, float calificacion) {
    try {
        json j;

        // Leer el archivo existente
        ifstream inFile("calificaciones.json");
        if (inFile.is_open()) {
            inFile >> j;
            inFile.close();
        }

        // Agregar la calificación al arreglo del ID
        string id_str = to_string(id);
        j[id_str].push_back(calificacion);

        // Sobrescribir el archivo
        ofstream outFile("calificaciones.json");
        if (!outFile.is_open()) {
            cout << "Error al abrir el archivo para escribir." << endl;
            return false;
        }
        outFile << j.dump(4);
        outFile.close();

        return true;
    } catch (const exception& e) {
        cerr << "Excepción al escribir en el archivo: " << e.what() << endl;
        return false;
    }
}


float leerJson(int id) {
    try {
        ifstream archivo("calificaciones.json");
        if (!archivo.is_open()) {
            cerr << "No se pudo abrir el archivo." << endl;
            return -1;
        }

        json j;
        archivo >> j;
        archivo.close();

        string key = to_string(id);
        if (!j.contains(key) || !j[key].is_array()) {
            cerr << "No hay calificaciones para el ID proporcionado." << endl;
            return -1;
        }

        float suma = 0;
        for (float cal : j[key]) {
            suma += cal;
        }

        float promedio = j[key].size() > 0 ? suma / j[key].size() : 0;
        return promedio;
    } catch (const exception& e) {
        cerr << "Excepción al leer el archivo: " << e.what() << endl;
        return -1;
    }
}

class Contenido {
protected:
    // ID, un nombre, una duración y un género 
    int id;
    string nombre;
    int duracion; 
    string genero;
    float calificacion; 

public: 
    Contenido(int _id, string _nombre, int _duracion, string _genero) {
        id = _id;
        nombre = _nombre;
        duracion = _duracion;
        genero = _genero;
        calificacion = leerJson(id);
    }

    void mostrar() {
        cout << "ID: " << id << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Duración: " << duracion << " minutos" << endl;
        cout << "Género: " << genero << endl;
        cout << "Calificación: " << calificacion << "/10" << endl;
    }

    void mostrarCalificacion(bool actualizado = false) {
        if (actualizado) {
            cout << "Calificación actualizada: " << calificacion << endl;
        }
        cout << "Calificación: " << calificacion << endl;
    }

    void calificar(float nuevaCalificacion) {
        if (nuevaCalificacion >= 0 && nuevaCalificacion <= 10) {
            escribirJson(id, nuevaCalificacion);
            calificacion = leerJson(id);
            mostrarCalificacion();
        } else {
            cout << "Calificación inválida. Debe estar entre 0 y 10." << endl;
        }
    }
};



int main() {
    Contenido contenido(1, "Película de Prueba", 120, "Acción");
    contenido.mostrar();
    float nuevaCalificacion;
    cout << "Ingrese una nueva calificación (0-10): ";
    cin >> nuevaCalificacion;
    contenido.calificar(nuevaCalificacion);
    return 0;
}