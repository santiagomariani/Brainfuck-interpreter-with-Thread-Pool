//
// Created by santi on 24/04/19.
//

#include "CaracterComa.h"

CaracterComa::CaracterComa(MemoriaDatos &memoria, std::istream *entrada) :
    memoria(memoria),
    archivo_entrada(entrada) {}

void CaracterComa::operator()() {
    char caracter_entrada;
    if (!this->archivo_entrada->get(caracter_entrada)) {
        caracter_entrada = 0;
    }
    this->memoria.escribirValor(caracter_entrada);
}
