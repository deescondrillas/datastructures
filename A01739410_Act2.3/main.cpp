// Act 2.3 – 15 de octubre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A01739522 – Sergio Sebastian Cortez Yepez
// A01739190 - Carlos Arturo Ferat Torres

#include "Log.h"
#include "List.h"
#include <fstream>      // Para leer y escribir archivos

using namespace std;

// Definiciones
ifstream fin("bitacora.txt");
ofstream fout("sorted.txt");

int main() {
    // Variables y estructuras de datos
    List<Log> logs;
    string line;
    Log reader;
    //Leer logs
    while(getline(fin, line)) {
        reader.read(line);
        logs.insert(reader);
    }
    fout << logs.print();


    return 0;
}
