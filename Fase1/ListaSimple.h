#include "NodoSimple.h"

class ListaSimple{
    private:
    NodoSimple* primero;
    NodoSimple* ultimo;

    public:
    ListaSimple();
    ~ListaSimple();

    void append(string Nombres, string Apellidos,
    string FechaNacimiento, string Correo, string Password);

    bool buscar(string Correo, bool BanderaDatos, bool BanderaSecion);
    bool buscar2(string Correo, string Password);

    void eliminarUsuario(string Correo);
    void eliminarUsuarios();

    void print();
};