#include"include/adts/node.hpp"
#include"include/adts/queue.hpp"
#include"include/adts/stack.hpp"
#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>

using namespace std;

int main(int argc, char* argv[]){

    //FIGUE
    const char* rutamain = "/home/figue/Documents/Codigos/EDA/Tareas/tarea2/figuini_EDA_tarea_2/main.log"; 
    string rutatest = "/home/figue/Documents/Codigos/EDA/Tareas/tarea2/figuini_EDA_tarea_2/test.html";

    // //Stefano
    // const char* rutamain = "/home/stefano/dev/eda/figuini_EDA_tarea_2/main.log";
    // string rutatest = "/home/stefano/dev/eda/figuini_EDA_tarea_2/test.html";

    FILE* archivo = fopen(rutatest.c_str(), "r"); //hay que editar esto dependiendo el caso, pero en mi caso es asi.
    string texto;

    string palabras_reservadas[12] = {"<body>","</body>","<center>","</center>","<h1>","</h1>","<p>","</p>","<ol>","</ol>","<li>","</li>"};

    //este freopen sera para escribir en el main.log
    freopen(rutamain, "w", stdout); //hay que editar esto para que sea en tu caso
    
    
    if(archivo == nullptr){
        cout<<"no se pudo abrir"<<endl;
        exit(1);
    }

    char c;
    bool found = false;
    string word = "";
    eda::Stack stack;

    while(!feof(archivo)){
        c = getc(archivo);

        if(c == '>'){
            eda::Node* ptr;
            word = word + c;
            found = false;

            
            for(int i = 0; i < 12; i++){
                if(word == palabras_reservadas[i]){
                    found = true;
                    if((i % 2) == 0){
                        ptr = new eda::Node();
                        ptr->setData(word);
                        stack.push(ptr);
                    }
                    else{
                        if(stack.isEmpty()){
                            cout << " NOT OK\n";
                            break;
                        }
                        else{
                            ptr = stack.top();
                            string tmp = ptr->getData();
                            if(tmp == palabras_reservadas[i-1]){
                                cout << "tag " << tmp;
                                cout << " OK\n";
                                stack.pop();
                            }
                            else{
                                cout<< "tag " << tmp;
                                cout << " NOT OK\n";
                            }
                        }
                    }
                    break;
                }
            }

            if(!found){
                cout << " NOT OK\n";
            }
            word = "";
            continue;
        }

        if(c == '<'){
            word = word + c;
            continue;
        }

        if(word != ""){
            word = word + c;
        }
    }

    fclose(archivo);
    std::fclose(stdout);
    return 0;
}