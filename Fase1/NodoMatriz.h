#include "base.h"

class NodoMatriz {
        private:
        string usu_i, usu_j;
        bool data = false;
        NodoMatriz *arriba, *abajo;
        NodoMatriz *izq, *dcha;

        public:
        NodoMatriz(string usu_i, string usu_j);//Nodo encabezados
        NodoMatriz(string usu_i, string usu_j, bool data);//Nodo para data
// ---------- Setters ----------
        void setUsu_I(string i);
        void setUsu_J(string j);
        void setData(bool data);

        void setArriba(NodoMatriz *arriba);
        void setAbajo(NodoMatriz *abajo);
        void setIzq(NodoMatriz *izq);
        void setDcha(NodoMatriz *dcha);
//---------- Getters ----------
        string getUsu_I();
        string getUsu_J();
        bool getData();

        NodoMatriz* getArriba();
        NodoMatriz* getAbajo();
        NodoMatriz* getIzq();
        NodoMatriz* getDcha();
};