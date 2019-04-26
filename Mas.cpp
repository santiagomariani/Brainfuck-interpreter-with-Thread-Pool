//
// Created by santi on 24/04/19.
//

#include "CaracterMas.h"

CaracterMas::CaracterMas(MemoriaDatos &memoria) : memoria(memoria) {
}

void CaracterMas::operator()() {
    this->memoria.aumentarValor();
}
