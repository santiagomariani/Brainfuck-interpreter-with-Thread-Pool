//
// Created by santi on 17/04/19.
//

#include <vector>
#include <iostream>
#include <string>

#include "Parser.h"

#define NOMBRE 0
#define PRIORIDAD 1
#define ARCHIVO_ENTRADA 2
#define ARCHIVO_SALIDA 3
#define CODIGO_BRAINFUCK 4

Parser::Parser() {
}

void Parser::parsear(std::string &linea) {
    this->liberar_campos();
    std::string::iterator it = linea.begin();
    ++it;
    std::string *cadena = new std::string();
    for (; it!= linea.end(); ++it) {
        if (*it != ',') {
            cadena->push_back(*it);
            continue;
        }
        ++it;
        if (it == linea.end()) {
            cadena->push_back(',');
        } else if (*it == ' ') {
            this->campos.push_back(cadena);
            cadena = new std::string();
        } else {
            --it;
            cadena->push_back(*it);
        }
    }
    this->campos.push_back(cadena);
    this->prioridad = std::stoi(*this->campos[PRIORIDAD]);
}

std::string* Parser::obtener_archivo_entrada() {
    return this->campos[ARCHIVO_ENTRADA];
}
std::string* Parser::obtener_archivo_salida() {
    return this->campos[ARCHIVO_SALIDA];
}
std::string* Parser::obtener_codigo_bf() {
    return this->campos[CODIGO_BRAINFUCK];
}
std::string* Parser::obtener_nombre() {
    return this->campos[NOMBRE];
}
int Parser::obtener_prioridad() {
    return this->prioridad;
}
void Parser::liberar_campos() {
    std::vector<std::string*>::iterator it = this->campos.begin();
    for (; it!=this->campos.end(); ++it) {
        delete *it;
    }
    this->campos.clear();
}
Parser::~Parser() {
    this->liberar_campos();
}
