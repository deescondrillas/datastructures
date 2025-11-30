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
    ifstream fin("bitacora.txt");
    string line;
    Hash hash;
    Log entry;
    // Leer archivo de bitacora
    while (getline(fin, line)) {
        entry.read(line);
        
        pair<int, int> red = entry.getRed();
        string ip = entry.getIP();
        hash.ins(red.first, red.second, ip);
    }
    hash.OrdenarIPs();
    cout << "completado" << endl;
    
    // --------------------------------------------------
    // Leer que redes imprimir
    int n;
    string redStr;
    cin>>n;

    for (int i=0; i<n; i++) {
        cin>>redStr;
        cout << "----- " << redStr << " -----\n";

        int pos = redStr.find('.');
        int ip1 = stoi(redStr.substr(0, pos));
        int ip2 = stoi(redStr.substr(pos+1));

        Red* net = hash.search(ip1, ip2);

        if (!net) {
            cout << "Red no encontrada.\n\n";
            continue;
        }

        cout << "Accesos totales: " << net->getAccs() << "\n";
        cout << "IPs unicas: " << net->getNumIPs() << "\n";

        Vector<string> v = net->getIPs();   // obtienes el vector
        for (int i = 0; i < v.Size(); i++) {
            cout << v[i] << "\n";
        }

        cout << "\n";
    }

    return 0;

}
