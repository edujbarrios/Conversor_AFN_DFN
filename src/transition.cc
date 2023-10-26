
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6 NFA2DFA
// Autor: Eduardo José Barrios García
// Correo: alu0101341019
// Fecha: semana del 15 al 19 de octubre

#include "../include/transition.h"

/**
 * @brief Adds a transition from a given state with a given input to a next state.
 * @param state The current state.
 * @param input The input symbol.
 * @param nextState The state to transition to.
 */

void Transition::addTransition(int state, char input, int nextState) {
    transitions[state][input].insert(nextState);
}


/**
 * @brief Checks if a transition exists for a given state and input.
 * @param state The current state.
 * @param input The input symbol.
 * @return True if a transition exists, false otherwise.
 */

bool Transition::hasTransition(int state, char input) {
    return transitions.find(state) != transitions.end() && transitions[state].find(input) != transitions[state].end();
}


/**
 * @brief Retrieves the transition set for a given state and input.
 * @param state The current state.
 * @param input The input symbol.
 * @return A set of next states if the transition exists; an empty set otherwise.
 */

std::set<int> Transition::getTransition(int state, char input) {
    if (hasTransition(state, input)) {
        return transitions[state][input];
    } else {
        return std::set<int>();
    }
}

