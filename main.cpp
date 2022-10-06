#include"include/adts/node.hpp"
#include"include/adts/queue.hpp"
#include"include/adts/stack.hpp"
#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>

using namespace std;


// bool validateParenthesis(const std::string &input, int* pos){
// 	bool error = false;
// 	int i = 0;
// 	Stack stack;
// 	while (!error && i < input.length()){
// 		if (input[i] == '(') {
// 			stack.push(new Node(input[i]));
// 		}
// 		if (input[i] == ')') {
// 			if (stack.isEmpty()){
// 				error = true;
// 			}
// 			else{
// 				stack.pop();
// 			}
// 		}
// 		i = i + 1;
// 	}
// 	if (!stack.isEmpty()){
// 		error = true;
// 	}
// 	*pos = i - 1 ;
// 	return !error;
// }


// int main(int nargs, char** vargs){
// 	std::string input;
// 	int pos=0;
// 	std::cout<<"Ingresa expresión: ";
// 	std::getline(std::cin, input);
// 	bool status = validateParenthesis(input, &pos);
// 	if (status){
// 		std::cout<< " Expresión Correcta " << std::endl;
// 	}
// 	else{
// 		std::cout<< " Expresión Inválida" << std::endl;
// 		std::cout<< "Pos error:  " << pos	<< std::endl;
// 	}

// 	return 0;
// }

// if (texto.find(palabras_reservadas[0]) != std::string::npos) {}



int main(int argc, char* argv[]){
    ifstream archivo("/home/figue/Documents/Codigos/EDA/Tareas/tarea2/figuini_EDA_tarea_2/test.html"); //hay que editar esto dependiendo el caso, pero en mi caso es asi.
    string texto;

    string palabras_reservadas[12] = {"<body>","</body>","<center>","</center>","<h1>","</h1>","<p>","</p>","<ol>","</ol>","<li>","</li>"};

    //este freopen sera para escribir en el main.log
    freopen("/home/figue/Documents/Codigos/EDA/Tareas/tarea2/figuini_EDA_tarea_2/main.log", "w", stdout); //hay que editar esto para que sea en tu caso
    
    
    if(archivo.fail()){
        cout<<"no se pudo abrir"<<endl;
        exit(1);
    }

    int pos = 0;
    int i = 0;
    bool error = false;
    eda::Stack stack;

    while(!archivo.eof()){
        getline(archivo,texto);
        cout<<texto<<endl;
        if (texto.find(palabras_reservadas[0]) != std::string::npos) {
            cout<<"se reconocio la palabra"<<endl;
        }
    }

    archivo.close();
    std::fclose(stdout);
    // printf("me caes bien");
    return 0;
}
