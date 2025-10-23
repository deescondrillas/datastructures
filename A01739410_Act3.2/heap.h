#pragma once
#include <iostream>

using namespace std;

template <class T>
class Heap {
    public:
        // Define el tipo de heap                   | O(1)
        bool priority(T a, T b) {
            return a > b; // max heap
            return a < b; // min heap
        }
        // Swapea nodos hasta formar un heap        | O(log₂n)
        void heapify(int p = 0) {
            int childL(2 * p + 1), childR(2 * p + 2), mxe(heap[p]), mxp(p);
            // heapifea hijo izquierdo
            if(childL < sz) {
                heapify(childL);
                if(priority(heap[childL], mxe)) {
                    mxp = childL;
                    mxe = heap[mxp];
                }
            }
            // heapifea hijo derecho
            if(childR < sz) {
                heapify(childR);
                if(priority(heap[childR], mxe)) {
                    mxp = childR;
                    mxe = heap[mxp];
                }
            }
            // swapea y heapifea otra vez
            if(mxp - p) {
                heap[mxp] = heap[p];
                heap[p] = mxe;
                heapify(mxp);
            }
        }
        // Inserta un elemento y heapifea           | O(log₂n)
        void push(T val) {
            heap[sz++] = val;
            heapify();
        }
        // Elimina un elemento y heapifea           | O(log₂n)
        void pop() {
            heap[0] = heap[--sz];
            heapify();
        }
        // Regresa el valor con mayor prioridad     | O(1)
        T top() {
            return heap[0];
        }
        // Regresa true si el heap está vacío
        // o false si no lo está                    | O(1)
        bool empty() {
            return !sz ? true : false;
        }
        // Regresa el tamaño del heap               | O(1)
        int size() {
            return sz;
        }
        // Imprime todo el heap                     | O(n)
        void print() {
            for(int i = 0; i < sz; ++i) cout << heap[i] << ' ';
            cout << endl;
        }
        // Ordena los elementos por prioridad       | O(n log₂n)
        void heapsort() {
            int temp = sz;
            T sorted[temp];
            for(int i = 0; i < temp; ++i) {sorted[i] = top(); pop();}
            for(int i = 0; i < temp; ++i) push(sorted[i]);
        }
        // Imprime cada nodo con sus hijos          | O(n)
        void nodes() {
            for(int i = 0; i < sz; ++i) {
                if(2 * i >= sz) break;
                if(2 * i + 1 < sz) cout << heap[i] << " l(" << heap[2 * i + 1] << ')';
                if(2 * i + 2 < sz) cout << " r(" << heap[2 * i + 2] << ")";
                cout << endl;
            }
        }

    private:
        T heap[1024];
        int sz = 0;
};
