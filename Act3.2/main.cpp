// Act 3.2 – 26 de octubre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A01739522 – Sergio Sebastian Cortez Yepez
// A01739190 – Carlos Arturo Ferat Torres

#include "heap.h"

#define cinfirst ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    int option(1), value(0);
    Heap<int> heap;
    cinfirst

    while(option) {
        cin >> option;
        switch(option) {
            case 1:                 // push  | O(log₂n)
                cin >> value;
                heap.push(value);
                break;
            case 2:                 // pop   | O(log₂n)
                // Para que el output coincida con el ejemplo de salida,
                // cuando se hace un pop() tambien se debe imprimir el
                // elemento que se saca, aunque la tarea no lo indica
                cout << heap.top() << endl; // Esta es la linea adicional
                heap.pop();
                break;
            case 3:                 // print | O(n)
                heap.print();
                break;
            case 4:                 // top   | O(1)
                cout << heap.top() << endl;
                break;
            case 5:                 // empty | O(1)
                if(heap.empty()) cout << "true" << endl;
                else cout << "false" << endl;
                break;
            case 6:                 // size  | O(1)
                cout << heap.size() << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}
