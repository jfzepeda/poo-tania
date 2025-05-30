//
//  Rectangulo.hpp
//  poo_codes_TC1030
//
//  Created by Juan Felipe Zepeda on 20/05/25.
//


// MARK: - Clase hija Rectangulo
class Rectangulo: public Shape {
private:
    int b;
    int h;
    
public:
    Rectangulo(int, int, int, int);
    int getArea();
};