
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6 NFA2DFA
// Autor: Eduardo José Barrios García
// Correo: alu0101341019
// Fecha: semana del 15 al 19 de octubre


#include "../include/alphabet.h"

/**
 * @class Alphabets
 * @brief Class for handling alphabets.
 */

Alphabets::Alphabets() {
    // Constructor, if needed.
}

   /**
     * @brief Sets the alphabet based on the given string.
     * @param s Input string representation of the alphabet. 
     *          Characters are stored in the set and spaces are ignored.
     */


void Alphabets::set_value(const std::string& s) {
    input.clear();
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            input.insert(s[i]);
        }
    }
    t = s;
}


    /**
     * @brief Getter for the input alphabet set.
     * @return A reference to the set containing unique alphabet characters.
     */

const std::set<char>& Alphabets::getInput() const {
    return input;
}

 /**
     * @brief Getter for the string representation of the alphabet.
     * @return A reference to the string representing the alphabet.
     */


const std::string& Alphabets::getString() const {
    return t;
}

