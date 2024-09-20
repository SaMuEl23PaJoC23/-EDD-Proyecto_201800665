#include "base.h"
#include <fstream>

class AbrirArchivo{
    private:
    string linea, texto;

    public:
        string lectura(string direccion){
        texto="";
        ifstream archivo(direccion);

        if(archivo.fail()){cout<<"Archivo no encontrado..."; return texto;}
        else{
            while(getline(archivo,linea)){
            texto+=linea;
            }     
        }
        archivo.close();
        return texto;
    }
};