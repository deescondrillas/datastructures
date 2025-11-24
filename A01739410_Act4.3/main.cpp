// Act 4.3 – 23 de noviembre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A01739522 – Sergio Sebastian Cortez Yepez
// A01739190 – Carlos Arturo Ferat Torres

#include <fstream>
#include "Graph.h"

// Declarar archivo de lectura
ifstream fin("bitacora.txt");

int main() {
    // Variables y estructuras de datos
    int dNet{0}, dHost{0};
    string line;
    Graph logs;
    Log reader;

    // Input desde bitacora.txt | O(n)
    while(getline(fin, line)) {
        reader.read(line);
        logs.insert(reader.getNet());
    }

    // Ordenar y mergear        | O(n log₂n)
    logs.mergesort();

    // Obener maximos           | O(n)
    logs.get_degree(&dNet, &dHost);

    // Output a consola         | O(n)
    logs.print(&dNet, &dHost);

    // cout << dNet << ' ' << dHost << endl;
    return 0;
}
