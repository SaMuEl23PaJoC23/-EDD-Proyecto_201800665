#include "NodoMatriz.h"

NodoMatriz::NodoMatriz(string i, string j){//NodoMatriz encabezados
    this->usu_i = i;
    this->usu_j = j;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->izq = nullptr;
    this->dcha = nullptr;
}

NodoMatriz::NodoMatriz(string i, string j, bool data){//NodoMatriz para data
    this->data = data;
    this->usu_i = i;
    this->usu_j = j;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->izq = nullptr;
    this->dcha = nullptr;   
}
// ---------- Setters ----------
void NodoMatriz::setData(bool data){
    this->data = data;
}

void NodoMatriz::setUsu_I(string i){
    this->usu_i = i;
}

void NodoMatriz::setUsu_J(string j){
    this->usu_j = j;
}

void NodoMatriz::setArriba(NodoMatriz *arriba){
    this->arriba = arriba;
}

void NodoMatriz::setAbajo(NodoMatriz *abajo){
    this->abajo = abajo;
}

void NodoMatriz::setIzq(NodoMatriz *izq){
    this->izq = izq;
}

void NodoMatriz::setDcha(NodoMatriz *dcha){
    this->dcha = dcha;
}
//---------- Getters ----------
bool NodoMatriz::getData(){
    return data;
}

string NodoMatriz::getUsu_I(){
    return usu_i;
}

string NodoMatriz::getUsu_J(){
    return usu_j;
}

NodoMatriz* NodoMatriz::getArriba(){
    return arriba;
}

NodoMatriz* NodoMatriz::getAbajo(){
    return abajo;
}

NodoMatriz* NodoMatriz::getIzq(){
    return izq;
}

NodoMatriz* NodoMatriz::getDcha(){
    return dcha;
}