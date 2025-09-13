// A01739755 – Michelle Amanda Hernández Legaria
// A01739410 – Franco De Escondrillas Vázquez
// A01739511 – Jorge Luis Zago Guevara

#include <iostream>
#include <utility>      // Para usar pair<int, int>
#include <fstream>      // Para leer y escribir archivos
#include <sstream>      // Para parsear strings
#include <vector>
#include <string>

using namespace std;

// Definiciones
ifstream fin("bitacora.txt");
ofstream fout("sorted.txt");

typedef pair<int, int> ii;

#define f first
#define s second
#define pb push_back
#define rp(i, a, b) for(int i = (a), TT = (b); i < TT; ++i)                         // Definición de un ciclo for rápido
#define iostream_testcases ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);     // Gestiona todos los cin primero, y luego los cout

// Variables y funciones que se usan en la estructura de datos
string console = "";            // Guarda el output para imprimir de golpe
string sorted = "";             // Guarda el output para escribir de golpe
string nprint(int, bool);       // Convierte un int n a string, en formato de uno o dos dígitos (n < 10)

// Array para traducir meses de string a int
string meses[13] = {"","Jan","Feb","Mar","Apr","May", "Jun", "Jul", "Aug","Sep", "Oct", "Nov", "Dec"};

// Estructura de datos para almacenar los logs
struct Log {
    // Variables de almacenamiento
    vector<int> timestamp = {0, 0, 0, 0, 0};     // 1. mes, día, hora, minuto, segundo
    vector<int> ip = {0, 0, 0, 0};               // 2. primera, segunda, tercera, cuarta address
    int port = 0;                               // 3. puerto
    string issue = "";                          // 4. descripción de error

    // Obtener mes y día de un log
    ii dia() {
        return {timestamp[0], timestamp[1]};
    }

    // Sobrecarga para ordenar logs
    bool operator < (const Log& log) const {
        if(timestamp < log.timestamp) return 1;
        if(timestamp > log.timestamp) return 0;
        if(ip < log.ip) return 1;
        if(ip > log.ip) return 0;
        if(port < log.port) return 1;
        if(port > log.port) return 0;
        if(issue < log.issue) return 1;
        return 0;
    }

    void operator = (const Log& log) {
        timestamp = log.timestamp;
        issue = log.issue;
        port = log.port;
        ip = log.ip;
    }

    // Funciones para leer y escribir
    void read(string line) {
        // Parsear la línea: "Jul 18 07:53:22 235.99.27.158:6526 Failed password..."
        stringstream ss(line);
        string mesStr, diaStr, tiempoStr, ipPuertoStr, issueStr;

        // Leer mes y día
        ss >> mesStr >> diaStr;

        // Convertir mes a número
        for(int i = 1; i <= 12; i++) {
            if(meses[i] == mesStr) {
                timestamp[0] = i;  // mes
                break;
            }
        }

        // Convertir día
        timestamp[1] = stoi(diaStr);  // día

        // Leer tiempo (HH:MM:SS)
        ss >> tiempoStr;
        stringstream tiempoStream(tiempoStr);
        string hora, minuto, segundo;
        getline(tiempoStream, hora, ':');
        getline(tiempoStream, minuto, ':');
        getline(tiempoStream, segundo, ':');

        timestamp[2] = stoi(hora);    // hora
        timestamp[3] = stoi(minuto);  // minuto
        timestamp[4] = stoi(segundo); // segundo

        // Leer IP:puerto
        ss >> ipPuertoStr;
        stringstream ipStream(ipPuertoStr);
        string ipPart, puertoStr;
        getline(ipStream, ipPart, ':');
        getline(ipStream, puertoStr, ':');

        // Parsear IP (4 partes)
        stringstream ipPartStream(ipPart);
        string ip1, ip2, ip3, ip4;
        getline(ipPartStream, ip1, '.');
        getline(ipPartStream, ip2, '.');
        getline(ipPartStream, ip3, '.');
        getline(ipPartStream, ip4, '.');

        ip[0] = stoi(ip1);
        ip[1] = stoi(ip2);
        ip[2] = stoi(ip3);
        ip[3] = stoi(ip4);

        // Puerto
        port = stoi(puertoStr);

        // Leer el resto del mensaje
        getline(ss, issueStr);
        issue = issueStr.substr(1); // Eliminar el espacio inicial
        return;
    }

    void print(string& doc) {
        doc += meses[timestamp[0]] + " " + nprint(timestamp[1], 1) + " ";
        doc += nprint(timestamp[2], 1) + ":" + nprint(timestamp[3], 1) + ":" + nprint(timestamp[4], 1) + " ";
        doc += nprint(ip[0], 0) + "." + nprint(ip[1], 0) + "." + nprint(ip[2], 0) + "." + nprint(ip[3], 0);
        doc += ":" + nprint(port, 0) + " " + issue + '\n';
        return;
    }
};

// Ordena en forma ascendente los datos con el método de merge
void mergesort(int, int);               // O(n log₂n)

// Realiza una busqueda binaria y regresa los índices de los datos correspondientes
ii binarysearch(ii, ii, vector<Log>&);  // O(log₂n)

// Implementación de función de lectura (Zago)
void readBitacora(string filename);     // O(n)

// Variables globales
vector<vector<Log>> logs(1);    // Optimiza memoria de O(n log₂n) a O(3n)
int n = 0;                      // Cuenta el número de línas


int main() {
    iostream_testcases
    // Input – bitacora.txt (Zago)
    readBitacora("bitacora.txt");

    // Redimencionar el vector de vectores para optimizar espacio (Franco)
    for(int i = n; i > 1; ++i /= 2) {
        logs.pb(vector<Log>(i/2 + 1));
        logs.pb(vector<Log>(i/2 + 1));
    }

    // Sort – Ordenamiento de logs | tiempo: O(n log₂n) memoria: O(3n) (Franco)
    mergesort(0, n);

    // Input – 4 enteros (mes, dia, mes, dia)
    ii a, b; cin >> a.f >> a.s >> b.f >> b.s;

    ii x = binarysearch(a, b, logs[0]);

    // Output – consola
    rp(i, x.f, x.s) logs[0][i].print(console);
    cout << console;

    // Output – sorted.txt
    rp(i, 0, n) logs[0][i].print(sorted);
    sorted.pop_back();
    fout << sorted;
}

// Funciones
string nprint(int n, bool x) {
    string s = to_string(n);
    if(x && s.size() < 2) s.insert(0, "0");
    return s;
}

void mergesort(int lvl, int sz) {
    if(sz <= 1) return;

    int l = 0;
    int r = 0;

    int szL = sz/2;
    int szR = sz - szL;

    int logL = (lvl + (lvl & 1)) + 1;                       // como los subarrays se guardan por pares, se debe saltar de dos en dos
    int logR = (lvl + (lvl & 1)) + 2;                       // para ello, se usa la operación (i + (i & 1)) para avanzar +2 cada dos

    rp(i, 0, sz) {                                          // se dividen los elementos en cada subarray
        if(i < szL) logs[logL][i] = logs[lvl][i];
        else logs[logR][i - szR] = logs[lvl][i];
    }

    mergesort(logL, szL);                                   // se ordena el primer subarray
    mergesort(logR, szR);                                   // se ordena el segundo subarray

    rp(i, 0, sz) {
        if(l < szL && r < szR) {                            // si no se han usado ya todos los elementos de un subarray, los compara
            if(logs[logL][l] < logs[logR][r]) {             // se toma el elemento más chico y se avanza al siguiente
                logs[lvl][i] = logs[logL][l++];
            }
            else logs[lvl][i] = logs[logR][r++];
        }
        else if(l == szL) logs[lvl][i] = logs[logR][r++];   // si se acaba el primer subarray, se completa con el segundo
        else if(r == szR) logs[lvl][i] = logs[logL][l++];   // si se acaba el segundo subarray, se completa con el primero
    }
}

ii binarysearch(ii l, ii r, vector<Log>& logs) {
    return {l.f + r.f, l.s + r.s};
}

void readBitacora(string filename) {
    ifstream file(filename);
    string line;

    while(getline(file, line)) {
        Log log;
        log.read(line);
        logs[0].push_back(log);
        ++n;
    }
    return;
}

/*
To do list
    1. Lectura y escritura. (Zago)
    2. Ordenar con mergesort y crear sorted.txt (Franco)
    3. Hacer la búsqueda binaria (con la lista ordenada (Michelle)
*/
