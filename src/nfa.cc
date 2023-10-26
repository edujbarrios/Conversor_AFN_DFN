// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6 NFA2DFA
// Autor: Eduardo José Barrios García
// Correo: alu0101341019
// Fecha: semana del 15 al 19 de octubre


#include "../include/nfa.h"

NFA::NFA() {
    // Constructor, if needed.
}



/**
 * @brief Sets the number of states in the NFA.
 * @param num The total number of states.
 */
void NFA::setNumStates(int num) {
    numStates = num;
}

/**
 * @brief Adds a transition for a given state and input to the NFA.
 * @param state The current state.
 * @param input The input character for the transition.
 * @param nextState The next state after the transition.
 */

void NFA::addTransition(int state, char input, int nextState) {
    transitions[state][input].insert(nextState);
}


/**
 * @brief Checks if there's a transition for a given state and input.
 * @param state The current state.
 * @param input The input character for the transition.
 * @return True if the transition exists, false otherwise.
 */

bool NFA::hasTransition(int state, char input) {
    return transitions.find(state) != transitions.end() && transitions[state].find(input) != transitions[state].end();
}

/**
 * @brief Retrieves the transition set for a given state and input.
 * @param state The current state.
 * @param input The input character for the transition.
 * @return A set containing the next states for the transition. If no transition is found, an empty set is returned.
 */

std::set<int> NFA::getTransition(int state, char input) {
    if (hasTransition(state, input)) {
        return transitions[state][input];
    } else {
        return std::set<int>();
    }
}


/**
 * @brief Adds a state as a starting state for the NFA.
 * @param state The state to be added as a starting state.
 */

void NFA::addStartState(int state) {
    startStates.insert(state);
}


/**
 * @brief Checks if a given state is a starting state for the NFA.
 * @param state The state to be checked.
 * @return True if the state is a starting state, false otherwise.
 */

bool NFA::isStartState(int state) {
    return startStates.find(state) != startStates.end();
}


/**
 * @brief Adds a state as a final state for the NFA.
 * @param state The state to be added as a final state.
 */

void NFA::addFinalState(int state) {
    finalStates.insert(state);
}


/**
 * @brief Checks if a given state is a final state for the NFA.
 * @param state The state to be checked.
 * @return True if the state is a final state, false otherwise.
 */

bool NFA::isFinalState(int state) {
    return finalStates.find(state) != finalStates.end();
}
