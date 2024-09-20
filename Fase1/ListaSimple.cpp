#include "ListaSimple.h"
//------------------------------------------------------
ListaSimple::ListaSimple(){
    primero=nullptr;
    ultimo=nullptr;
}
//------------------------------------------------------
ListaSimple::~ListaSimple(){
    NodoSimple* temp=primero;
    NodoSimple* aux;

    while(temp!=nullptr){
        aux=temp->getSiguiente();
        delete temp;
        temp=aux;
    }
}
//------------------------------------------------------
void ListaSimple::append(string Nombres, string Apellidos,
    string FechaNacimiento, string Correo, string Password){
    NodoSimple* nuevo_nodo = new NodoSimple(Nombres, Apellidos, FechaNacimiento, Correo, Password);

    if(primero == nullptr){
        primero=nuevo_nodo;
        ultimo=nuevo_nodo;
    }
    else{
        ultimo->setSiguiente(nuevo_nodo);
        ultimo=nuevo_nodo;
    }
}
//------------------------------------------------------
void ListaSimple::print(){
    NodoSimple* temp = primero;

    if (temp!=nullptr){
        while(temp!=nullptr){
        cout<<temp->getNombres()<<"\n";
        cout<<temp->getApellidos()<<"\n";
        cout<<temp->getFechaNacimiento()<<"\n";
        cout<<temp->getCorreo()<<"\n";
        cout<<temp->getPassword()<<"\n";
        cout<<"................\n";
        temp=temp->getSiguiente();
        }
        cout<<endl;
    }
    else{cout<<"No hay usuarios para mostrar...\n\n";}    
}
//------------------------------------------------------
bool ListaSimple::buscar(string Correo, bool BanderaDatos, bool BanderaSecion){
    NodoSimple* temp = primero;

    while(temp!=nullptr){
        if(temp->getCorreo() == Correo){
            if(BanderaDatos==false){
                if(BanderaSecion == true){cout<<"\n\nCorreo ya existente...!\n\n";}
                return true;
            }
            else{
                cout<<" -) Nombres: "<<temp->getNombres()<<"\n";
                cout<<" -) Apellidos: "<<temp->getApellidos()<<"\n";
                cout<<" -) Fecha de nacimiento: "<<temp->getFechaNacimiento()<<"\n";
                cout<<" -) Correo: "<<temp->getCorreo()<<"\n";
                cout<<" -) Password: "<<temp->getPassword()<<"\n\n";
            }   
        }
        temp=temp->getSiguiente();
    }
    return false;
}
//------------------------------------------------------
bool ListaSimple::buscar2(string Correo, string Password){
    NodoSimple* temp = primero;

    while(temp!=nullptr){
        if(temp->getCorreo() == Correo){
            if(temp->getPassword() == Password){
                return true;
            }else{cout<<"\nPassword Incorrecto !!";return false;}
        }
        temp=temp->getSiguiente();
    }
    return false;
}
//------------------------------------------------------
void ListaSimple::eliminarUsuario(string Correo){
    NodoSimple *actual = primero;
    NodoSimple *anterior = nullptr;
    while(actual != nullptr && actual->getCorreo() != Correo){
        anterior = actual;
        actual = actual->getSiguiente();
    }
    if(actual == nullptr){//Significa que no se encontró el nodo con ese dato o la lista esta vacia
        if(primero == nullptr){cout<<"La lista esta Vacia... !\n\n";}
        else{cout<<"No se encontro el elemento en la lista \n\n";}
    }
    else{
        if(primero == actual){//Significa que vamos a eliminar el primer nodo
            actual = primero->getSiguiente();
            delete primero;
            primero = actual;
            if(primero == nullptr){
                ultimo=primero;
            }
        }
        else{
            anterior->setSiguiente(actual->getSiguiente()); 
            delete actual;
            if(anterior->getSiguiente()==nullptr){
                ultimo = anterior;
            }
        }
    }
}
//------------------------------------------------------
void ListaSimple::eliminarUsuarios(){
    NodoSimple *aux;

    while(primero != nullptr){
        aux = primero->getSiguiente();
        delete primero;
        primero = aux;
    }
}