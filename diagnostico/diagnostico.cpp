
//
//  main.cpp
//  diagnostico_cpp
//
//  Created by Juan Felipe Zepeda on 15/05/25.
//

#include <iostream>
#include <string>
using namespace std;

class frac {
private:
    int numerador;
    int denominador;
    
public:
    frac(int _num, int _deno) {
        if (_deno == 0) {
            cout << "Error: Denominador no puede ser cero." << endl;
            exit(1);
        }
        if (_num == 0) {
            _deno = 1;
        }

        numerador = _num;
        denominador = _deno;

        simplificar();
    }

    void simplificar() {
        int mcd = 1;
        for (int i = 1; i <= numerador && i <= denominador; i++) {
            if (numerador % i == 0 && denominador % i == 0) {
                mcd = i;
            }
        }
        numerador /= mcd;
        denominador /= mcd;
    }

    frac sum(frac f) {
        int num = numerador * f.denominador + denominador * f.numerador;
        int deno = denominador * f.denominador;
        frac resultado(num, deno);
        resultado.simplificar();
        return resultado;
    }

    frac div(frac f) {
        int num = numerador * f.denominador;
        int deno = denominador * f.numerador;
        frac resultado(num, deno);
        resultado.simplificar();
        return resultado;
    }

    void print() {
        cout << numerador << "/" << denominador << endl;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int num1, deno1, num2, deno2;
    num1 = 1;
    deno1 = 3;
    num2 = 4;
    deno2 = 10;
    
    frac f1(num1, deno1);
    frac f2(num2, deno2);

    cout << "Fraccion 1: ";
    f1.print();
    cout << "Fraccion 2: ";
    f2.print();

    frac resultado = f1.sum(f2);
    cout << "Suma: ";
    resultado.print();

    resultado = f1.div(f2);
    cout << "División: ";
    resultado.print();

    return 0;
}

/*

No tengo conocimiento para realizar el segundo
ejercicio de suma de matrices de fracciones.alignas

Adicionalmente dado que ejecuto el programa en Xcode
este no genera archivo .h por lo que no puedo incluirlo

*/
