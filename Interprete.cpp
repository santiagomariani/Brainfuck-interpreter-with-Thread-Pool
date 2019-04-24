#include "Interprete.h"

#include <fstream>
#include <iostream>

#include <vector>
#include <stack>
#include <map>
#include <string>

#include <string.h>

#define TAM 3

Interprete::Interprete(const std::string *bf) :
    bf(new std::ifstream(*bf)),
    entrada(&std::cin),
    salida(&std::cout),
    io_estandar(true) {
}

Interprete::Interprete(const std::string *bf,
        const std::string *entrada,
        const std::string *salida) :
        bf(new std::stringstream(*bf)),
        entrada(new std::ifstream(*entrada)),
        salida(new std::ofstream(*salida)),
        io_estandar(false) {}

int Interprete::interpretar() {
    if (!sintaxisCorrecta()) {
        return 1;
    }

    char caracter_archivo;

    while (*this->bf >> caracter_archivo) {
        if (caracter_archivo != '[') {
            this->procesarCaracter(caracter_archivo);
        } else {
            std::vector<char> buffer;
            std::map<int, int> saltos;
            this->copiarLoop(buffer, saltos);
            this->ejecutarLoop(buffer, saltos);
        }
    }
    return 0;
}

void Interprete::copiarLoop(std::vector<char> &buffer,
        std::map<int, int> &saltos) {
    char caracter_archivo = '[';
    int pos_corchete_cierra;
    int pos_corchete_abre;
    std::stack<int> aux;
    aux.push(0);
    buffer.push_back(caracter_archivo);
    for (int i = 1; !aux.empty(); i++) {
        this->bf->get(caracter_archivo);
        if (caracter_archivo == '[') {
            aux.push(i);
        } else if (caracter_archivo == ']') {
            pos_corchete_abre = aux.top();
            aux.pop();
            pos_corchete_cierra = i;
            saltos[pos_corchete_abre] = pos_corchete_cierra;
            saltos[pos_corchete_cierra] = pos_corchete_abre;
        }
        buffer.push_back(caracter_archivo);
    }
}

void Interprete::ejecutarLoop(std::vector<char> &buffer,
        std::map<int, int> &saltos) {
    size_t longitud = buffer.size();
    buffer.shrink_to_fit();
    size_t i = 0;
    while (i < longitud) {
        if (buffer[i] == '[') {
            if (this->memoria.leerValor() > 0) {
                ++i;
            } else {
                i  = saltos[i] + 1;
            }
        } else if (buffer[i] == ']') {
            if (this->memoria.leerValor() > 0) {
                i = saltos[i] + 1;
            } else {
                ++i;
            }
        } else {
            this->procesarCaracter(buffer[i]);
            ++i;
        }
    }
}

void Interprete::procesarCaracter(char caracter_archivo) {
    if (caracter_archivo == '<') {
        this->memoria.retrocederPos();
    } else if (caracter_archivo == '>') {
        this->memoria.avanzarPos();
    } else if (caracter_archivo == '+') {
        this->memoria.aumentarValor();
    } else if (caracter_archivo == '-') {
        this->memoria.disminuirValor();
    } else if (caracter_archivo == ',') {
        char caracter_entrada;
        if (!entrada->get(caracter_entrada)) {
            caracter_entrada = 0;
        }
        this->memoria.escribirValor(caracter_entrada);
    } else if (caracter_archivo == '.') {
        char caracter_a_imprimir;
        caracter_a_imprimir = this->memoria.leerValor();
        *salida << caracter_a_imprimir;
    }
}

bool Interprete::sintaxisCorrecta() {
    int corchetes = 0;
    char caracter_archivo;
    while (*this->bf >> caracter_archivo) {
        if (caracter_archivo == '[') {
            ++corchetes;
        } else if (caracter_archivo == ']') {
            --corchetes;
        }
        if (corchetes < 0) {
            return false;
        }
    }
    this->bf->clear();
    this->bf->seekg(0);
    return corchetes == 0;
}

Interprete::~Interprete() {
    if (!this->io_estandar) {
        ((std::ifstream*)this->entrada)->close();
        ((std::ofstream*)this->salida)->close();
        delete this->entrada;
        delete this->salida;
    } else {
        ((std::ifstream*)this->bf)->close();
    }
    delete this->bf;
}
