#include "MemoriaDatos.h"

#include <stdio.h>
#include <string.h>
#include <iostream>

#define TAM 3000

MemoriaDatos::MemoriaDatos() : memoria(TAM, 0), it(memoria.begin()){
}
void MemoriaDatos::avanzarPos() {
    if (std::addressof(*this->it) != std::addressof(this->memoria.back())) {
        ++this->it;
    }
}
void MemoriaDatos::retrocederPos() {
    if (std::addressof(*this->it) != std::addressof(this->memoria.front())) {
        --this->it;
    }
}
void MemoriaDatos::aumentarValor() {
    ++*this->it;
}
void MemoriaDatos::disminuirValor() {
    --*this->it;
}
void MemoriaDatos::escribirValor(char c) {
    *this->it = c;
}
char MemoriaDatos::leerValor() {
    return *this->it;
}
MemoriaDatos::~MemoriaDatos() {
}
