#include "NodoPila.h"

class Pila{
    private:
    NodoPila* primeroP;
    NodoPila* ultimoP;

    public:
    Pila();
    ~Pila();

    void appendPila(string Emisor, string Receptor, string Estado);

    int MostrarSolPila(string Correo);

    void ActualizarSolPila(string Correo, string Estado);

    bool buscarPila(string Emisor, string Receptor);
};