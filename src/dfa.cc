
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6 NFA2DFA
// Autor: Eduardo José Barrios García
// Correo: alu0101341019
// Fecha: semana del 15 al 19 de octubre


#include "../include/dfa.h"

DFA::DFA() {
    // Constructor, if needed.
}

/**
 * @brief Set the number of states for the DFA.
 * @param num The number of states.
 */

void DFA::setNumStates(int num) {
    numStates = num;
}

/**
 * @brief Adds a transition for a specific state and input character.
 * @param state The current state.
 * @param input The input character.
 * @param nextState The next state after the transition.
 */

void DFA::addTransition(int state, char input, int nextState) {
    transitions[state][input] = nextState;
}

/**
 * @brief Checks if there's a transition for a specific state and input character.
 * @param state The current state.
 * @param input The input character.
 * @return True if the transition exists, otherwise False.
 */

bool DFA::hasTransition(int state, char input) {
    return transitions.find(state) != transitions.end() && transitions[state].find(input) != transitions[state].end();
}

/**
 * @brief Gets the next state for a specific state and input character.
 * @param state The current state.
 * @param input The input character.
 * @return The next state after the transition. Returns -1 if no transition exists for the given input.
 */

int DFA::getTransition(int state, char input) {
    if (hasTransition(state, input)) {
        return transitions[state][input];
    } else {
        return -1; // Return -1 to indicate no transition for this input.
    }
}

/**
 * @brief Marks a state as a starting state.
 * @param state The state to be marked as starting state.
 */

void DFA::addStartState(int state) {
    startStates.insert(state);
}

/**
 * @brief Checks if a state is a starting state.
 * @param state The state to be checked.
 * @return True if the state is a starting state, otherwise False.
 */

bool DFA::isStartState(int state) {
    return startStates.find(state) != startStates.end();
}

/**
 * @brief Marks a state as a final state.
 * @param state The state to be marked as final state.
 */

void DFA::addFinalState(int state) {
    finalStates.insert(state);
}

/**
 * @brief Checks if a state is a final state.
 * @param state The state to be checked.
 * @return True if the state is a final state, otherwise False.
 */

bool DFA::isFinalState(int state) {
    return finalStates.find(state) != finalStates.end();
}

