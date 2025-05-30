//
//  Poligono.hpp
//  poo_codes_TC1030
//
//  Created by Juan Felipe Zepeda on 20/05/25.
//


// MARK: - Clase hija Poligono
class Poligono: public Shape {
private:
    int l;
    int b;
    int a;
    
public:
    Poligono(int, int, int, int, int);
    int getArea();
    int getLados();
};
