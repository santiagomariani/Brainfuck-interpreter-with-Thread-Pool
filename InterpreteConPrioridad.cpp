//
// Created by santi on 18/04/19.
//

#include "InterpreteConPrioridad.h"

InterpreteConPrioridad::InterpreteConPrioridad(Interprete *interprete, int n) :
    interprete(interprete), prioridad(n) {
}

void InterpreteConPrioridad::interpretar() {
    this->interprete->interpretar();
}


int InterpreteConPrioridad::obtenerPrioridad() const {
    return this->prioridad;
}

InterpreteConPrioridad::~InterpreteConPrioridad() {
    delete interprete;
}
