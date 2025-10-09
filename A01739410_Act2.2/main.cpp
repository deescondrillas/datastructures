// Act 2.1 – 2 de octubre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A01739522 – Sergio Sebastian Cortez Yepez
// A01739190 - Carlos Arturo Ferat Torres

#include <iostream>

using namespace std;

// Estructura del nodo – componente principal de la lista
template <class T>
struct Nodo {
    T data;
    Nodo *next;
    Nodo(T x, Nodo* h): data(x), next(h) {}
};

// Estructura de la lista ligada – contiene las funciones para insertar y eliminar
template <class T>
struct Lista {
    Nodo<T> *head = NULL;

    // Inserta un elemento al inicio de la lista ligada | O(1)
    void Inserta_al_inicio(T value) {
        Nodo<T>* nuevoNodo = new Nodo<T>(value, head);
        head = nuevoNodo;
        return;
    }

    // Inserta un elemento al final de la lista ligada | O(n)
    void Inserta_al_final(T value) {
        Nodo<T>* nuevoNodo = new Nodo<T>(value, NULL);
        Nodo<T>* ptN = head;
        if(!head) {
            head = nuevoNodo;
            return;
        }
        while(ptN->next) ptN = ptN->next;
        ptN->next = nuevoNodo;
    }

    // Elimina un elemento al inicio de la lista | O(1)
    void Elimina_al_inicio() {
        Nodo<T>* ptN = head;
        if(!head) {
            cout << "ERROR" << endl;
            return;
        }
        head = head->next;
        delete ptN;
    }

    // Elimina un elemento al final de la lista ligada | O(n)
    void Elimina_al_final() {
        Nodo<T>* ptN = head;
        if(!head) {
            cout << "ERROR" << endl;
            return;
        }
        if(!head->next) {
            head = NULL;
            delete ptN;
            return;
        }
        while(ptN->next->next) ptN = ptN->next;
        Nodo<T>* ptE = ptN->next;
        ptN->next = NULL;
        delete ptE;
    }

    // Imprime los elementos de la lista | O(n)
    void Imprime() {
        Nodo<T>* ptN = head;
        while(ptN) {
            cout << ptN->data << endl;
            ptN = ptN->next;
        }
    }
};


int main() {
    int opcion(1), valor(0);
    Lista<int> list;

    // Menu ciclado
    while (opcion) {
        cin >> opcion;
        switch (opcion) {
            // Salir del programa
            case 0:
                break;
            // Insertar al inicio | O(1)
            case 1:
                cin >> valor;
                list.Inserta_al_inicio(valor);
                break;
            // Insertar al final | O(n)
            case 2:
                cin >> valor;
                list.Inserta_al_final(valor);
                break;
            // Eliminar al inicio | O(1)
            case 3:
                list.Elimina_al_inicio();
                break;
            // Eleminar al final | O(n)
            case 4:
                list.Elimina_al_final();
                break;
            // Imprimir la lista | O(n)
            case 5:
                list.Imprime();
                break;
        }
    }
    return 0;
}
