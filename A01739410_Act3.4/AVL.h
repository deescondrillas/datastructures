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
    void insert(T value, Node<T>** p = nullptr) {
        Node<T>* newNode = new Node<T>(value);
        Node<T>* child = newNode;
        p ? p : p = &root;
        if(!root) {
            root = newNode;
            return;
        }
        // Insertar a la izquierda
        if(value < (*p)->data) {
            if((*p)->left) {
                insert(value, &(*p)->left);
                child = (*p)->left;
            }
            else (*p)->left = newNode;
        }
        // Insertar a la derecha
        if(value > (*p)->data) {
            if((*p)->right) {
                insert(value, &(*p)->right);
                child = (*p)->right;
            }
            else (*p)->right = newNode;
        }
        // Revisar y realizar rotaciones
        (*p) = avl(*p);
        if((*p)->height < child->height + 1) (*p)->height += 1;
    }

    // Genera las rotaciones pertinentes                    | O(log₂n)*
    Node<T>* avl(Node<T>* p) {
        if(abs(delta(p)) < 2) return p;
        // Representar principales con x, y, z
        Node<T> *x, *y, *z;
        // Identificar variante del problema
        int ha(0), hb(0), hc(0), hd(0), var(0);
        if(delta(p) > 0) delta(p->right) > 0 ? var = 1 : var = 2;
        if(delta(p) < 0) delta(p->left) < 0 ? var = 3 : var = 4;
        // Asignar caso
        switch(var) {
            case 1:
                x = p;
                y = x->right;
                z = y->right;
                break;
            case 2:
                x = p;
                z = x->right;
                y = z->left;
                break;
            case 3:
                z = p;
                y = z->left;
                x = y->left;
                break;
            case 4:
                z = p;
                x = z->left;
                y = x->right;
                break;
            default:
                cout << "ERROR" << endl;
                break;
        }
        // Asignar hijos de x, y, z
        Node<T> *a(NULL), *b(NULL), *c(NULL), *d(NULL);
        x->left ? a = x->left : NULL;
        y->left ? b = y->left : NULL;
        y->right ? c = y->right : NULL;
        z->right ? d = z->right : NULL;
        // Modificacion de casos 1 y 3
        if(var == 1) z->left ? c = z->left : c = NULL;
        if(var == 3) x->right ? b = x->right : b = NULL;
        // Generar rotacion
        y->left = x;
        y->right = z;
        x->left = a;
        x->right = b;
        z->left = c;
        z->right = d;
        // Actualizar alturas
        a ? ha = a->height : --ha;
        b ? hb = b->height : --hb;
        c ? hc = c->height : --hc;
        d ? hd = d->height : --hd;
        x->height = max(ha, hb) + 1;
        z->height = max(hc, hd) + 1;
        y->height = max(x->height, z->height) + 1;
        // Regresar nuevo padre
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
        int v = 0;
};
