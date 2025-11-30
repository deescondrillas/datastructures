// Act 5.1 – 29 de noviembre, 2025
// class Hash

#pragma once

#include "Red.h"

using namespace std;

class Hash {
    public:
        // Constructor      | O(1)
        Hash() {
            tabla = Vector<Red>(SIZE);
        }

        // Insertar         | sin colision O(1) || WCS O(n)
        void ins(Red red) {
            // Crear copia a insertar
            Red nuevo = red;
            // Elemento ya insertado
            Red* find = search(nuevo);
            if(find) find->insertIP(*nuevo.hostIP());
            // Tabla llena
            else if(size == 65521) cout << "tabla llena, imposible insertar" << endl;
            // Insertar nuevo
            else {
                // Buscar espacio
                int p = hash(*nuevo.redIP());
                while(flag[p]) p = (p + 1) % SIZE;
                tabla[p] = nuevo;
                flag[p] = 1;
                size++;
            }
        }

        // Buscar           | sin colision O(1) || WCS O(n)
        Red* search(Red &red) {
            int p = hash(*red.redIP());
            // Buscar ip de red
            while(flag[p]) {
                if(tabla[p] == red) return &tabla[p];
                p = (p + 1) % SIZE;
            }
            return nullptr;
        }

        // Mergesort        | O(n log₂n)
        void mergesort() {
            for(int i = 0; i < SIZE; ++i) if(flag[i]) tabla[i].mergeSortIPs(0, tabla[i].hostSZ() - 1);
        }

    private:
        static const int SIZE{65521};
        Red red;
        Vector<Red> tabla;
        bool flag[SIZE] = {false};
        int size{0};

        // Funcion Hash     | O(1)
        int hash(Ip red) {
            return (red.first() * 256 + red.second()) % SIZE;
        }
        // Se usa la funcion Ip1 * 256 + Ip2 ya que la red esta formada por dos secciones a y b de hasta 256
        // Todas las combinaciónes posibles se encuentran entre [0, 65536] por lo que representando la llave
        // en un entero de 16 bits se manejan todas esas posibilidades, posteriormente se le aplica modulo
        // 65521, el primo más grande menor a 65536, lo que garantiza muy pocas colisiones y aproveca todo el
        // tamaño de los primeros dos octetos de la IP.Home
};
