#include "base.h"

class NodoPila{
    private:
    string Emisor;
    string Receptor;
    string Estado;
    NodoPila* sig;

    public:
    NodoPila(string Emisor, string Receptor, string Estado);

    void setEmisor(string dato);
    string getEmisor();

    void setReceptor(string dato);
    string getReceptor();

    void setEstado(string dato);
    string getEstado();

    void setSig(NodoPila* siguiente);
    NodoPila* getSig();
};