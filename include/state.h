
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6 NFA2DFA
// Autor: Eduardo José Barrios García
// Correo: alu0101341019
// Fecha: semana del 15 al 19 de octubre


#ifndef STATE_H
#define STATE_H

#include <set>

class State {
public:

    /**
     * @brief Adds a state with a specific value.
     * @param value The value of the state to be added.
     */

    void addState(int value);

 /**
     * @brief Checks if a state with a specific value exists.
     * @param value The value of the state to be checked.
     * @return True if the state exists, otherwise False.
     */

    bool hasState(int value);

     /**
     * @brief Gets all the states.
     * @return A set containing all the states.
     */

    std::set<int> getStates();

private:

    /**
     * @brief Data structure for storing states. 
     * 
     * It uses a set to ensure unique values and easy membership checking.
     */
    std::set<int> states;
};

#endif // STATE_H

