//
// Created by santi on 18/04/19.
//

#ifndef TP2_COMPARADOR_H
#define TP2_COMPARADOR_H


#include "InterpreteConPrioridad.h"

class Comparador {
    public:
    // Se utiliza despues en la cola de prioridad.
    // Permite comparar 2 InterpretesConPrioridad
    // a traves de su numero de prioridad.
    bool operator()(const InterpreteConPrioridad *a,
            const InterpreteConPrioridad *b);
};

#endif //TP2_COMPARADOR_H
