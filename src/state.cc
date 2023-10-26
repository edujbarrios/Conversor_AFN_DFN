
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6 NFA2DFA
// Autor: Eduardo José Barrios García
// Correo: alu0101341019
// Fecha: semana del 15 al 19 de octubre


#include "../include/state.h"

/**
 * @brief Adds a transition from a given state with a given input to a next state.
 * @param state The current state.
 * @param input The input symbol.
 * @param nextState The state to transition to.
 */

void State::addState(int value) {
    states.insert(value);
}


/**
 * @brief Checks if a state with the given value exists in the set of states.
 * @param value The value of the state to be checked.
 * @return True if the state exists, false otherwise.
 */

bool State::hasState(int value) {
    return states.find(value) != states.end();
}


/**
 * @brief Retrieves the set of all states.
 * @return A set containing all states.
 */

std::set<int> State::getStates() {
    return states;
}

