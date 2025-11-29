// Act 5.1 – 29 de noviembre, 2025
// class Hash

#pragma once
# include "Red.h"
# include "Vector.h"
# include <iostream>

using namespace std;

class Hash {
    public:
        // Constructor – O(1)
        Hash() {

        }
        // Insertar – sin colision O(1) || WCS O(n)
        void ins(int ip1, int ip2, string& ip) {
            if(size == 65521) {
                cout << "tabla llena, imposible insertar" << endl;
                return;
            };

            int p = hash(ip1, ip2);

            // Buscar espacio
            while(flag[p] && !(tabla[p].ip1 == ip1 && tabla[p].ip2 == ip2))
                p = (p + 1) % SIZE;

            // Revisa si es nuevo
            if (!flag[p]){
                tabla[p] = Red(ip1, ip2);
                flag[p] = 1;
                size++;
            }

            // Añade IP completa
            tabla[p].insertIP(ip);
        }

        // Buscar – sin colision O(1) || WCS O(n)
        Red* search(int ip1, int ip2) {
            int p = hash(ip1, ip2);

            while(flag[p]){
                if(tabla[p].ip1 == ip1 && tabla[p].ip2 == ip2)
                    return &tabla[p];
                p = (p + 1) % SIZE;
            }
            return nullptr;
        }

    private:
        static const int SIZE{65521};
        Red red;
        Red tabla[SIZE] = {red};
        int flag[SIZE] = {0};
        int size{0};

        // Funcion Hash – O(1)
        int hash(int ip1, int ip2) {
            return (ip1 * 256 + ip2) % SIZE;
        }
};
