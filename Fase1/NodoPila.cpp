#include "NodoPila.h"
//Constructor
NodoPila::NodoPila(string Emisor, string Receptor, string Estado){
    this->Emisor=Emisor;
    this->Receptor=Receptor;
    this->Estado=Estado;
    sig=nullptr;
}

//Getters
string NodoPila::getEmisor(){return Emisor;}

string NodoPila::getReceptor(){return Receptor;}

string NodoPila::getEstado(){return Estado;}

NodoPila* NodoPila::getSig(){return sig;}

//Setters
void NodoPila::setEmisor(string dato){this->Emisor=dato;}

void NodoPila::setReceptor(string dato){this->Receptor=dato;}

void NodoPila::setEstado(string dato){this->Estado=dato;}

void NodoPila::setSig(NodoPila* siguiente){this->sig=siguiente;}