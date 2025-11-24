// Act 4.3 – 23 de noviembre, 2025
// Clase IP

#pragma once

#include "List.h"

template <class T>
class Ip {
    public:
        // Constructor
        Ip(int x = -1, int y = -1, T* node = nullptr) {
            if(node) this->adj.insert(*node);
            outDeg = node ? 1 : 0;
            this->dirOne = x;
            this->dirTwo = y;
        }

        // Compare IPs              | O(1)
        bool operator < (const Ip& otherIp) const {
            if(dirOne == otherIp.dirOne) return dirTwo < otherIp.dirTwo;
            return dirOne < otherIp.dirOne;
        }

        // Compare IPs              | O(1)
        bool operator == (const Ip& otherIp) const {
            return dirOne == otherIp.dirOne && dirTwo == otherIp.dirTwo;
        }

        // Print IP                 | O(1)
        void print() {
            cout << dirOne << '.' << dirTwo;
        }

        // Merge identical IPs      | O(1)
        void merge(Ip<T>& node) {
            this->adj.merge(node.adj);
            outDeg += node.degree();
        }

        // Adjacent list mergesort  | O(n log₂n)
        void mergesort() {
            adj.mergesort();
        }

        int degree() {
            return outDeg;
        }

    private:
        List<T> adj;
        int dirOne = -1;
        int dirTwo = -1;
        int outDeg = 0;

    template <class> friend class List;
    friend class Graph;
};
