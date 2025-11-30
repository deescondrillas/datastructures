// Act 5.2 – 29 de noviembre, 2025
// Clase Log

#pragma once

#include <sstream>
#include "Red.h"

using namespace std;

// Array para traducir meses de string a int
string meses[13] = {"","Jan","Feb","Mar","Apr","May", "Jun", "Jul", "Aug","Sep", "Oct", "Nov", "Dec"};

// Definición de clase
class Log {
    public:
        // Constructor                  | O(1)
        Log() {

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
            int ip[4];
            for(int i = 0; i < 4; ++i) {
                if(i < 3) getline(lin, ips, '.');
                else getline(lin, ips, ':');
                ip[i] = stoi(ips);
            }
            redIP.init(ip[0], ip[1]);
            hostIP.init(ip[2], ip[3]);
            // Guardar puerto
            getline(lin, puerto, ' ');
            port = stoi(puerto);
            // Guardar mensaje
            getline(lin, mensaje, '\n');
            issue = mensaje;
        }

        // Retorna la red del log       | O(1)
        Red getRed() {
            return Red(redIP, hostIP);
        }

    private:
        // Variables de almacenamiento
        int timestamp[5] = {0, 0, 0, 0, 0};     // 1. mes, día, hora, minuto, segundo
        Ip redIP, hostIP;                       // 2. primera, segunda, tercera, cuarta address
        int port = 0;                           // 3. puerto
        string issue = "";                      // 4. descripción de error
};
