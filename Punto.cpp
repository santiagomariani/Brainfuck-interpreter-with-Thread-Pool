//
// Created by santi on 24/04/19.
//

#include "CaracterPunto.h"

CaracterPunto::CaracterPunto(MemoriaDatos &memoria, std::ostream *salida) :
    memoria(memoria),
    archivo_salida(salida) {}

void CaracterPunto::operator()() {
    char caracter_a_imprimir;
    caracter_a_imprimir = this->memoria.leerValor();
    *this->archivo_salida << caracter_a_imprimir;
}
