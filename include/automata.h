
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6 NFA2DFA
// Autor: Eduardo José Barrios García
// Correo: alu0101341019
// Fecha: semana del 15 al 19 de octubre

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "../include/state.h"
#include "../include/alphabet.h"
#include "../include/transition.h"
#include "../include/nfa.h"
#include "../include/dfa.h"
#include <map>
#include <queue>
#include <string>


/**
 * @brief Class: Automata:Computes the epsilon-closure of a set of states in an NFA.
 * @param nfa The NFA to compute the epsilon-closure from.
 * @param states The set of states to get the epsilon-closure of.
 * @return A set of states representing the epsilon-closure.
 */
std::set<int> epsilonClosure(const NFA& nfa, std::set<int>& states);
/**
 * @brief Computes the transition of a set of states in the NFA based on a given input symbol.
 * @param nfa The NFA to get the transition from.
 * @param states The set of states to compute the transition for.
 * @param symbol The input symbol.
 * @return A set of states representing the transition result.
 */

std::set<int> move(NFA& nfa, std::set<int>& states, char symbol);
/**
 * @brief Converts a given NFA to its equivalent DFA.
 * @param nfa The NFA to convert.
 * @return The equivalent DFA.
 */

DFA convertNFAToDFA(NFA& nfa);

/**
 * @brief Reads an NFA definition from a file.
 * @param filename The name/path of the file containing the NFA definition.
 * @return True if the NFA was read successfully, False otherwise.
 */
bool readnfa(std::string filename);

/**
 * @brief Saves the given DFA to a file.
 * @param filename The name/path of the file to save the DFA to.
 * @param dfa The DFA to save.
 */

void save_dfa_to_file(std::string filename, DFA& dfa);

#endif // ALGORITHM_H
