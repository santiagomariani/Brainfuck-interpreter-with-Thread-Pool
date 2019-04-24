//
// Created by santi on 18/04/19.
//

#include "ThreadPool.h"

ThreadPool::ThreadPool(int cantidad, HeapProtegido &heap) {
    for (int i = 0; i < cantidad; ++i) {
        threads.push_back(new Consumidor(heap));
    }
}

void ThreadPool::iniciarThreads() {
    auto it = this->threads.begin();
    for (; it != this->threads.end(); ++it) {
        (*it)->start();
    }
}

void ThreadPool::finalizarThreads() {
    auto it = this->threads.begin();
    for (; it != this->threads.end(); ++it) {
        std::cout << "ThreadPool: Join" << std::endl;
        (*it)->join();
    }
}

ThreadPool::~ThreadPool() {
    auto it = this->threads.begin();
    for (; it != this->threads.end(); ++it) {
        delete (*it);
    }
}
