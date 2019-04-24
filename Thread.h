//
// Created by santi on 18/04/19.
//

#ifndef TP2_THREAD_H
#define TP2_THREAD_H


#include <thread>

class Thread {
private:
    std::thread thread;
public:
    Thread();
    // Lanza el thread ejecutando la funcion Thread::run.
    void start();
    // Espera a que el hilo termine.
    void join();
    // El metodo run se define en una clase hija.
    virtual void run() = 0;
    Thread(const Thread&) = delete;
    Thread& operator=(const Thread&) = delete;
    Thread(Thread&& other);
    Thread& operator=(Thread&& other);
    virtual ~Thread();
};

#endif //TP2_THREAD_H
