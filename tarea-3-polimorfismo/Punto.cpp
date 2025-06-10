// === EJERCICIO 3: Punto2D / Punto3D y operator+ ===
#include <iostream>
#include <cmath>
using namespace std;

class Punto2D {
protected:
    double x, y;

public:
    Punto2D(double xx = 0, double yy = 0) {
        x = xx;
        y = yy;
    }

    double distancia(Punto2D p) {
        return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
    }

    Punto2D operator+(Punto2D p) {
        Punto2D tmp;
        tmp.x = x + p.x;
        tmp.y = y + p.y;
        return tmp;
    }

    double getX() { return x; }
    double getY() { return y; }
};
    
class Punto3D : public Punto2D {
    double z;

public:
    Punto3D(double xx = 0, double yy = 0, double zz = 0)
        : Punto2D(xx, yy) {
        z = zz;
    }

    double distancia(Punto3D p) {
        return sqrt((x - p.x)*(x - p.x)
                    + (y - p.y)*(y - p.y)
                    + (z - p.z)*(z - p.z));
    }

    Punto3D operator+(Punto3D p) {
        Punto3D tmp;
        tmp.x = x + p.x;
        tmp.y = y + p.y;
        tmp.z = z + p.z;
        return tmp;
    }
    
    double getZ() { return z; }
};
    
    
    