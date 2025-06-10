
#include <iostream>
using namespace std;

class Envio {
protected:
    double costoEstandar = 100;
    string nombreR, estadoR, nombreD, estadoD, direccionR, codigoPostalR, direccionD, codigoPostalD, ciudadR, ciudadD;

public:
    Envio(string _nR, string _dR, string _cR, string _eR, string _cpR,
          string _nD, string _dD, string _cD, string _eD, string _cpD) 
    {
        nombreR = _nR;
        direccionR = _dR;
        ciudadR = _cR;
        estadoR = _eR;
        codigoPostalR = _cpR;

        nombreD = _nD;
        direccionD = _dD;
        ciudadD = _cD;
        estadoD = _eD;
        codigoPostalD = _cpD;
    }

    virtual double calculaCosto() const {
        return costoEstandar;
    }
};

class Paquete : public Envio {
private:
    double largo, ancho, profundidad, peso, costoPerKg;

public:
    Paquete( 
        string _nR, string _dR, string _cR, string _eR, string _cpR,
        string _nD, string _dD, string _cD, string _eD, string _cpD,
        double _largo, double _ancho, double _profundidad, double _peso, double _costoPerKg = 20
    ) 
    : Envio(_nR, _dR, _cR, _eR, _cpR, 
            _nD, _dD, _cD, _eD, _cpD
    ) {
        largo = _largo;
        ancho = _ancho;
        profundidad = _profundidad;
        peso = _peso > 0 ? _peso : 0;
        costoPerKg = _costoPerKg > 0 ? _costoPerKg : 0;
    }
 
    double calculaCosto() const override {
        return costoEstandar + (peso * costoPerKg);
    }
};

class Sobre : public Envio {
private:
    double largo, ancho, costoExtra;

public:
    Sobre( 
        string _nR, string _dR, string _cR, string _eR, string _cpR,
        string _nD, string _dD, string _cD, string _eD, string _cpD,
        double _largo, double _ancho, double _costoExtra = 30
    ) 
        : Envio(_nR, _dR, _cR, _eR, _cpR, _nD, _dD, _cD, _eD, _cpD) {
        largo = _largo;
        ancho = _ancho;
        costoExtra = _costoExtra;
    }

    void normalizar() {
        if (largo < ancho) {
            swap(largo, ancho);
        }
    }
 
    double calculaCosto() const override {
        if (largo > 30 || ancho > 25) {
            return costoEstandar + costoExtra;
        } else {
            return costoEstandar;
        }
    }
};