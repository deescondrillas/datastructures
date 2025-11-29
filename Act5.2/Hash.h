// Act 5.1 – 29 de noviembre, 2025
// class Hash

#pragma once
# include "red"

using namespace std;

class Hash {
    public:
        // Constructor – O(1)
        Hash() {

        }
        // Insertar – sin colision O(1) || WCS O(n)
        void ins(Car nuevo) {
            if(is_in(nuevo.id())) cout << "imposible insertar, placa duplicada" << endl;
            else if(size == 97) cout << "tabla llena, imposible insertar" << endl;
            else {
                int p = hash(nuevo.id());
                // Buscar espacio
                while(flag[p] == 1) p = (p + 1) % 97;
                tabla[p] = nuevo;
                flag[p] = 1;
                size++;
            }
        }
        // Eliminar – sin colision O(1) || WCS O(n)
        void del() {
            string key;
            cin >> key;
            for(int i = 0; i < 97; ++i) {
                int p = (hash(key) + i) % 97;
                if(!flag[p]) return;
                if(flag[p] == 1 && tabla[p].id() == key) {
                    flag[p] = -1;
                    size--;
                }
            }
        }
        // Buscar – sin colision O(1) || WCS O(n)
        Car* search(string key) {
            for(int i = 0; i < 97; ++i) {
                int p = (hash(key) + i) % 97;
                if(!flag[p]) return nullptr;
                if(flag[p] == 1 && tabla[p].id() == key) return &tabla[p];
            }
            return nullptr;
        }
        // Imprimir – O(n)
        void print() {
            for(int i = 0; i < 97; i++){
                cout << i;
                if(flag[i] == 1) cout << ' ' << tabla[i];
                cout << endl;
            }
        }
        // Elemento en el set – sin colision O(1) || WCS O(n)
        bool is_in(string key){
            for(int i = 0; i < 97; ++i) {
                int p = (hash(key) + i) % 97;
                if(!flag[p]) return false;
                if(flag[p] == 1 && tabla[p].id() == key) return true;
            }
            return false;
        }

    private:
        static const int SIZE{65521};
        Car coche;
        Car tabla[SIZE] = {coche};
        int flag[SIZE] = {0};
        int size{0};

        // Funcion Hash – O(1)
        int hash(string data) {
            int s = 0;
            for(char a: data) s += (int)a;
            return s % 97;
        }
};
