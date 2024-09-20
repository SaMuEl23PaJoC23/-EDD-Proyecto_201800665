#include "nodo.h"

Nodo::Nodo(string i, string j){//Nodo encabezados
    this->usu_i = i;
    this->usu_j = j;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->izq = nullptr;
    this->dcha = nullptr;
}

Nodo::Nodo(string i, string j, bool data){//Nodo para data
    this->data = data;
    this->usu_i = i;
    this->usu_j = j;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->izq = nullptr;
    this->dcha = nullptr;   
}
// ---------- Setters ----------
void Nodo::setData(bool data){
    this->data = data;
}

void Nodo::setUsu_I(string i){
    this->usu_i = i;
}

void Nodo::setUsu_J(string j){
    this->usu_j = j;
}

void Nodo::setArriba(Nodo *arriba){
    this->arriba = arriba;
}

void Nodo::setAbajo(Nodo *abajo){
    this->abajo = abajo;
}

void Nodo::setIzq(Nodo *izq){
    this->izq = izq;
}

void Nodo::setDcha(Nodo *dcha){
    this->dcha = dcha;
}
//---------- Getters ----------
bool Nodo::getData(){
    return data;
}

string Nodo::getUsu_I(){
    return usu_i;
}

string Nodo::getUsu_J(){
    return usu_j;
}

Nodo* Nodo::getArriba(){
    return arriba;
}

Nodo* Nodo::getAbajo(){
    return abajo;
}

Nodo* Nodo::getIzq(){
    return izq;
}

Nodo* Nodo::getDcha(){
    return dcha;
}