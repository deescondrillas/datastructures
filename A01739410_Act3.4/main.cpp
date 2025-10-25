// Act 3.4 – 28 de octubre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A01739522 – Sergio Sebastian Cortez Yepez
// A01739190 – Carlos Arturo Ferat Torres

#include <fstream>      // Para leer y escribir archivos
#include "AVL.h"
#include "Log.h"

// Definiciones
ifstream fin("bitacora.txt");       // Leer desde archivo

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
    logs.tree();
}
