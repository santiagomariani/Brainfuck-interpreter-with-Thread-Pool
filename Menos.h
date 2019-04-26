//
// Created by santi on 24/04/19.
//

#ifndef TP2_CARACTERMENOS_H
#define TP2_CARACTERMENOS_H

#include "MemoriaDatos.h"
#include "Caracter.h"

class CaracterMenos : public Caracter{
    private:
    MemoriaDatos &memoria;
    public:
    explicit CaracterMenos(MemoriaDatos &memoria);
    virtual void operator()();

};


#endif //TP2_CARACTERMENOS_H
