#include "NodoMatriz.h"

class Matriz {
    private:
        NodoMatriz *raiz;
        int ancho;
        int alto;

        NodoMatriz* buscarColumna(string usu_i);
        NodoMatriz* buscarFila(string usu_j);

        void insertarEnFila(NodoMatriz *nuevo, NodoMatriz *encabezadoColumna);
        void insertarEnColumna(NodoMatriz *nuevo, NodoMatriz *encabezadoFila);

        NodoMatriz* insertarEncabezadoFila(string usu_j);
        NodoMatriz* insertarEncabezadoColumna(string usu_i);

    public:
        Matriz();
        ~Matriz();

        void insert(string usu_i, string usu_j, bool data);

        bool existeNodoMatriz(NodoMatriz *nuevo);
        void print();
        void graph();
};