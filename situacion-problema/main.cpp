// === MAIN DE PRUEBA ===
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

// Librería de uso y documentacion de los JSON obtenida del 
// repositorio -> https://github.com/nlohmann/json

bool escribirJson(int id, float calificacion) {
    try {
        json j;

        // Leer el archivo existente
        ifstream inFile("calificaciones.json");
        if (inFile.is_open()) {
            // Sólo parsear si el archivo no está vacío
            if (inFile.peek() != std::ifstream::traits_type::eof()) {
                inFile >> j;
            }
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
        // Si el archivo está vacío, no hay calificaciones aún
        if (archivo.peek() == std::ifstream::traits_type::eof()) {
            archivo.close();
            return 0;
        }

        json j;
        try {
            archivo >> j;
        } catch (const json::parse_error& e) {
            cerr << "Error al parsear JSON: " << e.what() << endl;
            archivo.close();
            return 0;
        }
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

void print(string s) {
    cout << s << endl;
}

class Contenido {
private:
    float calificacion; 
protected:
    int id;
    string nombre;
    int duracion; 
    string genero;

public: 
    Contenido(int _id, string _nombre, int _duracion, string _genero) {
        id = _id;
        nombre = _nombre;
        duracion = _duracion;
        genero = _genero;
        calificacion = leerJson(id);
    }

    void virtual mostrar() const = 0;

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

class Pelicula : public Contenido {
public:
    Pelicula(int _id, string _nombre, int _duracion, string _genero)
        : Contenido(_id, _nombre, _duracion, _genero) {
    }

    void mostrar() const override {
        cout << "\nPelícula: " << nombre << endl;
        cout << "Duración: " << duracion << " minutos" << endl;
        cout << "Género: " << genero << endl;
        cout << "ID: " << id << endl;
    }
};

class Episodio {
protected:
    string titulo;
    int temporada;

public:
    Episodio(string _titulo, int _temporada) {
        titulo = _titulo;
        temporada = _temporada;
    }

    void imprimir() {
        cout << "T-" << temporada << " : " << titulo << endl;
    }
};

class Serie : public Contenido {
protected:
    Episodio* episodios[12]; // Suponiendo un máximo de 10 episodios
    int n = 0;

public:
    Serie(int _id, string _nombre, int _duracion, string _genero)
        : Contenido(_id, _nombre, _duracion, _genero) {
    }

    int calcularTemporada() {
        return n / (n - (n%4));
    };

    void agregarEpisodio(string _titulo) {
        if (n < 12) {
            episodios[n] = new Episodio(_titulo, calcularTemporada());
            n++;
        } else {
            cout << "No se pueden agregar más episodios." << endl;
        }
    }

    void mostrar() const override {
        print("\nSerie (" + to_string(id) + ") :" + nombre);
        cout << "Duración: " << (duracion * n) << " minutos" << endl;
        cout << "Género: " << genero << endl;
    }
};



int main() {
    Pelicula peli1(1, "Película de Prueba", 120, "Acción");
    peli1.mostrarCalificacion();
    float nuevaCalificacion;
    cout << "Ingrese una nueva calificación (0-10): ";
    cin >> nuevaCalificacion;
    peli1.calificar(nuevaCalificacion);
    
    Serie serie1(2, "Serie de Prueba", 40, "Drama");
    serie1.mostrar();
    float nuevaCalificacion;
    cout << "Ingrese una nueva calificación (0-10): ";
    cin >> nuevaCalificacion;
    serie1.calificar(nuevaCalificacion);
    return 0;
}