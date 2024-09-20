#include "ListaDoble.h"
//------------------------------------------------------
ListaDoble::ListaDoble(){
    primeroD=nullptr;
    ultimoD=nullptr;
}
//------------------------------------------------------
ListaDoble::~ListaDoble(){
    NodoDoble* temp = primeroD;
    NodoDoble* aux;

    while(temp != nullptr){
        aux = temp->getSiguienteD();
        delete temp;
        temp = aux;
    }
}
//------------------------------------------------------
void ListaDoble::appendDoble(string Correo, string Contenido, string Fecha, string Hora){
    NodoDoble* nuevo_nodoDoble = new NodoDoble(Correo, Contenido, Fecha, Hora);

    if(primeroD == nullptr){
        primeroD = nuevo_nodoDoble;
        ultimoD = nuevo_nodoDoble;
    }
    else{
        nuevo_nodoDoble->setPrevioD(ultimoD);
        ultimoD->setSiguienteD(nuevo_nodoDoble);
        ultimoD = nuevo_nodoDoble;
    }
}
//------------------------------------------------------
void ListaDoble::printD(){
    NodoDoble* temp = primeroD;

    if(temp != nullptr){
        while(temp != nullptr){
            cout<<temp->getPublicador()<<"\n";
            cout<<temp->getContenido()<<"\n";
            cout<<temp->getFecha()<<"\n";
            cout<<temp->getHora()<<"\n";
            cout<<"................\n";
            temp = temp->getSiguienteD();
        }
        cout<<endl;
    }
    else{cout<<"\nNo hay publicaciones para mostrar...\n\n";}
}
//------------------------------------------------------
void ListaDoble::eliminarPub(string Correo, string Fecha, string Hora){
     NodoDoble *actual = primeroD;
    NodoDoble *anterior = nullptr;
    while(actual != nullptr){
        if (actual->getPublicador() == Correo){
            if(actual->getFecha()== Fecha){
                if(actual->getHora() == Hora){
                    break;
                }
            }
        }
        anterior = actual;
        actual = actual->getSiguienteD();
    }
    if(actual == nullptr){//Significa que no se encontró el nodo con ese dato o la lista esta vacia
        if(primeroD == nullptr){cout<<"La lista esta Vacia... !\n\n";}
        else{cout<<"No se encontro el elemento en la lista \n\n";}
    }
    else{
        if(actual == primeroD){//Significa que vamos a eliminar el primer nodo
            actual = primeroD->getSiguienteD();            
            if(actual != nullptr){
                actual->setPrevioD(anterior);
            }
            else{ultimoD = actual;} 
            
            delete primeroD;
            primeroD = actual;
        }
        else{
            anterior->setSiguienteD(actual->getSiguienteD());
            if (actual->getSiguienteD() != nullptr){
                actual->getSiguienteD()->setPrevioD(anterior);
            }
            else{
                ultimoD = anterior;
            }
            delete actual;
        }
        cout<<"\n! Publicacion Eliminada !\n\n";
    }
}