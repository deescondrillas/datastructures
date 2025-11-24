// Act 4.3 – 23 de noviembre, 2025
// Clase Red

#pragma once

class Red {
    // Clase para guardar la direccion de red
    private:
        int ip1 = -1;
        int ip2 = -1;
    public:
        Red() : ip1(0), ip2(0) {}
        Red(int _ip1, int _ip2){
            ip1 = _ip1;
            ip2 = _ip2;
        }

        bool operator > (const Red& otherRed) const {
            if(ip1 != otherRed.ip1) return ip1 > otherRed.ip1;
            return ip2 > otherRed.ip2;
        }

        bool operator < (const Red& otherRed) const {
            if(ip1 != otherRed.ip1) return ip1 < otherRed.ip1;
            return ip2 < otherRed.ip2;
        }
        template <class> friend class Graph;
};
