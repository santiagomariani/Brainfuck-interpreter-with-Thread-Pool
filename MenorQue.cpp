//
// Created by santi on 24/04/19.
//

#include "CaracterMenorQue.h"

CaracterMenorQue::CaracterMenorQue(MemoriaDatos &memoria) : memoria(memoria) {
}

void CaracterMenorQue::operator()() {
    this->memoria.retrocederPos();
}
