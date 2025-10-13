// Act 2.3 – 15 de octubre, 2025
// Clase Node

#pragma once

using namespace std;

template <class T>
class Node {
    public:
        // Constructor
        Node(T _val, Node* _prev, Node* _next) {
            value = _val;
            prevNode = _prev;
            nextNode = _next;
        }
        // Getters
        T data() {
            return value;
        }
        Node* next() {
            return nextNode;
        }
        Node* prev() {
            return prevNode;
        }
        // Comparar nodos
        bool operator < (const T& otherNode) const {
            return value < otherNode.data();
        }

    private:
        T value;
        Node* nextNode;
        Node* prevNode;

};
