//
// Created by santi on 18/04/19.
//

#ifndef TP2_INTERPRETECONPRIORIDAD_H
#define TP2_INTERPRETECONPRIORIDAD_H


#include <mutex>
#include "Interprete.h"

class InterpreteConPrioridad {
    private:
    Interprete *interprete;
    int prioridad;
    public:
    InterpreteConPrioridad(Interprete *interprete, int n);
    // Interpreta el codigo brainfuck.
    void interpretar();
    // Devuelve la prioridad.
    int obtenerPrioridad() const;
    ~InterpreteConPrioridad();
};

#endif //TP2_INTERPRETECONPRIORIDAD_H
