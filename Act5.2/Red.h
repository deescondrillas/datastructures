// Act 5.2 – 23 de noviembre, 2025
// Clase Log
//
#pragma once
# include "Vector.h" // :)
# include <string>

using namespace std;

class Red {
    public:
        // Constructor              | O(1)
        Red() {

        }

        // Constructor pasando Red
        Red (int ip1_, int ip2_){
            ip1 = ip1_;
            ip2 = ip2_;
        }

        //Añadir IP unica
        void insertIP(string& ip){
            nAccs++;
            // evitar duplicados
            for (int i = 0; i < IPs.Size(); i++){
                if (IPs[i] == ip){
                    return;
                }
            }
            // Inserta la IP;
            IPs.pb(ip);
        }

        // Parsea la Red a string
        string getRed(){
            return to_string(ip1) + "-" + to_string (ip2);
        }

        // Ordena las IPs;
        void sortIPs(){
            // Alguien escriba un mergeSort
        }

        // Getters
        int getAccs(){
            return nAccs;
        }

        int getNumIPs (){
            return IPs.Size();
        }

        Vector<string> getIPs() {
            return IPs;
        }

    private:
        int ip1 = -1;
        int ip2 = -1;
        int nAccs = 0;
        Vector<string> IPs;

        friend class Hash;
};
