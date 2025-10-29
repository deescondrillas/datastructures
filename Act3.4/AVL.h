// Act 3.4 – 28 de octubre, 2025
// Clase AVL

#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class AVL {
    public:
    // Actualiza la altura de un nodo           | O(1)
    // Regresa la Δh entre sus hijos
    int update(Node<T>* p) {
        int hl, hr;
        p->left ? hl = p->left->height : hl = -1;
        p->right ? hr = p->right->height : hr = -1;
        p->height = max(hl, hr) + 1;
        return hr - hl;
    }
    // Δh > 0 cuando domina derecha
    // Δh < 0 cuando domina izquierda

    // Imprime k datos de mayor a menor         | O(k log₂n)
    int inordenC(int k = 0, Node<T>* p = nullptr) {
        if(!p) p = root;
        // Derecha
        if(p->right) k = inordenC(k, p->right);
        if(!k--) return 0;
        // Raiz
        p->data.print();
        //Izquierda
        if(p->left) k = inordenC(k, p->left);
        return k;
    }

    // Insertar elemento en el AVL              | O(log₂n)
    void insert(T value, Node<T>** p = nullptr) {
        Node<T>* newNode = new Node<T>(value);
        if(!root) root = newNode;
        if(!p) p = &root;
        // Insertar a la izquierda
        if(value < (*p)->data) {
            if((*p)->left) insert(value, &(*p)->left);
            else (*p)->left = newNode;
        }
        // Insertar a la derecha
        if(value > (*p)->data) {
            if((*p)->right) insert(value, &(*p)->right);
            else (*p)->right = newNode;
        }
        // Revisar y realizar rotaciones
        *p = avl(*p);
        update(*p);
    }

    // Genera las rotaciones pertinentes        | O(1)
    Node<T>* avl(Node<T>* p) {
        if(abs(update(p)) < 2) return p;
        // Representar principales con x, y, z
        Node<T> *x(p), *y(p), *z(p);
        // Identificar variante del problema
        int var;
        if(update(p) > 0) update(p->right) > 0 ? var = 1 : var = 2;
        if(update(p) < 0) update(p->left) < 0 ? var = 3 : var = 4;
        // Asignar caso
        switch(var) {
            case 1:
                y = x->right;
                z = y->right;
                break;
            case 2:
                z = x->right;
                y = z->left;
                break;
            case 3:
                y = z->left;
                x = y->left;
                break;
            case 4:
                x = z->left;
                y = x->right;
                break;
            default:
                break;
        }
        // Asignar hijos de x, y, z
        Node<T> *a(x->left), *b(y->left), *c(y->right), *d(z->right);
        // Modificacion de casos 1 y 3
        if(var == 1) c = z->left;
        if(var == 3) b = x->right;
        // Generar rotacion
        y->left = x;
        y->right = z;
        x->left = a;
        x->right = b;
        z->left = c;
        z->right = d;
        // Actualizar alturas
        update(x);
        update(z);
        update(y);
        // Regresar nuevo padre
        return y;
    }

    private:
        Node<T>* root = nullptr;
};
