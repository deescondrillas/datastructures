// Act 5.2 – 23 de noviembre, 2025
// Clase Log
//
#pragma once
# include "Vector.h" // :)
# include <string>
#include <sstream>

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

        void mergeSortIPs(int left, int right){

            if (left >= right)
                return;

            int mid = left + (right - left) / 2;
            mergeSortIPs( left, mid);
            mergeSortIPs(mid + 1, right);
            merge(left, mid, right);
        }
        void merge(int left,int mid,int right){

            int n1 = mid - left + 1;
            int n2 = right - mid;

            Vector<string> L(n1), R(n2);

            for(int i=0; i < n1; i++){
                L[i] = IPs[i + left];
            }
            for(int i=0; i < n2; i++){
                R[i] = IPs[i + mid + 1];
            }

            int i = 0, j = 0;
            int k = left;
            while(i<n1 && j<n2){
                if(compararIPs(L[i], R[j])){
                    IPs[k] = L[i];
                    i++;
                }
                else{
                    IPs[k] = R[j];
                    j++;
                }
                k++;
            }

            while (i < n1) {
                IPs[k] = L[i];
                i++;
                k++;
            }
            while (j < n2) {
                IPs[k] = R[j];
                j++;
                k++;
            }
        }

        bool compararIPs(string sip1, string sip2){
            char c;
            int ipx;
            int ip1_3, ip1_4, ip2_3, ip2_4;
            stringstream ssip1{sip1};
            stringstream ssip2(sip2);
            ssip1>> ipx >> c >> ipx >> c >> ip1_3 >> c >>ip1_4;
            ssip2>> ipx >> c >> ipx >> c >> ip2_3 >> c >>ip2_4;

            if(ip1_3 != ip2_3) return ip1_3 <= ip2_3;
            return ip1_4 <= ip2_4;
        }

    private:
        int ip1 = -1;
        int ip2 = -1;
        int nAccs = 0;
        Vector<string> IPs;

        friend class Hash;
};
