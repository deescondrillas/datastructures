// Act 5.1 – 29 de noviembre, 2025
// class Ip

#pragma once

#include <iostream>
#include <string>

using namespace std;

class Ip {
    public:
    // Constructor – O(1)
    Ip() {
        this->ip1 = 0;
        this->ip2 = 0;
    }
    // Constructor con parametros – O(1)
    void init(int one, int two) {
        this->ip1 = one;
        this->ip2 = two;
    }
    // Obtener primer id – O(1)
    int first() {
        return this->ip1;
    }
    // Obtener segundo id – O(1)
    int second() {
        return this->ip2;
    }

    // Imprimir – O(1)
    friend ostream& operator << (ostream& os, Ip& ip) {
        os << ip.ip1 << '.' << ip.ip2;
        return os;
    }
    // Comparar – O(1)
    friend bool operator == (Ip& one, Ip& two) {
        return one.ip1 == two.ip1 && one.ip2 == two.ip2;
    }
    // Comparar – O(1)
    friend bool operator < (Ip& one, Ip& two) {
        return one.ip1 == two.ip1 ? one.ip2 < two.ip2 : one.ip1 < two.ip1;
    }

    private:
        int ip1;
        int ip2;
};
