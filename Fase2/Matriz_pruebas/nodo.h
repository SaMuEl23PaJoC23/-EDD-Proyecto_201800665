#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Nodo {
        private:
        string usu_i, usu_j;
        bool data = false;
        Nodo *arriba, *abajo;
        Nodo *izq, *dcha;

        public:
        Nodo(string usu_i, string usu_j);//Nodo encabezados
        Nodo(string usu_i, string usu_j, bool data);//Nodo para data
// ---------- Setters ----------
        void setUsu_I(string i);
        void setUsu_J(string j);
        void setData(bool data);

        void setArriba(Nodo *arriba);
        void setAbajo(Nodo *abajo);
        void setIzq(Nodo *izq);
        void setDcha(Nodo *dcha);
//---------- Getters ----------
        string getUsu_I();
        string getUsu_J();
        bool getData();

        Nodo* getArriba();
        Nodo* getAbajo();
        Nodo* getIzq();
        Nodo* getDcha();
};