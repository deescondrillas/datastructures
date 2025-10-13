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
        List(Node<T>* _head) {
            head = _head;
        }
        // Inserta elementos al final | O(1)
        void insert(T value) {
            Node<T>* newNode = new Node<T>(value, tail, NULL);
            if(!head) head = newNode;
            tail = newNode;
        }
        // Ordenar ascendentemente | O(n log₂n)
        void mergeSort() {
            //condicion base
            if (head == tail) return;

            Node<T>* slowP = head;
            Node<T>* fastP = head;

            //Recorrido a la mitad O(n)
            while(fastP -> next) {
                fastP = fastP -> next;
                slowP = slowP -> next;
                if(fastP -> next) fastP = fastP -> next;
            }

            // Separar listas
            slowP -> prev -> next = NULL;
            slowP -> prev = NULL;
            List<T> newList(slowP);

            // Llamada recursiva
            newList.mergeSort();
            mergeSort();

            // Unir listas
            Node<T> *ptL1(head), *ptL2(slowP);
            head = tail = NULL;
            while(ptL1 && ptL2) {
                // Insertar primer elemento
                if(ptL1->data < ptL2->data) {
                    // Lista vacia
                    if(!head) {
                        head = ptL1;
                        tail = ptL1;
                    }
                    // Lista con elementos
                    else {
                        tail->next = ptL1;
                        ptL1->prev = tail;
                        tail = tail->next;
                    }
                        ptL1 = ptL1->next;
                }
                else {
                     // Lista vacia
                    if(!head) {
                        head = ptL2;
                        tail = ptL2;
                    }
                    // Lista con elementos
                    else {
                        tail->next = ptL2;
                        ptL1->prev = tail;

                        tail = tail -> next;
                    }
                        ptL2 = ptL2->next;
                }
            }
            // Insertar lista sobrante
            if(ptL1) {
                tail->next = ptL1;
                ptL1->prev = tail;
                tail = tail->next;
            } else {
                tail->next = ptL2;
                ptL2->prev = tail;
                tail = tail->next;
            }
        }

        // Busqueda lineal | O(n)
        string search(string IP1, string IP2) {
            int ip1[4], ip2[4];
            return 'a';
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
