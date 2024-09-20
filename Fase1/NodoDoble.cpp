#include "NodoDoble.h"
//Constructor
NodoDoble::NodoDoble(string Publicador, string Contenido, string Fecha, string Hora){
    this->Publicador=Publicador;
    this->Contenido=Contenido;
    this->Fecha=Fecha;
    this->Hora=Hora;
    previoD=nullptr;
    siguienteD=nullptr;
}

//Getters
string NodoDoble::getPublicador(){return Publicador;}

string NodoDoble::getContenido(){return Contenido;}

string NodoDoble::getFecha(){return Fecha;}

string NodoDoble::getHora(){return Hora;}

NodoDoble* NodoDoble::getPrevioD(){return previoD;}

NodoDoble* NodoDoble::getSiguienteD(){return siguienteD;}

//Setters
void NodoDoble::setPublicador(string dato){this->Publicador=dato;}

void NodoDoble::setContenido(string dato){this->Contenido=dato;}

void NodoDoble::setFecha(string dato){this->Fecha=dato;}

void NodoDoble::setHora(string dato){this->Hora=dato;}

void NodoDoble::setPrevioD(NodoDoble* previo){this->previoD=previo;}

void NodoDoble::setSiguienteD(NodoDoble* siguiente){this->siguienteD=siguiente;}
