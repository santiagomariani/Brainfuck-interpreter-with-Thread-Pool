//
// Created by santi on 18/04/19.
//
#include <mutex>
#include <thread>
#include "HeapProtegido.h"

HeapProtegido::HeapProtegido() : done(false), notified(false) {
}

void HeapProtegido::push(InterpreteConPrioridad* interprete) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::unique_lock<std::mutex> lock(this->m);
    std::cout << "Encolando" << std::endl;
    this->cola_prioridad.push(interprete);
    this->notified = true;
    this->cond_var.notify_one();
}

InterpreteConPrioridad *HeapProtegido::pop() {
    std::unique_lock<std::mutex> lock(this->m);
    while (!this->notified && !this->done) {
        this->cond_var.wait(lock);
    }
    if (!this->cola_prioridad.empty()) {
        InterpreteConPrioridad *interprete = this->cola_prioridad.top();
        this->cola_prioridad.pop();
        this->notified = false;
        return interprete;
    }
    return nullptr;
}

void HeapProtegido::finalizado() {
    std::unique_lock<std::mutex> lock(this->m);
    this->done = true;
    //this->notified = true;
    cond_var.notify_all();
}

HeapProtegido::~HeapProtegido() {
}
