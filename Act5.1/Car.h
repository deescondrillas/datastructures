// Act 5.1 – 29 de noviembre, 2025
// class Car

#pragma once
#include <string>
#include <iostream>

using namespace std;

class Car {
    public:
    // Constructor – O(1)
    Car() {

    }
    // Obtener id – O(1)
    string id() {
        return placa;
    }
    // Imprimir – O(1)
    friend ostream& operator << (ostream& os, Car& car) {
        os << car.placa;
        os << ' ' << car.marca;
        os << ' ' << car.modelo;
        os << ' ' << car.agno;
        return os;
    }
    // Leer – O(1)
    friend istream& operator >> (istream& is, Car& car) {
        is >> car.placa;
        is.ignore(1, '\n');
        getline(is, car.marca);
        getline(is, car.modelo);
        is >> car.agno;
        return is;
    }

    private:
        string placa;
        string marca;
        string modelo;
        int agno;

};
