//
// Created by santi on 24/04/19.
//

#include "CaracterMenos.h"

CaracterMenos::CaracterMenos(MemoriaDatos &memoria) : memoria(memoria) {
}

void CaracterMenos::operator()() {
    this->memoria.disminuirValor();
}
