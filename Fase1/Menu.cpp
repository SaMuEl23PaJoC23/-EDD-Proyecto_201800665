#include "base.h"

class Menu{

public:
    void Principal(){
    cout<<"\n**********************************\n";
    cout<<"***** .:: Menu Principal ::. *****\n\n";
    cout<<"1) Iniciar Sesion \n";
    cout<<"2) Registrarse \n";
    cout<<"3) Informacion \n";
    cout<<"4) Salir \n";
    }

    void Administrador(){
        cout<<"\n==================================\n";
        cout<<"==== <> Menu Administrador <> ====\n";
        cout<<"1* Carga de Usuarios \n";
        cout<<"2* Carga de relaciones \n";
        cout<<"3* Carga de publicaciones  \n";
        cout<<"4* Gestionar Usuarios \n";
        cout<<"5* Reportes \n";
        cout<<"6* Salir modo -Admin- \n";
    }

    void Usuario(){
        cout<<"\n==================================\n";
        cout<<"======= .: Menu Usuario :. =======\n";
        cout<<"1). Perfil \n";
        cout<<"2). Solicitudes \n";
        cout<<"3). Publicaciones  \n";
        cout<<"4). Reportes \n";
        cout<<"5). Cerrar Secion \n";
    }

};
