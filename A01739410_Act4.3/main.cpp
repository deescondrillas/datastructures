// Act 4.3 – 23 de noviembre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A01739522 – Sergio Sebastian Cortez Yepez
// A01739190 – Carlos Arturo Ferat Torres

#include <iostream>
#include <fstream>
#include <string>

#include "Graph.h"
#include "Log.h"

using namespace std;

int main() {

    Graph<Log> graph;
    string line;

    ifstream fin("bitacora.txt");

    // Leer bitacora línea por línea
    while (getline(fin, line)) {
        if (line.size() > 0) {
            graph.insert(line);
        }
    }

    fin.close();

    graph.printMaxRedes();
    graph.printMaxHosts();

    return 0;
}
