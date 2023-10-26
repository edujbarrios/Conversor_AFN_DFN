// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6 NFA2DFA
// Autor: Eduardo José Barrios García
// Correo: alu0101341019
// Fecha: semana del 15 al 19 de octubre


#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <fstream>
#include <string>

#include "../src/alphabet.cc"
#include "../src/state.cc"
#include "../src/transition.cc"
#include "../src/dfa.cc"
#include "../src/nfa.cc"
#include "../src/automata.cc"

/**
 * @brief Prints the program's usage instructions.
 */


void printUsage() {
    std::cout << "Modo de empleo: ./NFA2DFA input.nfa output.dfa" << std::endl;
}

/**
 * @brief Checks if a file exists.
 * @param filename The name of the file to check.
 * @return True if the file exists, otherwise False.
 */

void printHelp() {
    std::cout << "Programa NFA2DFA para convertir un NFA especificado en un archivo a un DFA equivalente." << std::endl;
    std::cout << std::endl;
    std::cout << "Uso:" << std::endl;
    std::cout << "    ./NFA2DFA input.nfa output.dfa" << std::endl;
    std::cout << std::endl;
    std::cout << "Donde:" << std::endl;
    std::cout << "    input.nfa es el fichero conteniendo la descripción del NFA" << std::endl;
    std::cout << "    output.dfa es el fichero de especificación del DFA equivalente." << std::endl;
    std::cout << std::endl;
    std::cout << "Formato del archivo de especificación de autómatas:" << std::endl;
    std::cout << "    (Proporciona la descripción del formato aquí)" << std::endl;
    std::cout << std::endl;
    std::cout << "Para más ayuda, póngase en contacto con el desarrollador." << std::endl;
}

/**
 * @brief Checks if a file exists.
 * @param filename The name of the file to check.
 * @return True if the file exists, otherwise False.
 */

bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}


/**
 * @brief Entry point of the program.
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return Program exit status.
 */

int main(int argc, char *argv[]) {
    if (argc != 3) {
        if (argc == 2 && std::string(argv[1]) == "--help") {
            printHelp(); // Mostrar mensaje de ayuda si se proporciona la opción --help
            return 0;
        }
        std::cerr << "Número incorrecto de argumentos." << std::endl;
        printUsage(); // Mostrar el modo de empleo en caso de número incorrecto de argumentos
        return 1;
    }

    std::string ndfaDesc = argv[1]; // Archivo de descripción del NFA
    std::string output = argv[2];   // Archivo para guardar el DFA 

    if (!fileExists(ndfaDesc)) {
        std::cerr << "Error: el archivo " << ndfaDesc << " no existe." << std::endl;
        return 1;
    }

    readnfa(ndfaDesc);
    DFA dfa = convertNFAToDFA(main_nfa);
    save_dfa_to_file(output, dfa);

    return 0;
}


/**
 * @brief Reads an NFA from a file.
 * @param filename The name of the file containing the NFA.
 * @return True if the file was read successfully, otherwise False.
 */

int arr[100];

bool readnfa(std::string filename ){

   std::ifstream read(filename);

   if(! read ){
    std::cout << "NFA is not opened due to error or invalid name " << std::endl;
    return false;
   }

   std::string s;

   int  temp , acceptance , total_trans_states ;
   char input;
   int nextState;
   int total_states;

   getline(read  ,s);
   main_alphabets.set_value(s);  // Set alphabets
   
   read >> total_states;   // Read total states
  
   main_nfa.numStates = total_states;

   int acceptanceIndex = 0;
  
   int t;
   read >> t;
   main_nfa.startStates.insert(t);   // Read start states

   while(total_states){    // Read transition states    
         total_states--;

         read >> temp;    // Read current state
        
         read >> acceptance;   // Read final state

         if( acceptance == 1 )        // Check final stage
             main_nfa.finalStates.insert(temp);
            
         arr[acceptanceIndex] = acceptance;
         acceptanceIndex++;
               
         read >> total_trans_states;
  
         while(total_trans_states){
             total_trans_states--;

             read >> input;
             read >> nextState;
              
             if(input == '&')
                 input = '\0';
             main_nfa.transitions[temp][input].insert(nextState);
         }  
    } 

  return true;
}


/**
 * @brief Saves a DFA to a file.
 * @param filename The name of the file to save the DFA to.
 * @param dfa The DFA object to save.
 */

void save_dfa_to_file(std::string filename, DFA& dfa) {
    std::ofstream outputFile(filename);

    outputFile << main_alphabets.t << std::endl;
    outputFile << dfa.numStates  << std::endl;
    outputFile << *(dfa.startStates.begin()) << std::endl;
   
    int transitionCount = 0;
    bool isFinalState = false;

    for (int currentState = 0; currentState < dfa.numStates; ++currentState) {

        transitionCount = 0;
        isFinalState = false;

        for (const auto& currentTransition : dfa.transitions[currentState]) 
             transitionCount++;

        isFinalState = dfa.finalStates.find(currentState) != dfa.finalStates.end();
       
        outputFile << currentState << " " << (isFinalState ? 1 : 0) << " ";

        // si es un estado de aceptación y no tiene transiciones, añadir transición con todos los símbolos del alfabeto
        if (isFinalState && transitionCount == 0) {
            int symbolCount = 0;
            for (char symbol : main_alphabets.t) {
                if (symbol != ' ') {
                    symbolCount++;  // Aumentar el conteo si no es espacio
                }
            }
            outputFile << symbolCount << " ";  // Indicar el total de transiciones
            for (char symbol : main_alphabets.t) {
                if (symbol != ' ') {  // Evitar el espacio
                    outputFile << symbol << " " << currentState << " ";  // Transición para cada símbolo del alfabeto
                }
            }
        } else {
            outputFile << transitionCount << " ";
            for (const auto& currentTransition : dfa.transitions[currentState]) {
                char symbol = currentTransition.first;
                outputFile << symbol << " " << currentTransition.second << " ";
            }
        }
        outputFile << std::endl;
    }
       
    outputFile.close();
}
