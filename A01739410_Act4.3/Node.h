// Act 4.3 – 23 de noviembre, 2025
// Clase Node

#pragma once

class NodeBase {
    public:
        virtual ~NodeBase() {}
    };

    template <class T>
    class Node : public NodeBase {
        public:
            // Constructor
            Node() {}  // constructor por defecto
            Node(T _val) {
                data = _val;
                capacity = 10;
                children = new NodeBase*[capacity];
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
            void add(NodeBase* child) {
                if (childs == capacity) {
                    capacity *= 2;
                    NodeBase** nuevo = new NodeBase*[capacity];
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
            NodeBase** children;
            int childs;
            int capacity;
            T data;

        template <class> friend class Graph;
};
