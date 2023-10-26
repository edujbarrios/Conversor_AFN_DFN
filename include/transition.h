
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6 NFA2DFA
// Autor: Eduardo José Barrios García
// Correo: alu0101341019
// Fecha: semana del 15 al 19 de octubre


#ifndef TRANSITION_H
#define TRANSITION_H

#include <map>
#include <set>

/**
 * @class Transition
 * @brief Class representing transitions in automata.
 */

class Transition {
public:

    /**
     * @brief Checks if there's a transition for a specific state and input character.
     * @param state The current state.
     * @param input The input character.
     * @return True if the transition exists, otherwise False.
     */

    void addTransition(int state, char input, int nextState);

  /**
     * @brief Gets the set of possible next states for a specific state and input character.
     * @param state The current state.
     * @param input The input character.
     * @return A set containing all possible next states after the transition for the given input.
     */

    bool hasTransition(int state, char input);

      /**
     * @brief Gets the set of possible next states for a specific state and input character.
     * @param state The current state.
     * @param input The input character.
     * @return A set containing all possible next states after the transition for the given input.
     */
    std::set<int> getTransition(int state, char input);

private:
    std::map<int, std::map<char, std::set<int> > > transitions;
};

#endif // TRANSITION_H

