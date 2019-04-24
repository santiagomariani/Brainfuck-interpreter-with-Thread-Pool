//
// Created by santi on 18/04/19.
//

#ifndef TP2_THREADPOOL_H
#define TP2_THREADPOOL_H


#include <vector>
#include "Thread.h"
#include "Consumidor.h"

class ThreadPool {
    private:
    std::vector<Thread*> threads;
    public:
    ThreadPool(int cantidad, HeapProtegido &heap);
    // Se encarga de lanzar cada uno de los threads
    // que tiene el thread-pool.
    void iniciarThreads();

    // Se hace join a cada uno de los threads para
    // esperar a que estos terminen.
    void finalizarThreads();
    ~ThreadPool();
};


#endif //TP2_THREADPOOL_H
