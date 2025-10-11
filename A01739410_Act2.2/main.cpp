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

// Concatena dos listas N (longitud n) y M (longitud m) | O(n)
template <class T>
void concat(List<T>& a, List<T>& b) {
    Node<T>* ptN = a.head;
    // Lista vacia
    if(!ptN) {
        a.head = b.head;
        return;
    }
    // Lista con elementos
    while(ptN->next) ptN = ptN->next;
    ptN->next = b.head;
}

// Revierte una lista | O(n)
template <class T>
List<T> reverse(Node<T>* ptN) {
    List<T> newList;
    newList.head = ptN;
    // Lista vacia
    if(!ptN) {
        newList.head = NULL;
        return newList;
    }
    // Transicion
    if(ptN->next) {
        newList = reverse(ptN->next);
        ptN->next->next = ptN;
        ptN->next = NULL;
    }
    return newList;
}

//revisa si dos listas son igualess | O(n)
template <class T>
bool equals(List<T> *ptL1, List<T> *ptL2) {
    Node<T> * tmp1 = ptL1->head;
    Node<T> * tmp2 = ptL2->head;

    while(tmp1 && tmp2) {
        if(tmp1->data != tmp2->data) return false;
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    if(tmp1 || tmp2) return false;
    return true;
}

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
    listN = reverse(listN.head);
    listM = reverse(listM.head);

    // Output
    listM.print();
    listN.print();

    // Comparar listas
    equals(&listM, &listN) ? equal = "true" : equal = "false";

    // Concatenar listas
    concat(listN, listM);

    //Output Concat y Compare
    listN.print();
    cout << equal << endl;

    return 0;
}
