#include "nodo.h"

class Matriz {
    private:
        Nodo *raiz;
        int ancho;
        int alto;

        Nodo* buscarColumna(string usu_i);
        Nodo* buscarFila(string usu_j);

        void insertarEnFila(Nodo *nuevo, Nodo *encabezadoColumna);
        void insertarEnColumna(Nodo *nuevo, Nodo *encabezadoFila);

        Nodo* insertarEncabezadoFila(string usu_j);
        Nodo* insertarEncabezadoColumna(string usu_i);

    public:
        Matriz();
        ~Matriz();

        void insert(string usu_i, string usu_j, bool data);

        bool existeNodo(Nodo *nuevo);
        void print();
        void graph();
};