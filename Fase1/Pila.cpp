#include "Pila.h"
//------------------------------------------------------
Pila::Pila(){
    primeroP=nullptr;
    ultimoP=nullptr;
}
//------------------------------------------------------
Pila::~Pila(){
    NodoPila* temp=primeroP;
    NodoPila* aux;

    while(temp != nullptr){
        aux=temp->getSig();
        delete temp;
        temp=aux;
    }
}
//------------------------------------------------------
void Pila::appendPila(string Emisor, string Receptor, string Estado){
    NodoPila* nuevo_nodoPila = new NodoPila(Emisor, Receptor, Estado);

    if(primeroP == nullptr){
        primeroP=nuevo_nodoPila;
        ultimoP=nuevo_nodoPila;
    }
    else{
        ultimoP->setSig(nuevo_nodoPila);
        ultimoP=nuevo_nodoPila;
    }
}
//------------------------------------------------------
int Pila::MostrarSolPila(string Correo){
    NodoPila* temp=primeroP;
    int ContSol=0;

    cout<<"\n* ----- SOLICITUDES ----- *\n\n";
    cout<<"\n* << ----- Enviadas ----- >> *\n\n";
    while(temp != nullptr){
        if(temp->getEmisor() == Correo){//Solicitudes Enviadas
                cout<<"--<> Emisor: "<<temp->getEmisor()<<"\n";
                cout<<"--<> Receptor: "<<temp->getReceptor()<<"\n";
                cout<<"--<> Estado: "<<temp->getEstado()<<"\n\n";
        }
        temp=temp->getSig();
    }

    temp=primeroP;
    cout<<"\n* >> ----- Recividas ----- << *\n\n";
    while(temp != nullptr){
        if(temp->getReceptor() == Correo){//Solicitudes Recividas
                cout<<"--<> Emisor: "<<temp->getEmisor()<<"\n";
                cout<<"--<> Receptor: "<<temp->getReceptor()<<"\n";
                cout<<"--<> Estado: "<<temp->getEstado()<<"\n\n";
                if(temp->getEstado() =="PENDIENTE"){ContSol++;}
        }
        temp=temp->getSig();
    }
    return ContSol;
}
//------------------------------------------------------
void Pila::ActualizarSolPila(string Correo, string Estado){
    NodoPila* temp=primeroP;

    while(temp != nullptr){
        if(temp->getReceptor() == Correo){
            if(temp->getEstado() == "PENDIENTE"){
                if(Estado == "ver"){
                cout<<"\n--<> Emisor: "<<temp->getEmisor()<<"\n";
                cout<<"\n";
                break;
                }
                else{
                    temp->setEstado(Estado);//Actualiza el estado a ACEPTADA o RECHAZADA
                    break;
                }
            }
        }
        temp=temp->getSig();
    }
}
//------------------------------------------------------
bool Pila::buscarPila(string Emisor, string Receptor){
    NodoPila* temp=primeroP;

    while(temp != nullptr){
        if(temp->getEmisor() == Emisor && temp->getReceptor() == Receptor){
            return true;//Solicitud existente
        }
        temp=temp->getSig();
    }
    return false;//Solicitud no existente
}