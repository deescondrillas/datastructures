// Act 1.2 – 10 de septiembre, 2025

// A01739755 – Michelle Amanda Hernández Legaria
// A01739410 – Franco De Escondrillas Vázquez
// A01739511 – Jorge Luis Zago Guevara

#include <iostream>

using namespace std;

// Definiciones
#define rp(i, a, b) for(int i = (a), TT = (b); i < TT; ++i)                         // Definición de un ciclo for rápido
#define iostream_testcases ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);     // Gestiona todos los cin primero, y luego los cout

// Ordena en forma ascendente los datos con el método de Intercambio
void ordenaIntercambio(int*);       // O(n²)

// Ordena en forma ascendentelos datos con el método de Burbuja
void ordenaBurbuja(int*);           // O(n²)

// Ordena en forma ascendente los datos con el método de Merge
void ordenaMerge(int, int*);        // O(n log₂n)

// Buscar con la busqueda secuencial un dato entero dentro del vector
int busqSecuencial(int, int*);      // O(n)

// Buscar con la busqueda binaria un dato entero dentro del vector
int busqBinaria(int, int*);         // O(log₂n)

// Variables globales – Comparaciones y tamaño del arreglo
int sortI = 0;
int sortB = 0;
int sortM = 0;
int busqS = 0;
int busqB = 0;
int n;

int main() {
    iostream_testcases
    // Input 1 – Entero positivo (n) y arreglo de n elementos
    cin >> n;
    int arreglo[n];
    rp(i, 0, n) cin >> arreglo[i];
    // Input 2 – Entero positivo (q) y q queries
    int q; cin >> q;
    int queries[q];
    rp(i, 0, q) cin >> queries[i];
    // Proceso – Crear dos copias del arreglo para ordenarlas
    int copy1[n], copy2[n];
    rp(i, 0, n) copy1[i] = arreglo[i];
    rp(i, 0, n) copy2[i] = arreglo[i];
    // Proceso – Ordenar el arreglo para ejecutar las búsquedas
    ordenaIntercambio(copy1);
    ordenaBurbuja(copy2);
    ordenaMerge(n, arreglo);
    // Output 1 – Cantidad de comparaciones por método de ordenamiento
    cout << sortI << ' ' << sortB << ' ' << sortM << endl;
    // Output 2 – q respuestas a las queries y cantidad de comparaciones hechas
    rp(i, 0, q) {
        cout << busqSecuencial(queries[i], arreglo);
        busqBinaria(queries[i], arreglo);
        cout << ' ' << busqS << ' ' << busqB << endl;
    }
    return 0;
}

// Funciones
void ordenaIntercambio(int *arr) {
    rp(i, 0, n) rp(j, i + 1, n) {
        if(arr[i] > arr[j]) swap(arr[i], arr[j]);
        ++sortI;                                    // aumenta el contador con cada comparación
    }
}

void ordenaBurbuja(int *arr) {
    bool huboSwap = true;

    rp(i, 1, n) {
        huboSwap = false;
        rp(j, 0, n - i) {
            ++sortB;                                // aumenta el contador con cada comparación
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                huboSwap = true;
            }
        }
        if (!huboSwap) break;                       // si no hubo intercambios, ya está ordenado
    }
}

void ordenaMerge(int sz, int *arr) {
    if(sz == 1) return;

    int l = 0;
    int r = 0;
    int left = sz/2;
    int right = sz - left;
    int arrL[left], arrR[right];                    // se crean dos subarrays de la mitad de tamaño

    rp(i, 0, sz) {                                  // se dividen los elementos en cada subarray
        if(i < left) arrL[i] = arr[i];
        else arrR[i - left] = arr[i];
    }

    ordenaMerge(left, arrL);                        // se ordena el primer subarray
    ordenaMerge(right, arrR);                       // se ordena el segundo subarray

    rp(i, 0, sz) {
        if(l < left && r < right) {                 // si no se han usado ya todos los elementos de un subarray, los compara
            ++sortM;                                // aumenta el contador con cada comparación
            if(arrL[l] < arrR[r]) {                 // se toma el elemento más chico y se avanza al siguiente
                arr[i] = arrL[l++];
            }
            else arr[i] = arrR[r++];
        }
        else if(l == left) arr[i] = arrR[r++];      // si se acaba el primer subarray, se completa con el segundo
        else if(r == right) arr[i] = arrL[l++];     // si se acaba el segundo subarray, se completa con el primero
    }
}

int busqSecuencial(int x, int *arr) {
    busqS = 0;
    rp(i, 0, n) if(x == arr[busqS++]) return i;     // aumenta el contador cada iteración, si encuentra x regresa su índice
    return -1;                                      // si no encuentra x, regresa -1
}

int busqBinaria(int x, int *arr) {
    busqB = 0;
    int l = 0;
    int r = n - 1;
    int mid = (l + r)/2;

    while(l <= r) {
        ++busqB;                                    // aumenta el contador cada iteración
        if(x == arr[mid]) return mid;               // al encontrar x, regresa su índice
        if(x > arr[mid]) l = mid + 1;
        else r = mid - 1;
        mid = (l + r)/2;
    }
    return -1;                                      // si no se encuentra x, se regresa -1
}
