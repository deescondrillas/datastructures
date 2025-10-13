// Act 2.3 – 15 de octubre, 2025
// Clase Node

#pragma once

using namespace std;

template <class T>
class Node {
    public:
        // Constructor
        Node(T _val, Node* _prev, Node* _next) {
            data = _val;
            prev = _prev;
            next = _next;
        }
        // Comparar nodos
        bool operator < (const Node<T>& otherNode) const {
            return data < otherNode.data;
        }

    private:
        T data;
        Node* next;
        Node* prev;

    template <class> friend class List;
};
