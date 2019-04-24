#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>

#include "Interprete.h"
#include "Productor.h"
#include "Thread.h"
#include "ThreadPool.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Cantidad de parametros invalida.";
        return 2;
    }
    
    if (strcmp(argv[1], "interprete") == 0) {
        std::string archivo_bf = argv[2];
        Interprete interprete(&archivo_bf);
        return interprete.interpretar();
    } else if (strcmp(argv[1], "thread-pool") == 0) {
        int cant_threads = std::stoi(argv[2]);
        HeapProtegido heap;
        ThreadPool thread_pool(cant_threads, heap);
        Productor productor(heap);
        thread_pool.iniciarThreads();
        productor.producir();
        thread_pool.finalizarThreads();
    }
    return 0;
}
