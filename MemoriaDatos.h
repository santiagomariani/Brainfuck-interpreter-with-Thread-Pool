#ifndef TP2_MEMORIADATOS_H
#define TP2_MEMORIADATOS_H

struct MemoriaDatos {
    private:
    char *memoria;
    int ptr;
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
