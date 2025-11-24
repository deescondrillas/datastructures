// Act 4.3 – 23 de noviembre, 2025
// Clase Graph

#pragma once

#include "Log.h"

class Graph {
    public:
        // Constructor                              | O(1)
        Graph() {

        }

        // Insertar nuevo nodo                      | O(1)
        void insert(Ip<Ip<Log>> ip) {
            network.insert(ip);
        }

        // Mergesort                                | O(n log₂n)
        void mergesort() {
            network.mergesort();
            Node<Ip<Ip<Log>>>* pointer = network.head;
            while(pointer) {
                pointer->data.adj.mergesort();
                pointer = pointer->next;
            }
        }

        // Print net with max degree                | O(n)
        void get_degree(int* dNet, int* dHost) {
            Node<Ip<Ip<Log>>>* net_node = network.head;
            Node<Ip<Log>>* host_node;
            while(net_node) {
                // Inside loop
                host_node = net_node->data.adj.head;
                while(host_node) {
                    *dHost = max(*dHost, host_node->degree());
                    host_node = host_node->next;
                }

                // Outside loop
                *dNet = max(*dNet, net_node->degree());
                net_node = net_node->next;
            }
        }

        // Print networks and hosts with max degree | O(n)
        void print(int* dNet, int* dHost) {
            // Net
            Node<Ip<Ip<Log>>>* net_node = network.head;
            // Outside loop
            while(net_node) {
                if(*dNet == net_node->degree()) {
                    net_node->print();
                    cout << endl;
                }
                net_node = net_node->next;
            }

            // Host
            cout << endl;
            net_node = network.head;
            Node<Ip<Log>>* host_node;
            // Inside loop
            while(net_node) {
                host_node = net_node->data.adj.head;
                while(host_node) {
                    if(*dHost == host_node->degree()) {
                        net_node->print();
                        cout << '.';
                        host_node->print();
                        cout << endl;
                    }
                    host_node = host_node->next;
                }
                net_node = net_node->next;
            }
        }

    private:
        List<Ip<Ip<Log>>> network;
};
