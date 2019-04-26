//
// Created by santi on 24/04/19.
//

#ifndef TP2_CARACTERPUNTO_H
#define TP2_CARACTERPUNTO_H


#include <ostream>
#include "MemoriaDatos.h"
#include "Caracter.h"

class CaracterPunto : public Caracter{
    private:
    MemoriaDatos &memoria;
    std::ostream *archivo_salida;
    public:
    CaracterPunto(MemoriaDatos &memoria, std::ostream *salida);
    virtual void operator()();
};

#endif //TP2_CARACTERPUNTO_H
