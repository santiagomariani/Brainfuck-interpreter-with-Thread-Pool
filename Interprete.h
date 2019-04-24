#ifndef TP2_INTERPRETE_H
#define TP2_INTERPRETE_H

#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>

#include "MemoriaDatos.h"

class Interprete {
    private:
    MemoriaDatos memoria;
    std::istream *bf;
    std::istream *entrada;
    std::ostream *salida;
    bool io_estandar;
    // Interpreta los caracteres: ',', '.', '+', '-', '<' y '>'.
    // (Ejecuta logica correspondiente segun el caracter)
    void procesarCaracter(char c);
    // Verifica que los corchetes esten balanciados.
    bool sintaxisCorrecta();
    // Copia un loop entero en el buffer. Esto es por ej.:
    // "[[++.,~]+<[->+]]".
    void copiarLoop(std::vector<char> &buffer, std::map<int, int> &saltos);
    // Ejecuta el loop tantas veces como sea necesario. Si hay mas loops
    // adentro del loop principal, estos tambien se ejecutan.
    void ejecutarLoop(std::vector<char> &buffer, std::map<int, int> &saltos);

    public:
    // En caso de recibir solo una cadena, esta es el nombre del archivo
    // donde esta el codigo brainfuck, y los archivos de entrada
    // y salida seran los archivos de entrada y salida estandar
    // respectivamente.
    explicit Interprete(const std::string *bf);
    // En caso de recibir 3 cadenas, se utiliza un
    // determinado archivo de entrada, uno de salida y
    // ademas el codigo brainfuck a procesar sera el recibido
    // por parametro.
    Interprete(const std::string *bf,
            const std::string *entrada,
            const std::string *salida);
    // Interpreta el codigo brainfuck.
    int interpretar();
    ~Interprete();
};

#endif //TP2_INTERPRETE_H
