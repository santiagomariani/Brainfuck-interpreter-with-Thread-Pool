//
// Created by santi on 24/04/19.
//

#ifndef TP2_CARACTERMAS_H
#define TP2_CARACTERMAS_H

#include "MemoriaDatos.h"
#include "Caracter.h"

class CaracterMas : public Caracter {
    private:
    MemoriaDatos &memoria;
    public:
    explicit CaracterMas(MemoriaDatos &memoria);
    virtual void operator()();
};

#endif //TP2_CARACTERMAS_H
