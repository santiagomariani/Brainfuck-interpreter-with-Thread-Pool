//
// Created by santi on 18/04/19.
//

#ifndef TP2_HEAPPROTEGIDO_H
#define TP2_HEAPPROTEGIDO_H


#include <mutex>
#include <queue>
#include <vector>

#include <condition_variable>
#include "InterpreteConPrioridad.h"
#include "Comparador.h"

class HeapProtegido {
    private:
    std::priority_queue <InterpreteConPrioridad*,
            std::vector<InterpreteConPrioridad*>,
            Comparador> cola_prioridad;
    std::mutex m;
    std::condition_variable cond_var;
    bool done;
    bool notified;
    public:
    HeapProtegido();
    // Encola un interprete con prioridad y
    // notifica a un thread para que este
    // desencole.
    void push(InterpreteConPrioridad *interprete);
    // Espera a poder desencolar un interprete
    // con prioridad. Si puede desencolar, devuelve
    // el interprete. En caso de no haber mas nada
    // para desencolar se devuelve nullptr.
    InterpreteConPrioridad* pop();
    // Se notifica a todos los threads que ya
    // no hay mas nada para desencolar.
    void finalizado();
    ~HeapProtegido();
};

#endif //TP2_HEAPPROTEGIDO_H
