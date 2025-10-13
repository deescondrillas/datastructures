// Act 2.3 – 15 de octubre, 2025
// Clase List

#pragma once

#include "Node.h"
#include <iostream>

using namespace std;

template <class T>
class List {
    public:
        // Constructor
        List() {

        }
        // Inserta elementos en orden | O(n)
        void insert(T value) {

        }
        // Imprime los elementos de la lista | O(n)
        void print() {
            string out = "";
            Node<T>* ptN = head;
            while(ptN) {
                ptN->data().write(out);
                ptN = ptN->next;
            }
            cout << out << endl;
        }

    private:
        Node<T>* head = NULL;
        Node<T>* tail = NULL;
};
