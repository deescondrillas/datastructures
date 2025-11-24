// Act 4.3 – 23 de noviembre, 2025
// Clase Node

#pragma once

template <class T>
class Node {
    public:
        // Constructor
        Node(T _val) {
            data = _val;
        }

        // Comparar nodos
        bool operator > (const Node<T>& otherNode) const {
            return data > otherNode.data;
        }

        // Comparar nodos
        bool operator < (const Node<T>& otherNode) const {
            return data < otherNode.data;
        }

        // Agregar hijo
        void add(Node child) {
            adj[childs] = child;
            childs++;
        }

    private:
        Node* adj = nullptr;
        int childs = 0;
        T data;

    template <class> friend class Graph;
};
