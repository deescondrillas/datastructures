// Act 2.2 – 11 de octubre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A01739522 – Sergio Sebastian Cortez Yepez
// A01739190 - Carlos Arturo Ferat Torres

#include <iostream>

using namespace std;

// Estructura del nodo – componente principal de la lista
template <class T>
struct Node {
    T data;
    Node *next;
    Node(T x, Node* h): data(x), next(h) {}
};

// Estructura de la lista ligada
template <class T>
struct List {
    Node<T> *head = NULL;

    // Inserta un elemento al final de la lista | O(n)
    void insert(T value) {
        Node<T>* nuevoNodo = new Node<T>(value, NULL);
        Node<T>* ptN = head;
        if(!head) {
            head = nuevoNodo;
            return;
        }
        while(ptN->next) ptN = ptN->next;
        ptN->next = nuevoNodo;
    }

    // Imprime los elementos de la lista | O(n)
    void print() {
        Node<T>* ptN = head;
        while(ptN) {
            cout << ptN->data << endl;
            ptN = ptN->next;
        }
    }
};


int main() {
    List<int> listM, listN;
    int m, n, input;
    string equal;

    // Input
    cin >> m;
    for(int i = 0; i < m; ++i) {
        cin >> input;
        listM.insert(input);
    }
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> input;
        listN.insert(input);
    }

    // Revertir listas
    listN.reverse();
    listM.reverse();

    // Concatenar listas
    List<int> fullList = listN + listM;

    // Comparar listas
    listN == listM ? equal = "true" : equal = "false";

    // Output
    listM.print();
    listN.print();
    fullList.print();
    cout << equal << endl;
    return 0;
}
