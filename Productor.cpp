//
// Created by santi on 17/04/19.
//
#include "iostream"
#include <string>

#include "Productor.h"
#include "Interprete.h"
#include "InterpreteConPrioridad.h"

Productor::Productor(HeapProtegido &heap) : cola_prior(heap) {
}

void Productor::producir() {
    std::string linea;
    char char_final = ')';
    char salto_linea;
    while (std::getline(std::cin, linea, char_final)) {
        if (!std::cin.get(salto_linea)) break; // Leeo el salto de linea
        this->parser.parsear(linea);
        linea.clear();
        std::string *entrada = this->parser.obtener_archivo_entrada();
        std::string *salida = this->parser.obtener_archivo_salida();
        std::string *cod_bf = this->parser.obtener_codigo_bf();
        int n = this->parser.obtener_prioridad();
        auto *interpr = new Interprete(cod_bf, entrada, salida);
        auto *interpreteConPrioridad = new InterpreteConPrioridad(interpr, n);
        this->cola_prior.push(interpreteConPrioridad);
    }
    std::cout << "Llega a finalizar" << std::endl;
    this->cola_prior.finalizado();
}

Productor::~Productor() {
}
