// Act 3.4 – 28 de octubre, 2025
// Clase Log

#pragma once

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Actualizar clase para que no contenga la info de Red y Host (primeras de la IP)

// Array para traducir meses de string a int
string meses[13] = {"","Jan","Feb","Mar","Apr","May", "Jun", "Jul", "Aug","Sep", "Oct", "Nov", "Dec"};

// Definición de clase
class Log {
    public:
        // Constructor
        Log() {}

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
            // Saltar IP
            for(int i = 0; i < 4; ++i) {
                if(i < 3) getline(lin, ips, '.');
                else getline(lin, ips, ':');
            }
            // Guardar puerto
            getline(lin, puerto, ' ');
            port = stoi(puerto);
            // Guardar mensaje
            getline(lin, mensaje, '\n');
            issue = mensaje;
        }

        /* Sobrecarga para ordenar logs
        bool operator > (const Log& log) const {
 
            if(port > log.port) return 1;
            if(port < log.port) return 0;
            for(int i = 0; i < 5; ++i) {
                if(timestamp[i] > log.timestamp[i]) return 1;
                if(timestamp[i] < log.timestamp[i]) return 0;
            }
            if(issue > log.issue) return 1;
            return 0;
        }*/

        /* Sobrecarga para ordenar logs
        bool operator < (const Log& log) const {

            if(port < log.port) return 1;
            if(port > log.port) return 0;
            for(int i = 0; i < 5; ++i) {
                if(timestamp[i] < log.timestamp[i]) return 1;
                if(timestamp[i] > log.timestamp[i]) return 0;
            }
            if(issue < log.issue) return 1;
            return 0;
        }*/

    private:
        // Variables de almacenamiento
        int timestamp[5] = {0, 0, 0, 0, 0};     // 1. mes, día, hora, minuto, segundo
        int port = 0;                           // 3. puerto
        string issue = "";                      // 4. descripción de error
};
