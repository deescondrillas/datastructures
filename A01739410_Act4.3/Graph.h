// Act 4.3 – 23 de noviembre, 2025
// Clase Graph

#pragma once
#include "Node.h"
#include "Red.h"
#include "Host.h"
#include "Log.h"

template <class T>
class Graph {
    public:
        //Constructor
        Graph() {
            capRedes = 10;
            nRedes = 0;
            redes = new Node<Red>*[capRedes];
        }

        // Obtener o crear red
        Node<Red>* RedManager(int ip1, int ip2){
            // Busca la red
            for(int i = 0; i < nRedes; i++){
                if (redes[i] -> data.ip1 == ip1 &&
                    redes[i]->data.ip2 == ip2){
                    return redes[i];
                }
            }
            // Si no existe la crea
            if(nRedes == capRedes){
                capRedes *= 2;
                Node<Red>** temp = new Node<Red>*[capRedes];
                for(int i = 0; i < nRedes; i++) temp[i] = redes[i];
                delete[] redes;
                redes = temp;
            }

            Node<Red>* nuevaRed = new Node<Red>(Red(ip1, ip2));
            redes[nRedes++] = nuevaRed;
            return nuevaRed;
        }

        // Obtener o crear hosts
        Node<Host>* HostManager(Node<Red>* redNode, int ip3, int ip4){
            for (int i = 0; i < redNode -> childs; i++){
                Node<Host>* h = redNode -> children[i];
                if (h -> data.ip3 == ip3 && h -> data.ip4 == ip4){
                    return h;
                }
            }

            Node<Host>* nuevoHost = new Node<Host>(Host(ip3, ip4));
            redNode -> add(nuevoHost);
            return nuevoHost;
        }

        // Funcion para insertar un nodo al grafo, o bien encontrar el nodo si este ya existe
        void insert() {

        }
    private:
        Node<T> root;       // Nodo raiz
        Node<Red>** redes;  // "Vector" de redes
        int nRedes;
        int capRedes;
};
