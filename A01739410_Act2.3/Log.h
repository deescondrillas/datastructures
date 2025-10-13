// Act 2.3 – 15 de octubre, 2025
// Clase Log

#pragma once

#include <sstream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> ii;

#define f first
#define s second

// Array para traducir meses de string a int
string meses[13] = {"","Jan","Feb","Mar","Apr","May", "Jun", "Jul", "Aug","Sep", "Oct", "Nov", "Dec"};

// Convierte un int n a string, en formato de uno o dos dígitos (n < 10)
string nprint(int val, bool x) {
    string s = to_string(val);
    if(x && s.size() < 2) s.insert(0, "0");
    return s;
}

// Definición de clase
class Log {
    public:
        // Constructor
        Log() {

        }
        // Guardar linea en log
        void read(string line) {
            stringstream lin(line);
            string mes, dia, hora, ips, puerto, mensaje;
            // Guardar mes
            getline(lin, mes, ' ');
            for(int i = 1; i <= 12; i++) if(meses[i] == mes) timestamp[0] = i;
            // Guardar dia
            getline(lin, dia, ' ');
            timestamp[1] = stoi(dia);
            // Guardar hora, minuto y segundo
            getline(lin, hora, ':');
            timestamp[2] = stoi(hora);
            getline(lin, hora, ':');
            timestamp[3] = stoi(hora);
            getline(lin, hora, ' ');
            timestamp[4] = stoi(hora);
            // Guardar IP
            for(int i = 0; i < 4; ++i) {
                if(i < 3) getline(lin, ips, '.');
                else getline(lin, ips, ':');
                ip[i] = stoi(ips);
            }
            // Guardar puerto
            getline(lin, puerto, ' ');
            port = stoi(puerto);
            // Guardar mensaje
            getline(lin, mensaje, '\n');
            issue = mensaje;
        }
        // Imprimir log
        void write(string& doc) {
            doc += meses[timestamp[0]] + " " + nprint(timestamp[1], 1) + " ";
            doc += nprint(timestamp[2], 1) + ":" + nprint(timestamp[3], 1) + ":" + nprint(timestamp[4], 1) + " ";
            doc += nprint(ip[0], 0) + "." + nprint(ip[1], 0) + "." + nprint(ip[2], 0) + "." + nprint(ip[3], 0);
            doc += ":" + nprint(port, 0) + " " + issue + '\n';
            return;
        }
        // Sobrecarga para ordenar logs
        bool operator < (const Log& log) const {
            if(ip < log.ip) return 1;
            if(ip > log.ip) return 0;
            if(timestamp < log.timestamp) return 1;
            if(timestamp > log.timestamp) return 0;
            if(issue < log.issue) return 1;
            if(issue > log.issue) return 0;
            if(port < log.port) return 1;
            return 0;
        }

    private:
        // Variables de almacenamiento
        vector<int> timestamp = {0, 0, 0, 0, 0};     // 1. mes, día, hora, minuto, segundo
        vector<int> ip = {0, 0, 0, 0};               // 2. primera, segunda, tercera, cuarta address
        int port = 0;                                // 3. puerto
        string issue = "";                           // 4. descripción de error
};
