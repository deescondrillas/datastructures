#include <iostream>
#include <string>
#include "queue.h"

using namespace std;
typedef int** matriz;

// main mucho mas simple aunq no lo podemos mandar, porque no guarda la
// lista de adyacencias, solo usa la matriz

// Definicion de funciones
string nombre(int);
void dfs(matriz&, int, int, int*);
void bfs(matriz&, int, int, int*);

int main() {
	// Input n y representaciones
    int n{0}; cin >> n;

    matriz matriz_adyacencias = new int*[n];
    for (int i = 0; i < n; i++) matriz_adyacencias[i] = new int[n]();

    // Input de conexiones
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> matriz_adyacencias[i][j];
        }
    }

    // Output – Matriz de adyacencias       | O(n^2)
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << matriz_adyacencias[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl; // Enter

    // Output - Lista de adyacencias        | O(n^2)
    for(int i = 0; i < n; ++i) {
        cout << nombre(i);
        for(int j = 0; j < n; ++j) {
            if (matriz_adyacencias[i][j])
                cout << " - " << nombre(j);
        }
        cout << endl;
    }
    cout << endl; // Enter

    // Output – BFS
    int *visitados_bfs = new int[n]();
    bfs(matriz_adyacencias, n, 0, visitados_bfs);
    cout << "\n" << endl; // Doble Enter

    // Output – DFS
    int *visitados_dfs = new int[n]();
    dfs(matriz_adyacencias, n, 0, visitados_dfs);
    cout << endl; // Enter
    return 0;

    //Deletes
    for (int i = 0; i < n; ++i) {
        delete[] matriz_adyacencias[i];
    }
    delete[] matriz_adyacencias;
    return 0;
}

string nombre(int x) {
    char nom = (char)(65 + x);
    string s; s+= nom;
    return s;
}

string its(int n){
    n += 'A';
    char m = '\0';
    if(n>90) m = 'A'-1;
    while(n>90){
        n -= 26;
        m++;
    }
    string s;
    if(m=='\0') s = (char) n;
    else{
        s = m;
        s += (char) n;
    }
    return s;
}

int sti(string s){
    if(s.length()==1) return (int) s[0] - 'A';

    int m = (int) s[0];
    int n = (int) s[1];

    m -= 'A'-1;
    n -= 'A';
    return m*26+n;
}

// Recorrido por profundidad - DFS  | O(n)
void dfs(matriz &a, int n, int s, int *visitados){
    visitados[s] = 1;           // Marca como visitado el vector al que llega
    cout << nombre(s) << ' ';   // cout << cositas raras

    //Visita a los vecinos
    for (int v = 0; v < n; ++v) {
        if(a[s][v] == 1 && !visitados[v]){
            dfs(a, n, v, visitados);
        }
    }
}

// Recorrido por anchura - BFS      | O(n)
void bfs(matriz &a, int n, int s, int *visitados){
    Queue<int> q;               // FIFO

    visitados[s] = 1;           // Marco 1ro como visitado
    q.push(s);                  // Lo meto a la cola

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << nombre(u) << ' ';       // cout << cosas raras

        //Explora vecinos
        for(int v = 0; v < n; ++v){
            if (a[u][v] == 1 && !visitados[v]){
                visitados[v] = 1;
                q.push(v);
            }
        }
    }
}
