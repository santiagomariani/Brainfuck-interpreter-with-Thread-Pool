//
// Created by santi on 24/04/19.
//

#ifndef TP2_CARACTERMENORQUE_H
#define TP2_CARACTERMENORQUE_H


#include "MemoriaDatos.h"
#include "Caracter.h"

class CaracterMenorQue : public Caracter {
    private:
    MemoriaDatos &memoria;
    public:
    explicit CaracterMenorQue(MemoriaDatos &memoria);
    virtual void operator()();
};


#endif //TP2_CARACTERMENORQUE_H
