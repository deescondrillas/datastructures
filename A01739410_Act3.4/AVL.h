// Act 3.4 – 28 de octubre, 2025
// Clase AVL

#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class AVL {
    public:
    // Obtiene la diferencia de alturas                     | O(1)
    int delta(Node<T>* p) {
        int dif(0);
        if(p->right) dif = p->right->height + 1;
        if(p->left) dif -= p->left->height + 1;
        return dif;
    }

    // Actualiza la altura de un nodo                       | O(1)
    void update(Node<T>* p) {
        int hl, hr;
        p->left ? hl = p->left->height : hl = -1;
        p->right ? hr = p->right->height : hr = -1;
        p->height = max(hl, hr) + 1;
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

    // Insertar elemento en el AVL                          | O(log₂n)
    void insert(T value, Node<T>** p = nullptr) {
        Node<T>* newNode = new Node<T>(value);
        Node<T>** child = &newNode;
        p ? p : p = &root;
        if(!root) {
            root = newNode;
            return;
        }
        // Insertar a la izquierda
        if(value < (*p)->data) {
            if((*p)->left) {
                insert(value, &(*p)->left);
                child = &(*p)->left;
            }
            else (*p)->left = newNode;
        }
        // Insertar a la derecha
        if(value > (*p)->data) {
            if((*p)->right) {
                insert(value, &(*p)->right);
                child = &(*p)->right;
            }
            else (*p)->right = newNode;
        }
        // Revisar y realizar rotaciones
        *p = avl(*p);
        update(*p);
    }

    // Genera las rotaciones pertinentes                    | O(1)
    Node<T>* avl(Node<T>* p) {
        if(abs(delta(p)) < 2) return p;
        // Representar principales con x, y, z
        Node<T> *x, *y, *z;
        // Identificar variante del problema
        int var;
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
        Node<T> *a, *b, *c, *d;
        x->left ? a = x->left : a = nullptr;
        y->left ? b = y->left : b = nullptr;
        y->right ? c = y->right : c = nullptr;
        z->right ? d = z->right : d = nullptr;
        // Modificacion de casos 1 y 3
        if(var == 1) z->left ? c = z->left : c = nullptr;
        if(var == 3) x->right ? b = x->right : b = nullptr;
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

    // Para visualizar el arbol, se imprime padre e hijo cada elemento
    void nodes(int parent = 1, Node<T>* p = nullptr) {
        int l, r;
        p ? p : p = root;
        cout << parent << ' ';
        if(p->left) {
            cout << "l(" << ++node << ") ";
            l = node;
        }
        if(p->right) {
            cout << "r(" << ++node << ") ";
            r = node;
        }
        cout << endl;
        if(p->left) nodes(l, p->left);
        if(p->right) nodes(r, p->right);
    }

    private:
        Node<T>* root = nullptr;
        int node = 1;
};
