// Act 4.3 – 23 de noviembre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A01739522 – Sergio Sebastian Cortez Yepez
// A01739190 – Carlos Arturo Ferat Torres

#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"
#include "Red.h"
#include "Host.h"
#include "Log.h"

using namespace std;

int main() {
    Graph<Red> grafo;
    ifstream file("bitacora.txt");
    string line;

    while (getline(file, line)) {
        if (!line.empty()) {
            grafo.insert(line);
        }
    }
    file.close();

    
    return 0;
}

/*
 * Almacenar, desde un nodo raíz, cada uno de los logs
 * El nodo raíz estará conectado a los nodos de red (primeros dos dígitos de la dirección IP)
 * El nodo de red estará conectado a los nodos con la dirección del equipo (últimos dos dígitos de la dirección IP)
 * Este último estará conectada a un nodo con el resto de la información
 *
 * Grado de salida en el primer y segundo nivel (red y hosts)
 */
