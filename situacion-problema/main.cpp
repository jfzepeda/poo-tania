// === MAIN DE PRUEBA ===
#include <iostream>
#include <cstdlib>  
#include <fstream>
#include <string>
#include "libs/json.hpp"
using namespace std;
using json = nlohmann::json;

// Librería de uso y documentacion de los JSON obtenida del 
// repositorio -> https://github.com/nlohmann/json

#include <cstdlib>   // para std::system
#include <iostream>

void print(string s) {
    cout << s << endl;
}

int reproducirVideo(int id) {
    print("\nQuieres ver la pelicula?  SI / NO");
    string respuesta;
    cin >> respuesta;
    if (respuesta != "SI" && respuesta != "si") {
        cout << "OK" << endl;
        return 0;
    }

    // Verifica que el ID sea válido
    if (id < 1 || id > 2) {
        cerr << "ID de vídeo inválido. Por ahora solo se acepta 1 y 2\n";
        return 1;
    }
    // Ruta absoluta o relativa al vídeo
    std::string ruta = "assets/pelicula_" + to_string(id) + ".mov";

    // Construye el comando: open "ruta"
    std::string cmd = std::string("open \"") + ruta + "\"";

    // Lanza el comando
    int res = std::system(cmd.c_str());
    // Teclear la barra espaciadora cuando se abra el vídeo
    std::system("osascript -e 'tell application \"System Events\" to keystroke space'");

    if (res != 0) {
        std::cerr << "Error al abrir el vídeo (código " << res << ")\n";
        return 1;
    }

    return 0;
}

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

float leerJson(int id, bool firstGet = false) {
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
        if ( (!j.contains(key) || !j[key].is_array()) && !firstGet){
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
        calificacion = leerJson(id, true);
    }

    void virtual mostrarDetalle() const = 0;
    void virtual mostrarNombre() const = 0;

    void mostrarCalificacion(bool actualizado = false) {
        if (actualizado) {
            cout << "Calificación actualizada: " << calificacion << endl;
        }
        cout << "Calificación media: " << calificacion << endl;
    }

    void calificar(float nuevaCalificacion) {
        if (nuevaCalificacion >= 0 && nuevaCalificacion <= 5) {
            escribirJson(id, nuevaCalificacion);
            calificacion = leerJson(id);
            mostrarCalificacion();
        } else {
            cout << "Calificación inválida. Debe estar entre 0 y 10." << endl;
        }
    }

    int getId() const {
        return id;
    }
};

class Pelicula : public Contenido {
public:
    Pelicula(int _id, string _nombre, int _duracion, string _genero)
        : Contenido(_id, _nombre, _duracion, _genero) {
    }

    void mostrarDetalle() const override {
        cout << "\nPelícula: " << nombre << endl;
        cout << "Duración: " << duracion << " minutos" << endl;
        cout << "Género: " << genero << endl;
        cout << "ID: " << id << endl;
    }
    
    void mostrarNombre() const override {
        cout << "Película: " << nombre << endl;
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

    void mostrarDetalle() const override {
        print("\nSerie (" + to_string(id) + ") :" + nombre);
        cout << "Duración: " << (duracion * n) << " minutos" << endl;
        cout << "Género: " << genero << endl;
    }

    void mostrarEpisodios() const {
        cout << "Episodios de la serie " << nombre << ":" << endl;
        for (int i = 0; i < n; i++) {
            episodios[i]->imprimir();
        }
    }

    void mostrarNombre() const override {
        cout << "Serie: " << nombre << endl;
    }
};

class Filmoteca {
private:
    Pelicula* peliculas[100];
    Serie* series[100];
    int numPeliculas;
    int numSeries;
public:
    Filmoteca() : numPeliculas(0), numSeries(0) {}

    void agregarPelicula(Pelicula* pelicula) {
        if (numPeliculas < 100) {
            peliculas[numPeliculas++] = pelicula;
        } else {
            cout << "No se pueden agregar más películas." << endl;
        }
    }

    void agregarSerie(Serie* serie) {
        if (numSeries < 100) {
            series[numSeries++] = serie;
        } else {
            cout << "No se pueden agregar más series." << endl;
        }
    };

    void mostrarPeliculas() const {
        cout << "\nPelículas:" << endl;
        for (int i = 0; i < numPeliculas; i++) {
            peliculas[i]->mostrarNombre();
        }
    };
    
    void mostrarSeries() const {
        cout << "\nSeries:" << endl;
        for (int i = 0; i < numSeries; i++) {
            series[i]->mostrarNombre();
        }
    };

    void mostrarContenido() const {
        mostrarPeliculas();
        mostrarSeries();
    };

    Pelicula* buscarPeli(int id) const {
        for (int i = 0; i < numPeliculas; i++) {
            if (peliculas[i]->getId() == id) {
                return peliculas[i];
            }
        }
        return nullptr;
    };

    Serie* buscarSerie(int id) const {
        for (int i = 0; i < numSeries; i++) {
            if (series[i]->getId() == id) {
                return series[i];
            }
        }
        return nullptr;
    };

};

int main() {
    // géneros permitidos (drama, acción, misterio).
    Pelicula peli1(1, "Avengers Endgame", 180, "Accion");
    Pelicula peli2(2, "The Dark Knight", 152, "Accion");
    Pelicula peli3(3, "Titanic", 195, "Drama");
    Pelicula peli4(4, "Inception", 148, "Misterio");
    Pelicula peli5(5, "The Godfather", 175, "Drama");
    Pelicula peli6(6, "Interstellar", 169, "Misterio");

    Serie serie1(7, "Serie de Drama", 40, "Drama");
    serie1.agregarEpisodio("Episodio 1");
    serie1.agregarEpisodio("Episodio 2");
    serie1.agregarEpisodio("Episodio 3");
    serie1.agregarEpisodio("Episodio 4");
    serie1.agregarEpisodio("Episodio 5");
    serie1.agregarEpisodio("Episodio 6");
    serie1.agregarEpisodio("Episodio 7");
    serie1.agregarEpisodio("Episodio 8");
    serie1.agregarEpisodio("Episodio 9");
    serie1.agregarEpisodio("Episodio 10");
    serie1.agregarEpisodio("Episodio 11");
    serie1.agregarEpisodio("Episodio 12");

    Serie serie2(8, "Serie de Accion", 50, "Accion");
    serie2.agregarEpisodio("Episodio 1");
    serie2.agregarEpisodio("Episodio 2");
    serie2.agregarEpisodio("Episodio 3");
    serie2.agregarEpisodio("Episodio 4");
    serie2.agregarEpisodio("Episodio 5");
    
    Serie serie3(9, "Serie de Misterio", 45, "Misterio");
    serie3.agregarEpisodio("Episodio 1");
    serie3.agregarEpisodio("Episodio 2");
    serie3.agregarEpisodio("Episodio 3");
    
    Serie serie4(10, "Serie de Accion", 55, "Accion");
    serie4.agregarEpisodio("Episodio 1");
    serie4.agregarEpisodio("Episodio 2");
    serie4.agregarEpisodio("Episodio 3");

    Filmoteca filmoteca;
    filmoteca.agregarPelicula(&peli1);
    filmoteca.agregarPelicula(&peli2);
    filmoteca.agregarPelicula(&peli3);
    filmoteca.agregarPelicula(&peli4);
    filmoteca.agregarPelicula(&peli5);
    filmoteca.agregarPelicula(&peli6);
    filmoteca.agregarSerie(&serie1);
    filmoteca.agregarSerie(&serie2);
    filmoteca.agregarSerie(&serie3);
    filmoteca.agregarSerie(&serie4);

    while (true)
    {
        cout << "\nSeleccione una opción:" << endl;
        cout << "1. Mostrar Películas" << endl;
        cout << "2. Mostrar Series" << endl;
        cout << "3. Mostrar Contenido" << endl;
        cout << "4. Salir" << endl;
        int opcion;
        cin >> opcion;

        if (opcion == 1) {
            filmoteca.mostrarPeliculas();
            cout << "\nSeleccione una película para calificar (1-6): ";
            int idPelicula;
            cin >> idPelicula;
            if (idPelicula >= 1 && idPelicula <= 6) {
                float nuevaCalificacion;
                cout << "Ingrese una nueva calificación (0-5): ";
                cin >> nuevaCalificacion;
                if (nuevaCalificacion >= 0 && nuevaCalificacion <= 10) {
                    Pelicula* pelicula = filmoteca.buscarPeli(idPelicula);
                    if (pelicula) {
                        pelicula->calificar(nuevaCalificacion);
                        pelicula->mostrarDetalle();
                        reproducirVideo(idPelicula);
                    } else {
                        cout << "Película no encontrada." << endl;
                    }
                } else {
                    cout << "Calificación inválida. Debe estar entre 0 y 10." << endl;
                }
            } else {
                cout << "ID de película no válido." << endl;
            }
            
            
        } else if (opcion == 2) {
            filmoteca.mostrarSeries();
            cout << "\nSeleccione una serie para calificar (7-10): ";
            int idSerie;
            cin >> idSerie;
            if (idSerie >= 7 && idSerie <= 10) {
                float nuevaCalificacion;
                cout << "Ingrese una nueva calificación (0-5): ";
                cin >> nuevaCalificacion;
                if (nuevaCalificacion >= 0 && nuevaCalificacion <= 10) {
                    Serie* serie = filmoteca.buscarSerie(idSerie);
                    if (serie) {
                        serie->calificar(nuevaCalificacion);
                        serie->mostrarDetalle();
                        serie->mostrarEpisodios();
                    } else {
                        cout << "Serie no encontrada." << endl;
                    }
                } else {
                    cout << "Calificación inválida. Debe estar entre 0 y 10." << endl;
                }
            } else {
                cout << "ID de serie no válido." << endl;
            }
            
        } else if (opcion == 3) {
            filmoteca.mostrarContenido();
            
        } else if (opcion == 4) {
            break;
        } else {
            cout << "Opción no válida, intente de nuevo." << endl;
        }
        
    }    

    return 0;
}