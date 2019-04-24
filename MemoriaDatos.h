#ifndef TP2_MEMORIADATOS_H
#define TP2_MEMORIADATOS_H

#include <vector>

struct MemoriaDatos {
    private:
    std::vector<unsigned char> memoria;
    std::vector<unsigned char>::iterator it;
    public:
    MemoriaDatos();
    // Avanza una posicion el puntero de datos.
    void avanzarPos();
    // Retrocede una posicion el puntero de datos.
    void retrocederPos();
    // Aumenta en 1 el valor apuntado por el puntero de datos.
    void aumentarValor();
    // Disminuye en 1 el valor apuntado por el puntero de datos.
    void disminuirValor();
    // Pone el valor recibido por parametro en el lugar
    // apuntado por el puntero de datos.
    void escribirValor(char c);
    // Devuelve el valor apuntado por el puntero de datos.
    char leerValor();
    ~MemoriaDatos();
};

#endif //TP2_MEMORIADATOS_H
