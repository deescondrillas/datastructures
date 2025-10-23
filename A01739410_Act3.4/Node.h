// Act 3.4 – 26 de octubre, 2025
// Clase Node

#pragma once

template <class T>
class Node {
    public:
        // Constructor
        Node(T _val, Node* _left, Node* _right) {
            data = _val;
            left = _left;
            right = _right;
            height = 0;
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
        int height;
        Node* left;
        Node* right;

    template <class> friend class AVL;
};
