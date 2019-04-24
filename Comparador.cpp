//
// Created by santi on 18/04/19.
//

#include "Comparador.h"

bool Comparador::operator()(const InterpreteConPrioridad *a,
        const InterpreteConPrioridad *b) {
    return a->obtenerPrioridad() < b->obtenerPrioridad();
}
