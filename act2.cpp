// Act 1.2 – 10 de septiembre, 2025

// A01739755 – Michelle Amanda Hernández Legaria
// A01739410 – Franco De Escondrillas Vázquez
// A01739511 – Jorge Luis Zago Guevara

#include <iostream>

using namespace std;

// Definiciones
#define rp(i, a, b) for(int i = (a), TT = (b); i < TT; ++i)

// Ordena en forma ascendente los datos con el método de Intercambio
void ordenaIntercambio(vector<int>);    // O(n²)

// Ordena en forma ascendentelos datos con el método de Burbuja
void ordenaBurbuja(vector<int>);        // O(n²)

// Ordena en forma ascendente los datos con el método de Merge
void ordenaMerge(vector<int>);          // O(…)

// Buscar con la busqueda secuencial un dato entero dentro del vector
int busqSecuencial(int, vector<int>);   // O(n)

// Buscar con la busqueda binaria un dato entero dentro del vector
int busqBinaria(int, vector<int>);      // O(log₂n)


int main() {
    // Input 1 – Entero positivo (n) y arreglo de n elementos
    int n; cin >> n;
    vector<int> arreglo(n);
    rp(i, 0, n) cin >> arreglo[i];
    // Input 2 – Entero positivo (q) y q queries
    int q; cin >> q;
    vector<int> queries(q);
    rp(i, 0, q) cin >> queries[i];
    // Proceso – ...

    // Output 1 – Cantidad de comparaciones por método de ordenamiento

    // Output 2 – q respuestas a las queries y cantidad de comparaciones hechas

    return 0;
}

// Funciones
