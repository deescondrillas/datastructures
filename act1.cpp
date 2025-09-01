// Act 1.1 – 3 de septiembre, 2025

// A01739755 – Michelle Amanda Hernández Legaria
// A01739410 – Franco De Escondrillas Vázquez
// A01739511 – Jorge Luis Zago Guevara

#include <iostream>

using namespace std;

// definiciones
typedef unsigned long long int lli;

// Calcula la sumatoria de 1 hasta n con un metodo iterativo
lli sumaIterativa(lli n);   // O(n)

// Calcula la sumatoria de 1 hasta n con un metodo recursivo
lli sumaRecursiva(lli n);   // O(n)

// Calcula la sumatoria de 1 hasta n con un metodo matemático directo
lli sumaDirecta(lli n);     // O(1)


int main() {
    // input – entero positivo (n)
    lli n; cin >> n;
    // output – Σ de 1 hasta n
    cout << sumaIterativa(n) << endl;
    cout << sumaRecursiva(n) << endl;
    cout << sumaDirecta(n) << endl;
    return 0;
}

// funciones
lli sumaIterativa(lli n) {
    lli out = 0;
    for(lli i = 1; i <= n; ++i) out += i;
    return out;
}

lli sumaRecursiva(lli n) {
    return n ? n + sumaRecursiva(n - 1) : 0;
}

lli sumaDirecta(lli n) {
    return (n * (n + 1)) / 2;
}
