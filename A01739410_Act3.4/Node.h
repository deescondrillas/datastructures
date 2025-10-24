// Act 3.4 – 28 de octubre, 2025
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

    private:
        T data;
        int height = 0;
        Node* left = nullptr;
        Node* right = nullptr;

    template <class> friend class AVL;
};
