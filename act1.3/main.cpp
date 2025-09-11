// Act 1.3 – 14 de septiembre, 2025

// A01739755 – Michelle Amanda Hernández Legaria
// A01739410 – Franco De Escondrillas Vázquez
// A01739511 – Jorge Luis Zago Guevara

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definiciones
#define rp(i, a, b) for(int i = (a), TT = (b); i < TT; ++i)                         // Definición de un ciclo for rápido
#define iostream_testcases ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);     // Gestiona todos los cin primero, y luego los cout

//
struct Log {
    vector<int> timestamp;      // 1. mes, día, hora, minuto, segundo
    vector<int> ip;             // 2. primera, segunda, tercera, cuarta adress
    string issue;
    int port;


    void read() {

    }

};

// Ordena en forma ascendente los datos con el método de Merge
void ordenaMerge(int, int*);        // O(n log₂n)

int main() {
    iostream_testcases
    // ...
    cout << "En proceso" << endl;
    return 0;
}

// Funciones
void ordenaMerge(int sz, int *arr) {
    // ...
}
