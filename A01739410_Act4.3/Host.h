// Act 4.3 – 23 de noviembre, 2025
// Clase Node
#pragma once

template <class T>
class Host {
    // Clase para guardar la IP del host
    private:
        int ip3 = -1;
        int ip4 = -1;
        Node<T> *logs = nullptr;
    public:
    Host(int size = 1024){
        this->logs = new T[size]();
    }
    
    bool operator > (const Host<T>& otherHost) const {
        return ip3 > otherHost.ip3;
        if(ip3 == otherHost.ip3) return ip4 > otherHost.ip4;
    }

    bool operator < (const Host<T>& otherHost) const {
        return ip3 < otherHost.ip3;
        if(ip3 == otherHost.ip3) return ip4 < otherHost.ip4;
    }
    
};
