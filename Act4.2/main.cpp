// Act 4.2 – 20 de noviembre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A01739522 – Sergio Sebastian Cortez Yepez
// A01739190 – Carlos Arturo Ferat Torres

#include <iostream>
#include <string>
#include "queue.h"

using namespace std;
typedef int** lista;

void loadGraph(int, int, lista&, int*&);
bool isDag(int, lista&, int*&);
bool isTree(int, int);
int sti(string s);


int main() {
    int n{0}, m{0};
    cin >> n >> m;

    lista lista_adj = new int*[n];
    int* sizes = new int[n]();

    loadGraph(n, m, lista_adj, sizes);

    isDag(n, lista_adj, sizes) ? isTree(n, m) ? cout << "True" << endl : cout << "False" << endl : cout << "No es un DAG" << endl;
    isDag(n, lista_adj, sizes) ? cout << "True" : cout << "False";
    return 0;
}

int sti(string s){
    if(s.length()==1) return (int) s[0] - 'A';

    int m = (int) s[0];
    int n = (int) s[1];

    m -= 'A'-1;
    n -= 'A';
    return m*26+n;
}


void loadGraph(int n, int m, lista &lista_adj, int* &sizes){
    int (*edges)[2] = new int[m][2];
    int* idx = new int[n]();

    for(int i = 0; i < m; i++){
        string a, b; cin >> a >> b;
        edges[i][0] = sti(a);
        edges[i][1] = sti(b);
    }

    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        sizes[u]++;
    }

    for (int i = 0; i < n; i++)
        lista_adj[i] = new int[sizes[i]];

    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        lista_adj[u][idx[u]++] = v;
    }

    delete[] idx;
    delete[] edges;
}

bool isDag(int n, lista &listA, int* &sizes){
    int* inDeg = new int[n]();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < sizes[i]; j++){
            int u = listA[i][j];
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
        procesados++;

        for(int i = 0; i < sizes[u]; i++){
            int v = listA[u][i];
            inDeg[v]--;
            if (inDeg[v] == 0) q.push(v);
         }
    }

    delete[] inDeg;

    return procesados == n;
}

bool isTree(int n, int m) {
    return (n - m) == 1;
}
