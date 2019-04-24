//
// Created by santi on 18/04/19.
//

#ifndef TP2_CONSUMIDOR_H
#define TP2_CONSUMIDOR_H


#include <condition_variable>
#include "Thread.h"
#include "HeapProtegido.h"

class Consumidor : public Thread {
    private:
    HeapProtegido &cola_prior;
    public:
    explicit Consumidor(HeapProtegido &heap);
    // Desencola interpretes con prioridad y los
    // usa para interpretar. Termina cuando ya no
    // hay mas interpretes con prioridad para desencolar.
    virtual void run() override;
    ~Consumidor();
};
#endif //TP2_CONSUMIDOR_H
