// Act 3.4 – 28 de octubre, 2025
// Clase AVL

#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class AVL {
    public:
    // Insertar elemento en el AVL                          | O(log₂n)
    void insert(T value, Node<T>* p = NULL) {
        Node<T>* newNode = new Node<T>(value, p);
        Node<T>* child = newNode;
        p ? p : p = root;
        if(!root) {
            root = newNode;
            return;
        }
        // Insertar a la izquierda
        if(value < p->data) {
            if(p->left) {
                insert(value, p->left);
                child = p->left;
            }
            else p->left = newNode;
        }
        // Insertar a la derecha
        if(value > p->data) {
            if(p->right) {
                insert(value, p->right);
                child = p->right;
            }
            else p->right = newNode;
        }
        // Revisar y realizar rotaciones
        if(p->height < child->height + 1) p->height += 1;
        p = avl(p);
    }

    // Genera las rotaciones pertinentes                    | O(log₂n)*
    Node<T>* avl(Node<T>* p) {
        if(p->height < 2) return p;
        // Esta función recibe un nodo (el padre), y regresa
        // el nodo padre después de hacer la rotación
        return p;
    }

    // Imprime k datos de mayor a menor                     | O(k log₂n)
    int inordenC(int k = 0, Node<T>* p = NULL) {
        if(!k) return k;
        p ? p : p = root;
        if(p->right) k = inordenC(k, p->right);
        if(!k) return k;
        p->data.print();
        --k;
        if(p->left) k = inordenC(k, p->left);
        return k;
    }

    private:
        Node<T>* root = NULL;
};
