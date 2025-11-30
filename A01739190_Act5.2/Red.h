// Act 5.2 – 23 de noviembre, 2025
// Clase Red

#pragma once
#include "Vector.h"
#include "Ip.h"

using namespace std;

class Red {
    public:
        // Constructor                      | O(1)
        Red() {

        }
        // Constructor con parámetros       | O(1)
        Red(Ip red_ip, Ip host_ip) {
            this->red = red_ip;
            insertIP(host_ip);
        }

        // Constructor con parámetros       | O(1)
        void init(Ip& red_ip, Ip& host_ip) {
            this->red = red_ip;
            insertIP(host_ip);
        }
        // Añadir ip de un nuevo host       | O(1)
        void insertIP(Ip new_ip){
            nAccs++;
            hosts.pb(new_ip);
        }

        // Obtener red                      | O(1)
        Ip* redIP() {
            return &this->red;
        }

        // Obtener el primer host IP        | O(1)
        Ip* hostIP() {
            return &this->hosts[0];
        }

        // Obtener tamagno de hosts         | O(1)
        int hostSZ() {
            return this->hosts.sz();
        }

        // Ordenar y eliminar duplicados    | O(n log₂n)
        void mergeSortIPs(int left, int right){
            // Caso base
            if (left >= right) return;
            // Division
            int mid{(left + right) / 2};
            mergeSortIPs(left, mid);
            mergeSortIPs(mid + 1, right);
            // Union
            merge(left, mid, right);
        }

        // Unir eliminando duplicados       | O(n)
        void merge(int left, int mid, int right){
            // Tamagnos de cada vector
            int n1 = mid - left + 1;
            int n2 = right - mid;
            // Reconstruir vectores
            Vector<Ip> L(n1), R(n2);
            for(int i = 0; i < n1; i++) L[i] = hosts[i + left];
            for(int i = 0; i < n2; i++) R[i] = hosts[i + mid + 1];
            // Unir y eliminar duplicados
            int i{0}, j{0}, k{left};
            while(i < n1 && j < n2) {
                if(L[i] == R[j]) {
                    hosts[k++] = L[i++];
                    j++;
                }
                else if (L[i] < R[j]) hosts[k++] = L[i++];
                else hosts[k++] = R[j++];
            }
            // Insertar remanentes
            while(i < n1) hosts[k++] = L[i++];
            while(j < n2) hosts[k++] = R[j++];
        }

        // Leer                             | O(1)
        friend istream& operator >> (istream& is, Red& net) {
            string s, dir1, dir2;
            is >> s;
            for(char i : s) {
                if(i == '.') {
                    dir1 = dir2;
                    dir2 = "";
                } else dir2 += i;
            }
            net.red.init(stoi(dir1), stoi(dir2));
            return is;
        }

        // Imprimir                         | O(1)
        friend ostream& operator << (ostream& os, Red network) {
            os << network.red << endl;
            os << network.nAccs << endl;
            os << network.hosts.sz() << endl;
            for(int i = 0; i < network.hosts.sz(); ++i)
                os << network.red << '.' << network.hosts[i] << endl;
            return os;
        }

        // Comparar                         | O(1)
        friend bool operator == (Red& one, Red& two) {
            return one.red == two.red;
        }

    private:
        Ip red;
        int nAccs = 0;
        Vector<Ip> hosts;

        friend class Hash;
};
