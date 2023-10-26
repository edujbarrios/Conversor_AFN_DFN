// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6 NFA2DFA
// Autor: Eduardo José Barrios García
// Correo: alu0101341019
// Fecha: semana del 15 al 19 de octubre

/**
 * @class NFA
 * @brief Class representing a Non-deterministic Finite Automaton.
 */

#ifndef DFA_H
#define DFA_H

#include <map>
#include <set>
#include "transition.h"
#include "state.h"

class DFA {
public:
    DFA();

    void setNumStates(int num);

    void addTransition(int state, char input, int nextState);

    bool hasTransition(int state, char input);

    int getTransition(int state, char input);

    void addStartState(int state);

    bool isStartState(int state);

    void addFinalState(int state);

        /**
     * @brief Checks if a state is a final/acceptance state.
     * @param state The state to check.
     * @return True if the state is a final state, otherwise False.
     */
    bool isFinalState(int state);

    int numStates;
    std::map<int, std::map<char, int> > transitions; ///< Total number of states in the NFA
    std::set<int> startStates; // Set of start states
    std::set<int> finalStates; // Set of accepted states
    Transition m_transitions; // Transition object
    State t_startStates; // State ovject
    State t_finalStates; // State object
};

#endif // DFA_H

