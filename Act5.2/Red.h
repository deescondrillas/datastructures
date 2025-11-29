// Act 5.2 – 23 de noviembre, 2025
// Clase Log
//
#pragma once
# include "Vector.h" // :)
# include <string>

using namespace std;

template <class T>
class Red {
    public:
        // Constructor              | O(1)
        Red() {
        }

    private:
        int dirOne = -1;
        int dirTwo = -1;
        int nAccs = 0;
        int Ncons = 0;
        Vector<string> IPs;

};
