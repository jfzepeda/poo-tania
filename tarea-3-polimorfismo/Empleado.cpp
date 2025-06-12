
#include <iostream>
using namespace std;

class Empleado {
private:
    string nombre;
    int edad;

public:
    Empleado(string _nombre, int _edad) {
        nombre = _nombre;
        edad = _edad;
    }

    virtual double calcularSalario() const = 0; // Método virtual puro, hace de Empleado una clase abstracta

    bool operator<(Empleado& otro) {
        return calcularSalario() < otro.calcularSalario();
    }
    bool operator>(Empleado& otro) {
        return calcularSalario() > otro.calcularSalario();
    }
    bool operator<=(Empleado& otro) {
        return calcularSalario() <= otro.calcularSalario();
    }
    bool operator>=(Empleado& otro) {
        return calcularSalario() >= otro.calcularSalario();
    }
    bool operator==(Empleado& otro) {
        return calcularSalario() == otro.calcularSalario();
    }
    bool operator!=(Empleado& otro) {
        return calcularSalario() != otro.calcularSalario();
    }
};

class EmpleadoBase : public Empleado {
private:
    int salarioBase;

public:
    EmpleadoBase(int _salarioBase, string _nombre, int _edad) 
    : Empleado(_nombre, _edad
    ) {
        salarioBase = _salarioBase > 0 ? _salarioBase : 0; // Aseguramos que el salario base sea positivo
    }

    double calcularSalario() const override {
        return salarioBase;
    };

};

class EmpleadoPorHora : public Empleado {
private:
    int horasTrabajadas;
    int tarifaPorHora;
    
public:
    EmpleadoPorHora(int _horasTrabajadas, int _tarifaPorHora, string _nombre, int _edad) 
    : Empleado(_nombre, _edad
    ) {
        horasTrabajadas = _horasTrabajadas;
        tarifaPorHora = _tarifaPorHora;
    }

    double calcularSalario() const override {
        return horasTrabajadas * tarifaPorHora;
    };
};

class EmpleadoPorComision : public Empleado {
private:
    int ventasRealizadas;
    double comisionPorVenta;
    
public:
    EmpleadoPorComision(int _ventasRealizadas, double _comisionPorVenta, string _nombre, int _edad) 
    : Empleado(_nombre, _edad
    ) {
        ventasRealizadas = _ventasRealizadas;
        comisionPorVenta = _comisionPorVenta;
    }

    double calcularSalario() const override {
        return ventasRealizadas * comisionPorVenta;
    };

};

