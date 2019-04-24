//
// Created by santi on 18/04/19.
//

#include "Consumidor.h"

Consumidor::Consumidor(HeapProtegido &heap) : cola_prior(heap){
}

void Consumidor::run() {
    InterpreteConPrioridad *interprete;
    interprete = this->cola_prior.pop();
    std::thread::id this_id = std::this_thread::get_id();
    while (interprete != NULL) {
        interprete->interpretar();
        delete interprete;
        std::cout << "Consumidor " << this_id << " desencolo" << std::endl;
        interprete = this->cola_prior.pop();
    }
    std::cout << "Consumidor " << this_id << " Termino" << std::endl;
}

Consumidor::~Consumidor() {
}
