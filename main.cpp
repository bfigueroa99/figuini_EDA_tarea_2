#include"include/adts/node.hpp"
#include"include/adts/queue.hpp"
#include"include/adts/stack.hpp"
#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>

using namespace std;

int main(int argc, char* argv[]){

    // //FIGUE
    // const char* rutamain = "/home/figue/Documents/Codigos/EDA/Tareas/tarea2/figuini_EDA_tarea_2/main.log"; 
    // const char* rutatest = "/home/figue/Documents/Codigos/EDA/Tareas/tarea2/figuini_EDA_tarea_2/test.html";

    //Stefano
    const char* rutamain = "/home/stefano/dev/eda/figuini_EDA_tarea_2/main.log";
    string rutatest = "/home/stefano/dev/eda/figuini_EDA_tarea_2/test.html";

    FILE* archivo = fopen(rutatest.c_str(), "r"); //hay que editar esto dependiendo el caso, pero en mi caso es asi.
    string texto;

    string palabras_reservadas[12] = {"<body>","</body>","<center>","</center>","<h1>","</h1>","<p>","</p>","<ol>","</ol>","<li>","</li>"};

    //este freopen sera para escribir en el main.log
    freopen(rutamain, "w", stdout); //hay que editar esto para que sea en tu caso
    
    
    if(archivo == nullptr){
        cout<<"no se pudo abrir"<<endl;
        exit(1);
    }

    int pos = 0;
    char c;
    string word;
    bool found = false;
    eda::Stack stack;

    while(!feof(archivo)){
        c = getc(archivo);
        pos++;

        // bool error = false;
	    // int i = 0;
        // Stack stack;
        // while (!error && i < input.length()){
        //     if (input[i] == '(') {
        //         stack.push(new Node(input[i]));
        //     }
        //     if (input[i] == ')') {
        //         if (stack.isEmpty()){
        //             error = true;
        //         }
        //         else{
        //             stack.pop();
        //         }
        //     }
        //     i = i + 1;
        // }
        // if (!stack.isEmpty()){
        //     error = true;
        // }
        // *pos = i - 1 ;

        if(c == '>'){
            // eda::Node* ptr;
            word = word + c;

            cout << "tag " << word;
            for(int i = 0; i < 12; i++){
                if(word == palabras_reservadas[i]){
                    found = true;
                }
            }

            if(found){
                cout << " OK\n";
            }else{
                cout << " NOT OK\n";
            }
            word = "";
            continue;

            // ptr = new eda::Node(word, stack.top());
            // stack.push(ptr);
        }

        if(c == '<'){
            word = word + c;
            continue;
        }

        if(word != ""){
            word = word + c;
        }

        // if (texto.find("</") != std::string::npos) {
        //     if(texto.find(">") != std::string::npos){
        //         cout << "Linea " << pos << " OK (</>)\n";
        //     }else{
        //         cout << "Linea " << pos << " NOT OK (</)\n";
        //     }

        // }else if(texto.find("<") != std::string::npos){
        //     if(texto.find(">") != std::string::npos){
        //         cout << "Linea " << pos << " OK (<>)\n";
        //     }else{
        //         cout << "Linea " << pos << " NOT OK (<)\n";
        //     }
        // }
    }

    fclose(archivo);
    std::fclose(stdout);
    return 0;
}
