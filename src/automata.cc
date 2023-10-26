
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
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <string>
#include "../include/automata.h"

/**
 * @brief Computes the epsilon closure of a set of states.
 * @param nfa The NFA for which the epsilon closure needs to be calculated.
 * @param states The set of states.
 * @return The epsilon closure of the set of states.
 */


std::set<int> epsilonClosure(const NFA& nfa, std::set<int>& states) {
    std::set<int> eclosure = states;
    std::queue<int> unprocessed;

    for (int state : states) {
        unprocessed.push(state);
    }

    while (!unprocessed.empty()) {
        int currentState = unprocessed.front();
        unprocessed.pop();

        std::map<char, std::set<int> > transitionsCopy = nfa.transitions.at(currentState);
        const std::map<char, std::set<int> >& transitions = transitionsCopy;
        if (transitions.find('\0') != transitions.end()) {
            const std::set<int>& epsilonTransitions = transitions.at('\0');
            for (int nextState : epsilonTransitions) {
                if (eclosure.insert(nextState).second) {
                    unprocessed.push(nextState);
                }
            }
        }
    }

    return eclosure;
}

/**
 * @brief Computes the set of states that the NFA moves to from a set of states on a given input symbol.
 * @param nfa The NFA.
 * @param states The set of states.
 * @param symbol The input symbol.
 * @return The set of states that the NFA transitions to on the given input.
 */

std::set<int> move(NFA& nfa, std::set<int>& states, char symbol) {
    std::set<int> result;
    
    for (int state : states) {
        const std::map<char, std::set<int> >& transitions = nfa.transitions[state];
        if (transitions.find(symbol) != transitions.end()) {
            const std::set<int>& symbolTransitions = transitions.at(symbol);
            result.insert(symbolTransitions.begin(), symbolTransitions.end());
        }
    }

    return result;
}

/**
 * @brief Converts a given NFA to its equivalent DFA.
 * @param nfa The NFA to convert.
 * @return The equivalent DFA.
 */

DFA convertNFAToDFA(NFA& nfa) {
    DFA dfa;
    dfa.numStates = 0;
    
    std::set<int> startStateClosure = epsilonClosure(nfa, nfa.startStates);
    dfa.startStates.insert(dfa.numStates);

for (int state : startStateClosure) {
    if (nfa.finalStates.find(state) != nfa.finalStates.end()) {
        dfa.finalStates.insert(dfa.numStates); // Cambia esta línea
        break;
    }
}

    
    std::map<std::set<int>, int> stateMap;
    stateMap[startStateClosure] = dfa.numStates++;
    
    std::queue<std::set<int> > unprocessed;
    unprocessed.push(startStateClosure);
    
    std::set<char> alphabet;
    
    for (int state = 0; state < nfa.numStates; ++state) {
        for (const auto& transition : nfa.transitions[state]) {
            if (transition.first != '\0') {
                alphabet.insert(transition.first);
            }
        }
    }
    
    while (!unprocessed.empty()) {
        std::set<int> currentState = unprocessed.front();
        unprocessed.pop();
        
        for (char symbol : alphabet) {
            std::set<int> nextState = move(nfa, currentState, symbol);
            std::set<int> nextStateClosure = epsilonClosure(nfa, nextState);
            
            if (!nextStateClosure.empty()) {
                if (stateMap.find(nextStateClosure) == stateMap.end()) {
                    stateMap[nextStateClosure] = dfa.numStates++;
                    unprocessed.push(nextStateClosure);
                }
              dfa.transitions[stateMap[currentState]][symbol] = stateMap[nextStateClosure];
   
                for (int state : nextStateClosure) {
                    if (nfa.finalStates.find(state) != nfa.finalStates.end()) {
                        dfa.finalStates.insert(stateMap[nextStateClosure]);
                        break;
                    }
                }
// Deberia comentarlo, pero esta ahi a modo de depuracion para verifiacar que todo se haya hecho bien
                std::cout << "\nDEPURACIÓN: \n";

                std::cout << "Processing state: " << stateMap[currentState] << " with symbol: " << symbol << std::endl;
                std::cout << "nextStateClosure: ";
                for (int state : nextStateClosure) {
                 std::cout << state << " ";
                    }
                std::cout << std::endl;
            if (dfa.finalStates.find(stateMap[nextStateClosure]) != dfa.finalStates.end()) {
            std::cout << "State " << stateMap[nextStateClosure] << " is an acceptance / final state in DFA." << std::endl;
                }

            }
        }
    }
    
    return dfa;
}


