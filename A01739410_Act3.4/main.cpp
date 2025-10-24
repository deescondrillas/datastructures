// Act 3.4 – 23 de octubre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A01739522 – Sergio Sebastian Cortez Yepez
// A01739190 – Carlos Arturo Ferat Torres

#include <fstream>      // Para leer y escribir archivos
#include "AVL.h"
#include "Log.h"

// Definiciones
ifstream fin("bitacora.txt");       // Leer desde archivo
int* entrada(int);                  // Cambiar la entrada del usuario de string a Log

int main() {
    // Variables y estructuras de datos
    AVL<Log> logs;
    string line;
    Log reader;

    // Input desde bitacora.txt | O(n)
    while(getline(fin, line)) {
        reader.read(line);
        logs.insert(reader);
    }

    // Output a consola         | O(k log₂n)
    logs.inordenC(5);
}

// Convertir entrada a Log      | O(1)
int* entrada(int x) {
    string input, address("");
    int pts(0);
    cin >> input;
    int* ips = new int[4];
    for(int i = 0; i < 4; ++i) {
        while(input[pts] != '.' && pts < input.size()) address += input[pts++];
        ips[i] = stoi(address);
        address = "";
        ++pts;
    }
    ips[3] += x;
    return ips;
}
