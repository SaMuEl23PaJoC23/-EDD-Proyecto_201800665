#include "Matriz.h"

Matriz::Matriz(){
    this->raiz  = new NodoMatriz("-1", "-1");
    this->alto = 0;
    this->ancho = 0;
}

Matriz::~Matriz(){
    NodoMatriz *temp = raiz;
    NodoMatriz *aux;

    while(temp != nullptr){
        NodoMatriz *tempFila = temp;
        NodoMatriz *auxFila;

        aux = temp->getAbajo();

        while(tempFila != nullptr){
            auxFila = tempFila->getDcha();
            delete tempFila;
            tempFila = auxFila;
        }

        temp = aux;
    }
}

void Matriz::insert(string usu_i, string usu_j, bool data){
    NodoMatriz *nuevo = new NodoMatriz(usu_i, usu_j, data);

    NodoMatriz *columna = buscarColumna(usu_i);//retorna columna donde se inserta nodo
    NodoMatriz *fila = buscarFila(usu_j);//retorna fila donde se inserta nodo
    
    if(!this->existeNodoMatriz(nuevo)){
        if(columna == nullptr){//crea los encabezados de columna
            columna = insertarEncabezadoColumna(usu_i);
            ancho++;
        }
        if(fila == nullptr){//Crea los encabezados de fila
            fila = insertarEncabezadoFila(usu_j);
            alto++;
        }

        insertarEnColumna(nuevo, fila);//inserta nodo en columna
        insertarEnFila(nuevo, columna);//inserta mismo nodo en fila
    }
}

bool Matriz::existeNodoMatriz(NodoMatriz *nuevo){
    NodoMatriz *encabezadoFila = this->raiz;

    while(encabezadoFila != nullptr){
        if(encabezadoFila->getUsu_J() == nuevo->getUsu_J()){
            NodoMatriz *columna = encabezadoFila;

            while(columna != nullptr){
                if(columna->getUsu_I() == nuevo->getUsu_I()){
                    //columna->setData(nuevo->getData());
                    delete nuevo;
                    return true;
                }
                columna = columna->getDcha();
            }  
            return false; 
        }
        encabezadoFila = encabezadoFila->getAbajo();
    }
    return false;
}

NodoMatriz* Matriz:: insertarEncabezadoFila(string usu_j){//inserta encabezado en J
    NodoMatriz *nuevoEncabezadoFila = new NodoMatriz("-1", usu_j);
    this->insertarEnFila(nuevoEncabezadoFila, this->raiz);
    return nuevoEncabezadoFila;
}

NodoMatriz* Matriz:: insertarEncabezadoColumna(string usu_i){//inserta encabezado en I
    NodoMatriz *nuevoEncabezadoColumna = new NodoMatriz(usu_i, "-1");
    this->insertarEnColumna(nuevoEncabezadoColumna, this->raiz);
    return nuevoEncabezadoColumna;
}

void Matriz::insertarEnFila(NodoMatriz *nuevo, NodoMatriz *encabezadoColumna){
    NodoMatriz *temp = encabezadoColumna;

    while(temp->getAbajo() != nullptr){
        temp = temp->getAbajo();
    }
    temp->setAbajo(nuevo);
    nuevo->setArriba(temp);  
    
}

void Matriz::insertarEnColumna(NodoMatriz *nuevo, NodoMatriz *encabezadoFila){
    NodoMatriz *temp = encabezadoFila;

    while(temp->getDcha() != nullptr){
        temp = temp->getDcha();
    }
    temp->setDcha(nuevo);
    nuevo->setIzq(temp);    
}

NodoMatriz* Matriz::buscarColumna(string usu_i){//posiblemente sirva despues para 
    NodoMatriz *temp = this->raiz;

    while(temp != nullptr){
        if(temp->getUsu_I() == usu_i){
            return temp;
        }
        temp = temp->getDcha();
    }
    return nullptr;
}

NodoMatriz* Matriz::buscarFila(string usu_j){
    NodoMatriz *temp = this->raiz;

    while(temp != nullptr){
        if(temp->getUsu_J() == usu_j){
            return temp;
        }
        temp = temp->getAbajo();
    }
    return nullptr;
}

void Matriz::print(){
    NodoMatriz *temp = raiz;
    NodoMatriz *aux;

    cout<<" + "<<raiz->getUsu_I();
    while(temp != nullptr){
        NodoMatriz *tempFila = temp;
        NodoMatriz *auxFila;

        while(tempFila != nullptr){
            auxFila = tempFila->getDcha();
            if(auxFila != nullptr){
                cout<<" = "<<auxFila->getUsu_I();
            }
            tempFila = auxFila;
        }
        cout<<"\n";
        break;
    }

    temp=raiz->getAbajo();
    while(temp != nullptr){
        NodoMatriz *tempFila = temp;
        NodoMatriz *auxFila;
        aux = temp->getAbajo();
        cout<<" * "<<tempFila->getUsu_J();

        while(tempFila != nullptr){
            auxFila = tempFila->getDcha();
            if(auxFila != nullptr){
                cout<<" =+= "<<(auxFila->getData() ? " V " : " F ");
            }
            tempFila = auxFila;
        }
        cout<<"\n";
        temp = aux;
    }
}

void Matriz::graph(){
    ofstream outfile ("matriz.dot");
    NodoMatriz *aux_fila = raiz;
    NodoMatriz *aux_columna;
    string dec_nodo;
    string conexion;

    outfile << "digraph G {" << endl;
    outfile << "\tnode[shape=\"box\"]\n" << endl;
    
    while(aux_fila != nullptr){
        string rank = "{rank=same";
        aux_columna = aux_fila;

        while(aux_columna != nullptr){
            string i_coord = aux_columna->getUsu_I();
            string j_coord = aux_columna->getUsu_J();

            if(i_coord=="-1"){i_coord="0";}
            if(j_coord=="-1"){j_coord="0";}

            string nombre = "\tNodoMatriz" + i_coord + "_" + j_coord;

            if(aux_columna->getUsu_I() == "-1" && aux_columna->getUsu_J() == "-1"){
                dec_nodo = nombre + "[label = \"raiz\", group = \"" + i_coord + "\"]";
            
            }else if(aux_columna->getUsu_I() == "-1"){
                dec_nodo = nombre + "[label = \"" + aux_columna->getUsu_J() + "\"";
                dec_nodo += ", group = \"" + i_coord + "\"]";
            
            }else if(aux_columna->getUsu_J() == "-1"){
                dec_nodo = nombre + "[label = \"" + aux_columna->getUsu_I() + "\"";
                dec_nodo += ", group = \"" + i_coord + "\"]";
            
            }else{
                dec_nodo = nombre + "[label = \"" + (aux_columna->getData() ? "T" : "F") + "\"";
                dec_nodo += ", group = \"" + i_coord + "\"]";
            }

            outfile << dec_nodo << endl;

            if(aux_columna->getDcha() != nullptr){//Union de nodos hacia DERECHA de raiz
                
                if(aux_columna->getDcha()->getUsu_I() == "-1"){i_coord="0";}
                else{i_coord = aux_columna->getDcha()->getUsu_I();}
                conexion = nombre + "->NodoMatriz" + i_coord;
                
                
                if(aux_columna->getDcha()->getUsu_J() == "-1"){j_coord="0";}
                else{j_coord = aux_columna->getDcha()->getUsu_J();}
                conexion += "_"+j_coord;

                outfile << conexion << endl;
                outfile << conexion << "[dir = back]" << endl;
            }


            if(aux_columna->getAbajo() != nullptr){//Union de nodos hacia ABAJO de raiz

                if(aux_columna->getAbajo()->getUsu_I()=="-1"){i_coord="0";}
                else{i_coord = aux_columna->getAbajo()->getUsu_I();}
                conexion = nombre + "->NodoMatriz" + i_coord;

                if(aux_columna->getAbajo()->getUsu_J()=="-1"){j_coord=="0";}
                else{j_coord = aux_columna->getAbajo()->getUsu_J();}
                conexion += "_" + j_coord;

                outfile << conexion << endl;
                outfile << conexion << "[dir = back] \n" << endl;
            }

            rank+=";"+nombre;
            aux_columna = aux_columna->getDcha();
        }

        rank+="}\n\n";
        outfile << rank << endl;
        
        aux_fila = aux_fila->getAbajo();
    }
    outfile << "}" << endl;
    outfile.close();
    int returnCode = system("dot -Tpng ./matriz.dot -o ./matriz.png");

    if(returnCode == 0){cout << "\n>> Comando ejecutado exitosamente !!! <<\n" << endl;}
    else{cout << "\n>> Ejecucion del comando fallida... <<\n" << returnCode << endl;}
}