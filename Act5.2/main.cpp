// Act 5.2 – 29 de noviembre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A01739522 – Sergio Sebastian Cortez Yepez
// A01739190 – Carlos Arturo Ferat Torres

#include <iostream>
#include <fstream>
#include "Hash.h"
#include "Log.h"

using namespace std;

// Declarar archivo de bitacora

int main() {
    // Variables
    ifstream fin("bitacorx.txt");
    string line;
    Hash hash;
    Log entry;

    // Leer archivo de bitacora
    while (getline(fin, line)) {
        entry.read(line);

        pair red = entry.getRed();
        string ip = entry.getIP();
        hash.ins(red.first, red.second, ip);
    }

    return 0;
}
