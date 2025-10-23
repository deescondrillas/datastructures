// Act 3.4 – 26 de octubre, 2025
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
        p ? p : p = root;
        Node<T>* newNode = new Node<T>(value, NULL, NULL);
        if(!root) {
            root = newNode;
            return;
        }
        // Insertar a la izquierda
        if(value < p->data) {
            --p->equi; // no siempre
            if(p->left) insert(value, p->left);
            else p->left = newNode;
        }
        // Insertar a la derecha
        if(value > p->data) {
            ++p->equi; // no siempre
            if(p->right) insert(value, p->right);
            else p->right = newNode;
        }
        // Checar equilibrio
        // ...
    }

    void avl(T value, Node<T>* p = NULL) {
        p ? p : p = root;
        Node<T>* newNode = new Node<T>(value, NULL, NULL);
        if(!root) {
            root = newNode;
            return;
        }
        if(value < p->data) {
            if(p->left) insert(value, p->left);
            else p->left = newNode;
        }
        if(value > p->data) {
            if(p->right) insert(value, p->right);
            else p->right = newNode;
        }
    }

    // Imprime datos de menor a mayor
    int inordenC(Node<T>* p = NULL, int k = 0) {
        if(!k) return 0;
        p ? p : p = root;
        if(p->right) k = inordenC(p->right, k);
        if(!k) return 0;
        cout << p->data << endl;
        if(p->left) k = inordenC(p->left, --k);
        return k;
    }

    private:
        Node<T>* root = NULL;
}
