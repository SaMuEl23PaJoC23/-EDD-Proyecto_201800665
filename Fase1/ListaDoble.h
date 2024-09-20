#include "NodoDoble.h"

class ListaDoble{
    private:
    NodoDoble* primeroD;
    NodoDoble* ultimoD;

    public:
    ListaDoble();
    ~ListaDoble();

    void appendDoble(string Publicador, string Contenido, string Fecha, string Hora);

    void printD();

    void eliminarPub(string Correo, string Fecha, string Hora);
};