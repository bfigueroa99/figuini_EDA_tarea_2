#include<iostream>
#include<fstream>
#include<cstdlib>  

using namespace std;

int main(){
    ifstream archivo("/home/figue/Documents/Codigos/EDA/Tareas/tarea2/figuini_EDA_tarea_2/test.html"); //hay que editar esto dependiendo el caso, pero en mi caso es asi.
    string texto;

    if(archivo.fail()){
        cout<<"no se pudo abrir"<<endl;
        exit(1);
    }

    while(!archivo.eof()){
        getline(archivo,texto);
        cout<<texto<<endl;
    }

    archivo.close();
    printf("me caes bien");
    return 0;
}