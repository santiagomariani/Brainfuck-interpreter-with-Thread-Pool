//
// Created by santi on 17/04/19.
//

#ifndef TP2_PRODUCTOR_H
#define TP2_PRODUCTOR_H

#include <condition_variable>
#include "Parser.h"
#include "HeapProtegido.h"

class Productor {
    private:
    Parser parser;
    HeapProtegido &cola_prior;
    public:
    explicit Productor(HeapProtegido &heap);
    // Lee y parsea lo que lee de entrada estandar, crea
    // los interpretes y luego guarda los mismos en la cola
    // de prioridad para que luego sean usados por los threads.
    void producir();
    ~Productor();
};

#endif //TP2_PRODUCTOR_H
