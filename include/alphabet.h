// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6 NFA2DFA
// Autor: Eduardo José Barrios García
// Correo: alu0101341019
// Fecha: semana del 15 al 19 de octubre


#ifndef ALPHABETS_H
#define ALPHABETS_H

#include <set>
#include <string>

class Alphabets {
public:
    Alphabets();
    void set_value(const std::string& s);
    const std::set<char>& getInput() const;
    const std::string& getString() const;

// set de chars
    std::set<char> input;
    std::string t;
};

Alphabets main_alphabets;
#endif // ALPHABETS_H




