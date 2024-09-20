#include "base.h"

class NodoSimple{ //Nodo Simple List
    private:
    string Nombres;
    string Apellidos;
    string FechaNacimiento;
    string Correo;
    string Password;
    NodoSimple *siguiente;

    public:
    NodoSimple(string Nombres, string Apellidos, 
    string FechaNacimiento, string Correo, string Password);

    void setNombres(string dato);
    string getNombres();

    void setApellidos(string dato);
    string getApellidos();

    void setFechaNacimiento(string dato);
    string getFechaNacimiento();

    void setCorreo(string dato);
    string getCorreo();

    void setPassword(string dato);
    string getPassword();

    void setSiguiente(NodoSimple* siguiente);
    NodoSimple* getSiguiente();
};