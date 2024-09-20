#include "Menu.cpp"
#include "ListaSimple.h"
#include "AbrirArchivo.cpp"
#include "Pila.h"
#include "ListaDoble.h"
//------------------------------------------------------------------------------------------
int main(int argc, char const *argv[]){
    Menu m;
    ListaSimple ls;
    Pila p;
    ListaDoble ld;

    int op1=0, opAdmin=0, opUsu=0, numSol=0, cantSol=0;
    char opUsu2=' ', opSol=' ';
    string Correo="", Password="", Nombres="", Apellidos="", 
    FechaNacimiento="", direccion="", texto="", ContenidoP="", FechaP="", HoraP="", envSol="";

    AbrirArchivo abrirD; //abrirD = abrir documento
    bool ban1=false, bandEliminado=true;
    

    
    do{
        m.Principal();
        cout<<"Opcion: ";
        cin>>op1;
        cout<<"**********************************\n\n";
        switch(op1){
//------------------------------------------------- Iniciar Secion -------------------
        case 1:
            cout<<"Correo: ";
            cin>>Correo;
            cout<<"Password: ";
            cin>>Password;
            
            if(Correo=="admin@gmail.com" && Password=="EDD2S2024"){
                do{//------------------------------------Menu ADMIN ------------------------------------
                    m.Administrador();
                    cout<<"Opcion: ";
                    cin>>opAdmin;
                    cout<<"==================================\n\n";
                    switch(opAdmin){
                    case 1:
                        cout<<"... Realizando carga de USUARIOS ...\n";
                        //cout<<"Direccion del Archivo: ";
                        //cin>>direccion;
                        direccion="C:\\Users\\samal\\Desktop\\-EDD-Proyecto_201800665\\Fase1\\archivosCarga\\usuarios.json";
                        texto=abrirD.lectura(direccion);
                        //cout<<texto;
                        if(texto != ""){  
                            int contador=0, contadorD=0;    //ContadorD = contador de datos, reiniciado cada 5 atributos
                            bool bandera1=false;
                            string cadena="";
                            vector <string> datos={};

                            for(char caracter:texto){
                                if(caracter == '"'){
                                    contador++;
                                    if(contador == 3){
                                        bandera1=true;
                                        continue;
                                    }
                                    if(contador == 4){
                                        bandera1=false;
                                        contador=0;
                                        //cout<<cadena<<"\n";
                                        datos.push_back(cadena);
                                        contadorD++;
                                        cadena="";
                                    }

                                    if(contadorD==5){ //Se almacena los atributos en un nodo de la lista simple
                                        ls.append(datos[0],datos[1],datos[2],datos[3],datos[4]);
                                        //cout<<datos[0]<<"\n";
                                        //cout<<datos[1]<<"\n";
                                        //cout<<datos[2]<<"\n";
                                        //cout<<datos[3]<<"\n";
                                        //cout<<datos[4]<<"\n\n";
                                        datos={};
                                        contadorD=0;
                                    }
                                }

                                if(bandera1==true){ //Se concatenan caracteres para formar los atributos
                                    cadena+=caracter;
                                }
                                
                            }
                            cout<<"\n--> Usuarios Cargados!!\n\n";
                        }
                        system("pause");
                        bandEliminado=false;
                        break;

                    case 2:
                        cout<<"... Realizando carga de RELACIONES ...\n\n";
                        //cout<<"Direccion del Archivo: ";
                        //cin>>direccion;
                        direccion="C:\\Users\\samal\\Desktop\\-EDD-Proyecto_201800665\\Fase1\\archivosCarga\\solicitudes.json";
                        texto=abrirD.lectura(direccion);
                        //cout<<texto;
                        if(texto != ""){  
                            int contador=0, contadorD=0;    //ContadorD = contador de datos, reiniciado cada 5 atributos
                            bool bandera1=false;
                            string cadena="";
                            vector <string> datos={};

                            for(char caracter:texto){
                                if(caracter == '"'){
                                    contador++;
                                    if(contador == 3){
                                        bandera1=true;
                                        continue;
                                    }
                                    if(contador == 4){
                                        bandera1=false;
                                        contador=0;
                                        //cout<<cadena<<"\n";
                                        datos.push_back(cadena);
                                        contadorD++;
                                        cadena="";
                                    }

                                    if(contadorD==3){
                                        if(p.buscarPila(datos[0], datos[1]) == false){//Verifica que la solicitud no exista
                                            p.appendPila(datos[0], datos[1], datos[2]);//Se almacena los atributos en un nodo de la lista simple
                                        }
                                        //cout<<datos[0]<<"\n";
                                        //cout<<datos[1]<<"\n";
                                        //cout<<datos[2]<<"\n\n";
                                        datos={};
                                        contadorD=0;
                                    }
                                }

                                if(bandera1==true){ //Se concatenan caracteres para formar los atributos
                                    cadena+=caracter;
                                }
                                
                            }
                            cout<<"\n--> Solicitudes Cargadas !!\n\n";
                        }
                        system("pause");
                        break;

                    case 3:
                        cout<<"... Realizando carga de PUBLICACIONES ...\n\n";
                        //cout<<"Direccion del Archivo: ";
                        //cin>>direccion;
                        direccion="C:\\Users\\samal\\Desktop\\-EDD-Proyecto_201800665\\Fase1\\archivosCarga\\publicaciones.json";
                        texto=abrirD.lectura(direccion);
                        //cout<<texto;
                        if(texto != ""){  
                            int contador=0, contadorD=0;    //ContadorD = contador de datos, reiniciado cada 5 atributos
                            bool bandera1=false;
                            string cadena="";
                            vector <string> datos={};

                            for(char caracter:texto){    
                                if(caracter == '"'){
                                    contador++;
                                    if(contador == 3){
                                        bandera1=true;
                                        continue;
                                    }
                                    if(contador == 4){
                                        bandera1=false;
                                        contador=0;
                                        //cout<<cadena<<"\n";
                                        datos.push_back(cadena);
                                        contadorD++;
                                        cadena="";
                                    }

                                    if(contadorD==4){ //Se almacena los atributos en un nodo de la lista doble
                                        ld.appendDoble(datos[0], datos[1], datos[2], datos[3]);
                                        //cout<<datos[0]<<"\n";
                                        //cout<<datos[1]<<"\n";
                                        //cout<<datos[2]<<"\n";
                                        //cout<<datos[3]<<"\n\n";
                                        datos={};
                                        contadorD=0;
                                    }
                                }

                                if(bandera1==true){ //Se concatenan caracteres para formar los atributos
                                    cadena+=caracter;
                                }
                                
                            }
                            cout<<"\n--> Publicaciones Cargadas !!\n\n";
                        }
                        system("pause");
                        break;

                        break;
                    case 4:
                        do{
                            cout<<"<> ... gestion de USUARIOS ... <>\n";
                            cout<<"a). ELIMINAR USUARIOS\n";
                            cout<<"r). Regresar\n";
                            cout<<"Opcion: ";
                            cin>>opUsu2;
                            cout<<"<> ============================ <>\n\n";
                            if(opUsu2=='a'){
                                ls.eliminarUsuarios();
                                cout<<"--> USUARIOS ELIMINADOS !!!\n\n";
                                system("pause");
                                opUsu2='r';
                            }
                            else if(opUsu2=='r'){
                                cout<<"\n--- REGRESANDO --- \n";
                                system("pause");
                            }
                            else{
                                cout<<"\nOpcion No valida...\n\n";
                            }
                        }while (opUsu2 != 'r');
                        break;

                    case 5:
                        cout<<"Reportes...\n";
                        break;
                    
                    default:
                        if(opAdmin != 6)cout<<"\nOpcion No valida...\n";
                        else{cout<<"SESION -Admin- FINALIZADA! \n";}
                        break;
                    }
                }while(opAdmin!=6);
                
            }            
            else{//-------------------------Menu USUARIO ----------------------------------------------
                ban1=false;
                ban1=ls.buscar2(Correo, Password);
                if(ban1 == true){//Verifica si el usuario EXISTE, sino no puede continuar.
                    do{
                        m.Usuario();
                        cout<<"Opcion: ";
                        cin>>opUsu;
                        cout<<"==================================\n\n";
                        switch(opUsu){
                            case 1:
                                do{    
                                    cout<<"============= PERFIL =============\n";
                                    cout<<"a). Ver Perfil\n";
                                    cout<<"b). Eliminar Cuenta\n";
                                    cout<<"r). Regresar\n";
                                    cout<<"Opcion: ";
                                    cin>>opUsu2;
                                    cout<<"==================================\n\n";
                                    switch (opUsu2){
                                        case 'a':
                                            ban1=ls.buscar(Correo, true, false);
                                            system("pause");
                                            break;
                                        
                                        case 'b':
                                            ls.eliminarUsuario(Correo);
                                            cout<<"Cuenta Eliminada....\n\n";
                                            opUsu2='r';
                                            opUsu=5;
                                            cout<<"--- REGRESANDO --- \n\n";
                                            system("pause");
                                            break;
                                        
                                        default:
                                            if(opUsu2 != 'r')cout<<"\nOpcion No valida...\n\n";
                                            else{cout<<"--- REGRESANDO --- \n";}
                                            break;
                                    }
                                }while(opUsu2 != 'r');
                                break;
                            
                            case 2:
                                do{
                                    cout<<"\n<>.............................<>\n";
                                    cout<<"<> ....... Solicitudes ....... <>\n";
                                    cout<<"a). Ver solicitudes\n";
                                    cout<<"b). Enviar\n";
                                    cout<<"r). Regresar\n";
                                    cout<<"Opcion: ";
                                    cin>>opUsu2;
                                    cout<<"<>.............................<>\n";
                                    switch (opUsu2){
                                        case 'a':
                                            numSol=0;
                                            cantSol=p.MostrarSolPila(Correo);//Muestra solicitudes enviadas y recividas
                                            cout<<"Solicitudes Pendientes: "<<cantSol<<"\n";
                                            cout<<"\n* ----- Aceptar/Rechazar ----- *\n\n";
                                            while(numSol != cantSol){
                                                p.ActualizarSolPila(Correo, "ver");
                                                cout<<"a) Aceptar\n";
                                                cout<<"r) Rechazar\n";
                                                cout<<"Opcion: ";
                                                cin>>opSol;
                                                switch (opSol){
                                                    case 'a':
                                                        p.ActualizarSolPila(Correo, "ACEPTADA");
                                                        numSol++;
                                                        break;
                                                    
                                                    case 'r':
                                                        p.ActualizarSolPila(Correo, "RECHAZAR");
                                                        numSol++;
                                                        break;
                                                    
                                                    default:
                                                        cout<<"\nOpcion No valida...\n\n";
                                                        break;
                                                }
                                            }
                                            if(numSol==0){
                                                cout<<"No hay solicitudes...\n\n";
                                                system("pause");
                                            }
                                            break;

                                        case 'b':
                                            cout<<"\n* ----- Enviar Solicitud ----- *\n\n";
                                            cout<<"Correo Receptor: ";
                                            cin>>envSol;
                                            ban1=ls.buscar(envSol, false, false);
                                            if(ban1==true){
                                                if(Correo != envSol){
                                                    if(p.buscarPila(Correo, envSol) == false){//Verifica que la solicitud no exista, ACTUALIZAR hacia matriz de relacion
                                                        p.appendPila(Correo, envSol, "PENDIENTE");
                                                        cout<<"\nSolicitud Enviada\n\n";
                                                    }
                                                    else{
                                                        cout<<"\nSolicitud ya Enviada\n\n";
                                                    }
                                                }
                                                else{
                                                    cout<<"\nNo puedes enviarte solicitud a ti mismo!\n\n";
                                                }
                                            }
                                            else{cout<<"\nCorreo No existente...\n\n";}
                                            system("pause");
                                            break;

                                        default:
                                            if(opUsu2 != 'r')cout<<"\nOpcion No valida...\n\n";
                                            else{cout<<"\n--- REGRESANDO --- \n";}
                                            break;
                                    }     
                                }while(opUsu2 != 'r');
                                break;

                            case 3:
                                
                                do{
                                    cout<<"\n<>.................................<>\n";
                                    cout<<"<> ........ Publicaciones ........ <>\n";
                                    cout<<"a). Ver todas (Tuyas y Solo amigos)\n";
                                    cout<<"b). Crear Publicacion\n";
                                    cout<<"c). Eliminar publicacion\n";
                                    cout<<"r). Regresar\n";
                                    cout<<"Opcion: ";
                                    cin>>opUsu2;
                                    cout<<"<>.................................<>\n";
                                    switch (opUsu2){
                                        case 'a':
                                            ld.printD();
                                            system("pause");
                                            break;

                                        case 'b':
                                            cout<<"\n>>  Creando publicacion  <<\n";
                                            cin.get();
                                            cout<<"Contenido: ";
                                            getline(cin, ContenidoP);
                                            cout<<"Fecha: ";
                                            cin>>FechaP;
                                            cout<<"Hora: ";
                                            cin>>HoraP;
                                            ld.appendDoble(Correo, ContenidoP, FechaP, HoraP);
                                            cout<<"\n! Publicacion Creada !\n\n";
                                            system("pause");
                                            break;

                                        case 'c':
                                            cout<<"Fecha: ";
                                            cin>>FechaP;
                                            cout<<"Hora: ";
                                            cin>>HoraP;
                                            ld.eliminarPub(Correo ,FechaP , HoraP);
                                            system("pause");
                                            break;
                                        
                                        default:
                                            if(opUsu2 != 'r')cout<<"\nOpcion No valida...\n\n";
                                            else{cout<<"\n--- REGRESANDO --- \n";}
                                            break;
                                    }     
                                }while(opUsu2 != 'r');
                                break;

                            case 4:
                                cout<<"Reportes...\n";
                                break;

                            default:
                                if(opUsu != 5)cout<<"\nOpcion No valida...\n";
                                else{cout<<"SESION FINALIZADA!\n";}
                                break;
                        }
                    }while(opUsu != 5);
                }
                else{cout<<"\n\n!! Usuario NO existente !!\n\n";}
                
            }
            break;
//------------------------------------------------- Registrarse -------------------
        case 2:
            cout<<"<> ------- REGISTRARSE ------- <>\n";
            cin.get();
            cout<<"Nombres: ";
            getline(cin, Nombres);
            cout<<"Apellidos: ";
            getline(cin, Apellidos);
            cout<<"Fecha de nacimiento: ";
            cin>>FechaNacimiento;
            cout<<"Correo electronico: ";
            cin>>Correo;
            
            ban1=false;
            ban1=ls.buscar(Correo, false, true);//Se verifica que el correo no exista, luego guarda nodo en lista SIMPLE
            if(ban1 == false){
                cout<<"Password: ";
                cin>>Password;
                ls.append(Nombres, Apellidos, FechaNacimiento, Correo, Password);
                cout<<"\n!! Usuario Creado !!\n\n";
            }
            bandEliminado=false;
            break;
//------------------------------------------------- INFORMACION -------------------
        case 3:
            cout<<"\n[----------------------------------]\n";
            cout<<"         Estructura de Datos.\n";
            cout<<"    Samuel Alejandro Pajoc Raymundo.\n";
            cout<<"             201800665.\n";
            cout<<"[----------------------------------]\n\n";
            cout<<"--> Usuarios Registrados <-- \n\n";
            ls.print();
            break;
//---------------------------------------------------------------------------------        
        default:
            if(op1 != 4)cout<<"\nOpcion No valida...\n\n";
            break;
        }
    }while(op1 != 4);
    return 0;
}