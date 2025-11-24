// Act 4.3 – 23 de noviembre, 2025
// Clase List

#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class List {
    public:
        // Constructor                      | O(1)
        List(Node<T>* _head = NULL, Node<T>* _tail = NULL) {
            head = _head;
            tail = _tail;
        }

        // Insercion de elementos al final  | O(1)
        void insert(T value) {
            Node<T>* newNode = new Node<T>(value, tail, NULL);
            if(!head) head = newNode;
            else tail->next = newNode;
            tail = newNode;
        }

        // Merge de nodos similares         | O(1)
        void merge(List<T>& otherList) {
            if(!otherList.head) return;
            if(!head) {
                head = otherList.head;
                tail = otherList.tail;
            } else {
                tail->next = otherList.head;
                otherList.head->prev = tail;
                tail = otherList.tail;
            }
            otherList.head = nullptr;
            otherList.tail = nullptr;

        }

        // Ordenamiento ascendentemente     | O(n log₂n)
        void mergesort() {
            // Condicion base
            if (head == tail) return;

            // Recorrido a la mitad
            Node<T> *slowP(head), *fastP(head);
            while(fastP->next) {
                fastP = fastP->next;
                if(fastP->next) {
                    fastP = fastP->next;
                    slowP = slowP->next;
                }
            }

            // Separacion de listas
            List<T> newList(slowP->next, tail);
            tail = slowP;
            tail->next->prev = NULL;
            tail->next = NULL;

            // Llamada recursiva
            newList.mergesort();
            mergesort();

            // Union de listas
            Node<T> *ptL1(head), *ptL2(newList.head);
            Node<T> **ptMin;
            head = tail = NULL;
            while(ptL1 && ptL2) {
                // Merge de listas
                if(ptL1->data == ptL2->data) {
                    ptL1->data.merge(ptL2->data);
                    ptMin = &ptL1;
                }
                // Insercion del primer elemento
                else if(ptL1->data < ptL2->data) ptMin = &ptL1;
                else ptMin = &ptL2;

                // Lista vacia
                if(!head) {
                    head = *ptMin;
                    tail = *ptMin;
                }
                // Lista con elementos
                else {
                    tail->next = *ptMin;
                    (*ptMin)->prev = tail;
                    tail = tail->next;
                }
                *ptMin = (*ptMin)->next;
            }
            // Union con lista sobrante
            if(ptL1) {
                tail->next = ptL1;
                ptL1->prev = tail;
            } else {
                tail->next = ptL2;
                ptL2->prev = tail;
            }
            // Recorrer tail al final
            while(tail->next) tail = tail->next;
        }

    private:
        Node<T>* head = NULL;
        Node<T>* tail = NULL;

    friend class Graph;
    template <class> friend class Ip;
};
