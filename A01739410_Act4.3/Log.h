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
            // Leer IP:
            getline(lin, ips, '.'); ip1 = stoi(ips);
            getline(lin, ips, '.'); ip2 = stoi(ips);
            getline(lin, ips, '.'); ip3 = stoi(ips);
            getline(lin, ips, ':'); ip4 = stoi(ips);
            // Guardar puerto
            getline(lin, puerto, ' ');
            port = stoi(puerto);
            // Guardar mensaje
            getline(lin, mensaje, '\n');
            issue = mensaje;
        }

    private:
        // Variables de almacenamiento
        int timestamp[5] = {0, 0, 0, 0, 0};     // 1. mes, día, hora, minuto, segundo
        int ip1{0}, ip2{0}, ip3{0}, ip4{0};     // 2. secciones de IP
        int port = 0;                           // 3. puerto
        string issue = "";                      // 4. descripción de error
    template <class> friend class Graph;
};
