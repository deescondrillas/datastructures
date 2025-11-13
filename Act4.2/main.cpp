// Act 4.2 – 20 de noviembre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A01739522 – Sergio Sebastian Cortez Yepez
// A01739190 – Carlos Arturo Ferat Torres

#include <iostream>
// #include ".h"

using namespace std;

bool isDag();
bool isTree(int, int);

int main() {
    int n{0}, m{0};
    isDag() ? isTree(n, m) ? cout << "True" << endl : cout << "False" << endl : cout << "No es un DAG" << endl;
    return 0;
}

bool isTree(int n, int m) {
    return n - m == 1;
}
