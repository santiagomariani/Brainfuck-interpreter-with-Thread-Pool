//
// Created by santi on 24/04/19.
//

#ifndef TP2_CARACTERMAYORQUE_H
#define TP2_CARACTERMAYORQUE_H

#include "MemoriaDatos.h"
#include "Caracter.h"

class CaracterMayorQue : public Caracter{
    private:
    MemoriaDatos &memoria;
    public:
    explicit CaracterMayorQue(MemoriaDatos &memoria);
    virtual void operator()();
};


#endif //TP2_CARACTERMAYORQUE_H
