#include "matriz.h"

int main(int argc, char const *argv[])
{
    Matriz m;//(usu_I, usu_J, data);
    m.insert("carlos","roberto",true);
    m.insert("pedro","roberto",true);

    m.insert("carlos","maria",true);
    m.insert("carlos","pedro",true);
    m.insert("pedro","maria",true);
    m.insert("samuel","linda",true);
    m.insert("linda","pedro",true);
    
    //m.print();
    m.graph();
    return 0;
}