// Act 2.3 – 15 de octubre, 2025
// Clase List

#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class List {
    public:
        // Constructor
        List(Node<T>* _head = NULL, Node<T>* _tail = NULL) {
            head = _head;
            tail = _tail;
        }

        // Insercion de elementos al final | O(1)
        void insert(T value) {
            Node<T>* newNode = new Node<T>(value, tail, NULL);
            if(!head) head = newNode;
            else tail->next = newNode;
            tail = newNode;
        }

        // Ordenamiento ascendentemente | O(n log₂n)
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

            // Separacion de listas O(1)
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
                // Insercion del primer elemento
                if(ptL1->data < ptL2->data) ptMin = &ptL1;
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

        // Busqueda lineal | O(n)
        string search(T left, T right) {
            string out = "";
            // Recorrer izquierda
            Node<T> *ptStart(head), *ptEnd(tail);
            while(ptStart->data < left && ptStart->next) ptStart = ptStart->next;
            // Recorrer derecha
            ptEnd = ptStart;
            while(ptEnd->data < right && ptEnd->next) ptEnd = ptEnd->next;
            if(right < ptEnd->data) ptEnd = ptEnd->prev;
            // Imprimir ascendente
            while(ptEnd->next != ptStart) {
                ptEnd->data.write(out);
                ptEnd = ptEnd->prev;
                if(ptEnd == NULL) break;
            }
            return out;
        }

        // Impresion de lista | O(n)
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
