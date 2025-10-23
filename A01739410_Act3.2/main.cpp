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
            case 1:
                cin >> value;
                heap.push(value);
                break;
            case 2:
                cout << heap.top() << endl;
                heap.pop();
                break;
            case 3:
                heap.print();
                break;
            case 4:
                cout << heap.top() << endl;
                break;
            case 5:
                if(heap.empty()) cout << "true" << endl;
                else cout << "false" << endl;
                break;
            case 6:
                cout << heap.size() << endl;
                break;
            default:
                heap.heapsort();
                break;
        }
    }
    return 0;
}

// 1 5 1 9 1 3 1 7 1 8 1 2 1 4 1 1 1 6 1 0 3 7 3 0
