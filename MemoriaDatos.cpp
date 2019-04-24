#include "MemoriaDatos.h"

#include <stdio.h>
#include <string.h>
#include <iostream>

#define TAM 3000

MemoriaDatos::MemoriaDatos() {
    this->memoria = new char[TAM];
    memset(this->memoria, 0, TAM);
    this->ptr = 0;
}
void MemoriaDatos::avanzarPos() {
    if (this->ptr < TAM - 1) {
        ++this->ptr;
    }
}
void MemoriaDatos::retrocederPos() {
    if (this->ptr > 0) {
        --this->ptr;
    }
}
void MemoriaDatos::aumentarValor() {
    ++(this->memoria)[this->ptr];
}
void MemoriaDatos::disminuirValor() {
    --(this->memoria)[this->ptr];
}
void MemoriaDatos::escribirValor(char c) {
    (this->memoria)[this->ptr] = c;
}
char MemoriaDatos::leerValor() {
    return (this->memoria)[this->ptr];
}
MemoriaDatos::~MemoriaDatos() {
    delete[] this->memoria;
}
