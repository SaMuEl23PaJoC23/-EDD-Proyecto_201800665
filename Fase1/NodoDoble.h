#include "base.h"

class NodoDoble{
    private:
    string Publicador;
    string Contenido;
    string Fecha;
    string Hora;
    NodoDoble* previoD;
    NodoDoble* siguienteD;

    public:
    NodoDoble(string Publicador, string Contenido, string Fecha, string Hora);

    void setPublicador(string dato);
    string getPublicador();

    void setContenido(string dato);
    string getContenido();

    void setFecha(string dato);
    string getFecha();

    void setHora(string dato);
    string getHora();

    void setPrevioD(NodoDoble* previo);
    NodoDoble* getPrevioD();

    void setSiguienteD(NodoDoble* siguiente);
    NodoDoble* getSiguienteD();
};