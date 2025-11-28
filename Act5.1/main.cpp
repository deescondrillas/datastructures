// Act 5.1 – 29 de noviembre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A0173
// A0173

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
                case 1:
                    cin >> nuevo;
                    hash.ins(nuevo);
                    break;
                case 2:
                    hash.del();
                    break;
                case 3:
                    hash.print();
                    break;
                case 4:
                    cin >> key;
                    cout << *hash.search(key) << endl;
                    break;
            }
        }
    return 0;
}
