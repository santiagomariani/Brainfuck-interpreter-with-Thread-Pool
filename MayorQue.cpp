//
// Created by santi on 24/04/19.
//

#include "CaracterMayorQue.h"

CaracterMayorQue::CaracterMayorQue(MemoriaDatos &memoria) : memoria(memoria) {
}

void CaracterMayorQue::operator()() {
    this->memoria.avanzarPos();
}
