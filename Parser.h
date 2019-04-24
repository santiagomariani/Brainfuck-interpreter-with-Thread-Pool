//
// Created by santi on 17/04/19.
//

#ifndef TP2_PARSER_H
#define TP2_PARSER_H

#include <string>
#include <vector>

class Parser {
    private:
    std::vector<std::string*> campos;
    int prioridad;
    // Destruye las cadenas que tiene el vector con los campos.
    void liberar_campos();

public:
    Parser();
    // Recibe una cadena con todos los campos. Parsea esta cadena
    // y guarda los campos por separado.
    void parsear(std::string &linea);
    // Devuelve el campo que tiene el nombre del archivo de entrada.
    std::string* obtener_archivo_entrada();
    // Devuelve el campo que tiene el nombre del archivo de salida.
    std::string* obtener_archivo_salida();
    // Devuelve el campo que tiene el codigo brainfuck.
    std::string* obtener_codigo_bf();
    // Devuelve el campo que tiene el nombre.
    std::string* obtener_nombre();
    // Devuelve el campo que tiene la prioridad.
    int obtener_prioridad();
    // Destruye las cadenas que tiene el vector con los campos.
    ~Parser();
};

#endif //TP2_PARSER_H
