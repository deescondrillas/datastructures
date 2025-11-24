// Act 4.3 – 23 de noviembre, 2025
// Clase Node

#pragma once

template <class T>
class Node {
    public:
        // Constructor
        Node(T _val, Node* _prev, Node* _next) {
            this->data = _val;
            this->prev = _prev;
            this->next = _next;
        }

        // Comparar nodos
        bool operator < (const Node<T>& otherNode) const {
            return data < otherNode.data;
        }

        // Comparar nodos
        bool operator == (const Node<T>& otherNode) const {
            return data == otherNode.data;
        }

        // Mergesort
        void mergesort() {
            return;
        }

        // Get degree
        int degree() {
            return data.degree();
        }

        // Print node
        void print() {
            data.print();
        }

    private:
        T data;
        Node* prev;
        Node* next;

    friend class Graph;
    template <class> friend class List;
};
