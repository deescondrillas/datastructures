// Act 3.4 – 28 de octubre, 2025
// Clase AVL

#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class AVL {
    public:
    // Regresa la raiz para insertar desde ahí              | O(1)
    Node<T>* r() {
        return root;
    }

    // Insertar elemento en el AVL                          | O(log₂n)
    void insert(T value, Node<T>* &p = nullptr) {
        Node<T>* newNode = new Node<T>(value);
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
        p = avl(p);
        if(p->height < child->height + 1) p->height += 1;
    }

    // Genera las rotaciones pertinentes                    | O(log₂n)*
    Node<T>* avl(Node<T>* p) {
        if(abs(delta(p)) < 2) return p;
        // Representar principales con x, y, z
        Node<T> *x, *y, *z, *a(NULL), *b(NULL), *c(NULL), *d(NULL);
        // Variantes 1 y 2
        if(delta(p) > 0) {
            x = p;
            // Caso 1
            if(delta(x->right) > 0) {
                y = x->right;
                z = y->right;
                if(x->left) a = x->left;
                if(y->left) b = y->left;
                if(z->left) c = z->left;
                if(z->right) d = z->right;
            }
            // Caso 2
            else {
                z = x->right;
                y = z->left;
                if(x->left) a = x->left;
                if(y->left) b = y->left;
                if(y->right) c = y->right;
                if(z->right) d = z->right;
            }
        }
        // Variantes 3 y 4
        else {
            z = p;
            // Caso 3
            if(delta(z->left) < 0) {
                y = z->left;
                x = y->left;
                if(x->left) a = x->left;
                if(x->right) b = x->right;
                if(y->right) c = y->right;
                if(z->right) d = z->right;
            }
            // Caso 4
            else {
                x = z->left;
                y = x->right;
                if(x->left) a = x->left;
                if(y->left) b = y->left;
                if(y->right) c = y->right;
                if(z->right) d = z->right;
            }
        }
        // Generar rotación
        y->left = x;
        y->right = z;
        x->left = a;
        x->right = b;
        z->left = c;
        z->right = d;
        return y;
    }

    // Imprime k datos de mayor a menor                     | O(k log₂n)
    int inordenC(int k = 0, Node<T>* p = nullptr) {
        if(!k) return k;
        p ? p : p = root;
        if(p->right) k = inordenC(k, p->right);
        if(!k) return k;
        p->data.print();
        --k;
        if(p->left) k = inordenC(k, p->left);
        return k;
    }

    // Obtiene la diferencia de alturas
    int delta(Node<T>* p) {
        int dif(0);
        if(p->right) dif = p->right->height;
        if(p->left) dif -= p->left->height;
        return dif;
    }

    // private:
        Node<T>* root = nullptr;
};
