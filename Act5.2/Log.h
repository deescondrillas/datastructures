// Act 5.2 – 29 de noviembre, 2025
// Clase Log

#pragma once

#include <sstream>
#include <string>
#include "Ip.h"

using namespace std;

// Array para traducir meses de string a int
string meses[13] = {"","Jan","Feb","Mar","Apr","May", "Jun", "Jul", "Aug","Sep", "Oct", "Nov", "Dec"};

// Definición de clase
class Log {
    public:
        // Constructor                  | O(1)
        Log() {

        }
        // Constructor con parametros   | O(1)
        Log(int t[5], int d[4], int p, string s) {
            for(int i = 0; i < 5; ++i) this->timestamp[i] = t[i];
            for(int i = 0; i < 4; ++i) this->ip[i] = d[i];
            this->issue = s;
            this->port = p;
        }

        // Guardar linea en log         | O(1)
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

        // Crear red                    | O(1)
        Ip<Ip<Log>> getNet() {
            Log log(timestamp, ip, port, issue);
            Ip<Log> host(ip[2], ip[3], &log);
            Ip<Ip<Log>> net(ip[0], ip[1], &host);
            return net;
        }

    private:
        // Variables de almacenamiento
        int timestamp[5] = {0, 0, 0, 0, 0};     // 1. mes, día, hora, minuto, segundo
        int ip[4] = {0, 0, 0, 0};               // 2. primera, segunda, tercera, cuarta address
        int port = 0;                           // 3. puerto
        string issue = "";                      // 4. descripción de error
};
