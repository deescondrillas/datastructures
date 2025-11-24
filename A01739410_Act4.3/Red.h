// Act 4.3 – 23 de noviembre, 2025
// Clase Node

#pragma once

template <class T>
class Red {
    // Clase para guardar la direccion de red
    private:
        int ip1 = -1;
        int ip2 = -1;
        Node<T> *hosts = nullptr;
    public:
    Red(int size = 1024){
        this->hosts = new T[size]();
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
