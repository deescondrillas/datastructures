// Act 2.3 – 15 de octubre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A01739522 – Sergio Sebastian Cortez Yepez
// A01739190 - Carlos Arturo Ferat Torres

#include <fstream>      // Para leer y escribir archivos
#include "List.h"
#include "Log.h"

// Definiciones
ifstream fin("bitacora.txt");
ofstream fout("sorted.txt");

int main() {
    // Variables y estructuras de datos
    List<Log> logs;
    string line;
    Log reader;

    // Input desde bitacora.txt
    while(getline(fin, line)) {
        reader.read(line);
        logs.insert(reader);
    }

    // Mergesort O(n log₂n)
    logs.mergesort();

    // Output en sorted.txt
    fout << logs.print();

    // Busqueda secuencial (por implementar)
    cout << "done" << endl;
    return 0;
}
