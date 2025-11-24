// Act 4.3 – 23 de noviembre, 2025
// Clase Node

#pragma once

template <class T>
class Node {
    public:
        // Constructor
        Node(T _val) {
            data = _val;
            capacity = 10;
            children = new Node<T>*[capacity];
            childs = 0;
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
            if (childs == capacity) {
                capacity *= 2;
                Node<T>** nuevo = new Node<T>*[capacity];

                for (int i = 0; i < childs; i++) nuevo[i] = children[i];

                delete[] children;
                children = nuevo;
            }

            children[childs++] = child;
        }

        int getChilds(){
            return childs;
        }

    private:
        Node<T>** children;
        int childs;
        int capacity;
        T data;

    template <class> friend class Graph;
};
