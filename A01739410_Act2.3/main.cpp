// Act 2.3 – 15 de octubre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A01739522 – Sergio Sebastian Cortez Yepez
// A01739190 - Carlos Arturo Ferat Torres

#include <fstream>      // Para leer y escribir archivos
#include "List.h"
#include "Log.h"

// Definiciones
ifstream fin("bitacora.txt");
ofstream fout("sortedDarta.txt");
int* entrada(int);

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

    // Busqueda secuencial
    Log inicio(entrada(0));
    Log final(entrada(1));
    cout << logs.search(inicio, final);
    return 0;
}

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
