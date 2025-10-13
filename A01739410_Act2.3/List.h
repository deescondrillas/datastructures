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
        // Inserta elementos al final | O(1)
        void insert(T value) {
            Node<T>* newNode = new Node<T>(value, tail, NULL);
            if(!head) head = newNode;
            tail = newNode;
        }
        // Imprime los elementos de la lista | O(n)
        string print() {
            string out = "";
            Node<T>* ptN = head;
            while(ptN) {
                ptN->data.write(out);
                ptN = ptN->next;
            }
            out.pop_back();
            return out;
        }

    private:
        Node<T>* head = NULL;
        Node<T>* tail = NULL;
};
