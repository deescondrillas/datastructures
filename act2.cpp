// Act 1.2 – 10 de septiembre, 2025

// A01739755 – Michelle Amanda Hernández Legaria
// A01739410 – Franco De Escondrillas Vázquez
// A01739511 – Jorge Luis Zago Guevara

#include <iostream>
#include <vector>

using namespace std;

// Definiciones
#define rp(i, a, b) for(int i = (a), TT = (b); i < TT; ++i)                         // Definición de un ciclo for rápido
#define iostream_testcases ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);     // Gestiona todos los cin primero, y luego los cout

// Ordena en forma ascendente los datos con el método de Intercambio
void ordenaIntercambio(vector<int>&);    // O(n²)

// Ordena en forma ascendentelos datos con el método de Burbuja
void ordenaBurbuja(vector<int>);        // O(n²)

// Ordena en forma ascendente los datos con el método de Merge
void ordenaMerge(vector<int>);          // O(n log₂n)

// Buscar con la busqueda secuencial un dato entero dentro del vector
int busqSecuencial(int, vector<int>);   // O(n)

// Buscar con la busqueda binaria un dato entero dentro del vector
int busqBinaria(int, vector<int>);      // O(log₂n)


int main() {
    iostream_testcases
    // Input 1 – Entero positivo (n) y arreglo de n elementos
    int n; cin >> n;
    vector<int> arreglo(n);
    rp(i, 0, n) cin >> arreglo[i];
    // Input 2 – Entero positivo (q) y q queries
    int q; cin >> q;
    vector<int> queries(q);
    rp(i, 0, q) cin >> queries[i];
    // Output 1 – Cantidad de comparaciones por método de ordenamiento
    ordenaIntercambio(arreglo);
    ordenaBurbuja(arreglo);
    ordenaMerge(arreglo);
    // Proceso – Ordenar el arreglo para ejecutar las búsquedas

    // Output 2 – q respuestas a las queries y cantidad de comparaciones hechas
    rp(i, 0, q) {
        busqSecuencial(queries[i], arreglo);
        busqBinaria(queries[i], arreglo);
    }
    // rp(i, 0, n) cout << arreglo[i] << ' '; cout << endl;
    return 0;
}

// Funciones
void ordenaIntercambio(vector<int> &v) {
    int comparaciones = 0;
    int sz = v.size();
    rp(i, 0, sz) rp(j, i + 1, sz) {
        ++comparaciones;
        if(v[i] > v[j]) swap(v[i], v[j]);
    }
    cout << comparaciones << ' ';
}

void ordenaBurbuja(vector<int> v) {
    int comparaciones = 0;
    // ...
    cout << comparaciones << ' ';
}

void ordenaMerge(vector<int> v) {
    int comparaciones = 0;
    // ...
    cout << comparaciones << '\n';
}

int busqSecuencial(int x, vector<int> v) {
    int comparaciones = 0;
    int indice = - 1;

    rp(i, 0, v.size()) {
        ++comparaciones;
        if(x == v[i]) {
            indice = i;
            break;
        }
    }

    cout << indice << ' ';
    cout << comparaciones << ' ';
    return indice;
}

int busqBinaria(int x, vector<int> v) {
    int comparaciones = 0;
    int indice = - 1;
    int l = 0;
    int r = v.size();
    int mid = (l + r - 1)/2;

    while(l < r) {
        ++comparaciones;
        if(x == v[mid]) {
            indice = mid;
            break;
        }
        if(x > v[mid]) l = mid + 1;
        else r = mid - 1;
        mid = (l + r - 1)/2;
    }
    /* OBSERVACIONES: para obtener los resultados de la tarea, se debe restar uno al
     * calcular el valor medio,lo cual no hace ningún sentido. De hacer una búsqueda
     * binaria más optimizada, se obtienen los resultados 2 3 3 3 vs 3 4 4 1 */
    cout << comparaciones << endl;
    return indice;
}

/*
TC Input (borrar después)
8
10 4 8 12 20 15 54 18
4
20 54 100 12

*/
