#include "Menu.cpp"

int main(int argc, char const *argv[]){
    Menu m;
    int op1=0;

    
    do{
        m.Principal();
        cout<<"Opcion: ";
        cin>>op1;
        if (op1 == 1){
            m.Administrador();
        }
        else if(op1 == 2){
            m.Usuario();
        }
        
    }while(op1 != 4);


    return 0;
}

