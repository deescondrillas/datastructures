// Act 3.4 – 28 de octubre, 2025
// Clase AVL

#pragma once

#include <iostream>
#include "Node.h"

// borrar despues
#include <string>
#include <queue>

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

    // Imprime k datos de mayor a menor         | O(k log₂n)
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

    // Insertar elemento en el AVL              | O(log₂n)
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

    // Genera las rotaciones pertinentes        | O(1)
    Node<T>* avl(Node<T>* p) {
        if(abs(update(p)) < 2) return p;
        // Representar principales con x, y, z
        Node<T> *x, *y, *z;
        // Identificar variante del problema
        int var;
        if(update(p) > 0) update(p->right) > 0 ? var = 1 : var = 2;
        if(update(p) < 0) update(p->left) < 0 ? var = 3 : var = 4;
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

// A partir de aqui nada es necesario para la entrega. Solo pinta el arbol

    // Obtener altura del arbol                 | O(n)
    int deep(int level = 1, Node<T>* p = nullptr) {
        p ? p : p = root;
        int mx = level;
        if(p->left) mx = max(mx, deep(level + 1, p->left));
        if(p->right) mx = max(mx, deep(level + 1, p->right));
        return mx;
    }

    // Obtener potencia de dos                  | O(k)
    int pow2(int k = 0) {
        return k ? pow2(k - 1) << 1 : 1;
    }

    // Imprimir cada subrenglon del arbol       | O(n)
    void print(int level = 0, string x = "--", bool line = false) {
        char o;
        int spaces = pow2(level);
        line ?  o = '_' :  o = ' ';
        for(int i = 1; i < spaces; ++i) i > spaces/2 + 1 ? cout << o : cout << ' ';
        x.size() < 2 ? cout << '0' + x : cout << x;
        for(int i = 1; i < spaces; ++i) i < spaces/2 - 1 ? cout << o : cout << ' ';
    }

    // Imprimir arbol                           | O(?)
    void tree() {
        int num(0), level(deep()), h(level);
        queue<Node<T>*> level0, level1;
        queue<Node<T>*>  *zero(&level0), *one(&level1), *temp;
        zero->push(root);
        // Repetir cada nivel
        while(level) {
            // Imprimir nivel
            while(zero->size()) {
                Node<T>* ptn = zero->front(); zero->pop();
                ptn ? print(level, to_string(++num % 100)) : print(level);
                ptn ? one->push(ptn->left) : one->push(NULL);
                ptn ? one->push(ptn->right) : one->push(NULL);
            }
            temp = &(*zero);
            zero = &(*one);
            one = &(*temp);
            // Imprimir coneccion
            cout << endl;
            if(level == 1) break;
            for(int i = 0; i < pow2(h - level); ++i) print(level, "/\\", 1);
            cout << endl;
            --level;
            for(int i = 0; i < pow2(h - level) / 2; ++i) {
                print(level, " /");
                print(level, "\\ ");
            }
            cout << endl;
        }
    }

    private:
        Node<T>* root = nullptr;
};
