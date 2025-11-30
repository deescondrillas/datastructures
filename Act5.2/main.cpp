// Act 5.2 – 29 de noviembre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A01739522 – Sergio Sebastian Cortez Yepez
// A01739190 – Carlos Arturo Ferat Torres

#include <fstream>
#include "Hash.h"
#include "Log.h"

using namespace std;

int main() {
    // Variables
    ifstream fin("bitacorx.txt");
    string line;
    Hash hash;

    // Lectura de archivo           | O(n)
    while(getline(fin, line)) {
        Log reader;
        reader.read(line);
        hash.ins(reader.getRed());
    }

    // Mergesort                    | O(n log₂n)
    hash.mergesort();

    // Variables para queries
    Red query;
    int n{0};
    cin >> n;

    // Manejo de queries            | O(q)
    for(int i = 0; i < n; ++i) {
        cin >> query;
        Red* data = hash.search(query);
        data ? cout << *data << endl : cout << "Dato no encontrado" << endl;
    }

    return 0;
}
