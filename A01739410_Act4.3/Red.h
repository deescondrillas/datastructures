// Act 4.3 – 23 de noviembre, 2025
// Clase Node
#pragma once
#include "Node.h"

template <class T>
class Red {
    // Clase para guardar la direccion de red
    private:
        int ip1 = -1;
        int ip2 = -1;
    public:
    Red(int _ip1, int ip2){
        ip1 = _ip1;
        ip2 = _ip2;
    }

    bool operator > (const Red<T>& otherRed) const {
        return ip1 > otherRed.ip1;
        if(ip1 == otherRed.ip1) return ip2 > otherRed.ip2;
    }

    bool operator < (const Red<T>& otherRed) const {
        return ip1 < otherRed.ip1;
        if(ip1 == otherRed.ip1) return ip2 < otherRed.ip2;
    }
    
};
