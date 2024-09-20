#include "NodoSimple.h"

//Constructor
NodoSimple::NodoSimple(string Nombres, string Apellidos, 
string FechaNacimiento, string Correo, string Password){
    this->Nombres=Nombres;
    this->Apellidos=Apellidos;
    this->FechaNacimiento=FechaNacimiento;
    this->Correo=Correo;
    this->Password=Password;
    siguiente=nullptr;
}

//Getters
string NodoSimple::getNombres(){return Nombres;}

string NodoSimple::getApellidos(){return Apellidos;}

string NodoSimple::getFechaNacimiento(){return FechaNacimiento;}

string NodoSimple::getCorreo(){return Correo;}

string NodoSimple::getPassword(){return Password;}

NodoSimple* NodoSimple::getSiguiente(){return siguiente;}

//Setters
void NodoSimple::setNombres(string dato){this->Nombres=dato;}

void NodoSimple::setApellidos(string dato){this->Apellidos=dato;}

void NodoSimple::setFechaNacimiento(string dato){this->FechaNacimiento=dato;}

void NodoSimple::setCorreo(string dato){this->Correo=dato;}

void NodoSimple::setPassword(string dato){this->Password=dato;}

void NodoSimple::setSiguiente(NodoSimple* siguiente){this->siguiente=siguiente;}