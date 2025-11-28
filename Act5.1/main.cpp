// Act 5.1 – 29 de noviembre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A01739522 – Sergio Sebastian Cortez Yepez
// A01739190 – Carlos Arturo Ferat Torres

#include "Hash.h"

using namespace std;

int main() {
    // Variables
    int option{4};
    string key;
    Hash hash;
    Car nuevo;

    // Menu
        while(option) {
            cin >> option;
            switch(option) {
                case 1: // ins() – sin colision O(1) || WCS O(n)
                    cin >> nuevo;
                    hash.ins(nuevo);
                    break;
                case 2: // del() – sin colision O(1) || WCS O(n)
                    hash.del();
                    break;
                case 3: // print() | O(n)
                    hash.print();
                    break;
                case 4: // search() – sin colision O(1) || WCS O(n)
                    cin >> key;
                    cout << *hash.search(key) << endl;
                    break;
            }
        }
    return 0;
}
