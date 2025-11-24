// Act 4.3 – 23 de noviembre, 2025
// Clase Host

#pragma once

class Host {
    // Clase para guardar la IP del host
    private:
        int ip3 = -1;
        int ip4 = -1;
    public:
    Host() : ip3(0), ip4(0) {}
    Host(int _ip3, int _ip4){
        ip3 = _ip3;
        ip4 = _ip4;
    }

    bool operator > (const Host& otherHost) const {
        if(ip3 != otherHost.ip3) return ip3 > otherHost.ip3;
        return ip4 > otherHost.ip4;
    }

    bool operator < (const Host& otherHost) const {
        if(ip3 != otherHost.ip3) return ip3 < otherHost.ip3;
        return ip4 < otherHost.ip4;
    }
    template <class> friend class Graph;
};
