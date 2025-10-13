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
            Node<T>* newNode = new Node<T>(value, NULL, NULL);
            Node<T>* ptN = head;
            // Lista vacia
            if(!head) {
                head = newNode;
                tail = newNode;
                return;
            }
            // Recorrer y comparar (dos o mas)
            while(ptN) {
                if(newNode->data < ptN->data) {
                    // Lazos previos
                    if(ptN->prev) {
                        ptN->prev->next = newNode;
                        newNode->prev = ptN->prev;
                    }
                    else head = newNode;
                    // Lazos siguientes
                    newNode->next = ptN;
                    ptN->prev = newNode;
                    return;
                }
                ptN = ptN->next;
            }
            // El elemento es mayor a todos
            ptN = newNode;
            newNode->prev = ptN;
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
