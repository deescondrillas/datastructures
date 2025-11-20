// Act 4.2 – 20 de noviembre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A01739522 – Sergio Sebastian Cortez Yepez
// A01739190 – Carlos Arturo Ferat Torres

#include "list.h"
#include "queue.h"

#include <iostream>
#include <string>

using namespace std;

// Funciones
bool topologicalSort(int, List<List<int>>&, string&);
void loadGraph(int, int, List<List<int>>&);
bool isTree(int, int, List<List<int>>&);
char itc(int);
int cti(char);

// Main
int main() {
    string topological;
    int n{0}, m{0};
    cin >> n >> m;
    // Crear lista de adyacencias
    List<List<int>> adj_list(n);
    // Cargar grafo
    loadGraph(n, m, adj_list);
    // Ordena topologicamente y determina si es un DAG
    if(topologicalSort(n, adj_list, topological)) {
        isTree(n, m, adj_list) ? cout << "True" << endl : cout << "False" << endl;
        cout << topological << endl;
    } else {
        cout << "No es un DAG" << endl;
    }
    return 0;
}

// Convierte el identificador del nodo de numero a letra                | O(1)
char itc(int i) {
    return (char) i + 'A';
}

// Convierte el identificador del nodo de letra a numero                | O(1)
int cti(char s) {
    return (int) s - 'A';
}

// Lee el input y genera el grafo correspondiente                       | O(m)
void loadGraph(int n, int m, List<List<int>>& adj_list){
    for(int i = 0; i < m; i++){
        char a, b; cin >> a >> b;
        int u{cti(a)}, v{cti(b)};
        adj_list.idx(u).push(v);
    }
}

// Ordena los nodos topologicamente y determina si el grafo es un DAG   | O(n + m)
bool topologicalSort(int n, List<List<int>>& adj_list, string& topological){
    int* inDeg = new int[n]();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < adj_list.idx(i).size(); j++){
            int u = adj_list.idx(i).idx(j);
            inDeg[u]++;
        }
    }

    Queue<int> q;
    for(int i = 0; i < n; i++){
        if(inDeg[i] == 0) q.push(i);
    }

    int procesados = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        topological += itc(u);
        topological += ' ';
        procesados++;

        for(int i = 0; i < adj_list.idx(u).size(); i++) {
            int v = adj_list.idx(u).idx(i);
            inDeg[v]--;
            if (inDeg[v] == 0) q.push(v);
         }
    }

    delete[] inDeg;

    return procesados == n;
}

// Revisa que el grado de entrada de todos los hijos sea uno            | O(n + m)
bool isTree(int n, int m, List<List<int>>& adj_list) {
    if(n - m != 1) return false;
    int* inDeg = new int[n];
    for(int i = 0; i < n; ++i) inDeg[i] = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < adj_list.idx(i).size(); ++j)
            inDeg[j]++;
    for(int i = 0; i < n ++i)

}
