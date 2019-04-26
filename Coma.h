//
// Created by santi on 24/04/19.
//

#ifndef TP2_CARACTERCOMA_H
#define TP2_CARACTERCOMA_H

#include <istream>
#include "MemoriaDatos.h"
#include "Caracter.h"

class CaracterComa : public Caracter {
    private:
    MemoriaDatos &memoria;
    std::istream *archivo_entrada;
    public:
    CaracterComa(MemoriaDatos &memoria, std::istream *entrada);
    virtual void operator()();
};


#endif //TP2_CARACTERCOMA_H
