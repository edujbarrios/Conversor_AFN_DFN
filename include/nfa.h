
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6 NFA2DFA
// Autor: Eduardo José Barrios García
// Correo: alu0101341019
// Fecha: semana del 15 al 19 de octubre


#ifndef NFA_H
#define NFA_H

#include <map>
#include <set>
#include "transition.h"
#include "state.h"

class NFA {
public:
    NFA();
    void setNumStates(int num);
    void addTransition(int state, char input, int nextState);
    bool hasTransition(int state, char input);
    std::set<int> getTransition(int state, char input);
    void addStartState(int state);
    bool isStartState(int state);
    void addFinalState(int state);
    bool isFinalState(int state);

    int numStates;
    std::map<int, std::map<char, std::set<int> > > transitions;
    std::set<int> startStates;
    std::set<int> finalStates;
    Transition m_transitions;
    State t_startStates;
    State t_finalStates;
};

NFA main_nfa;
#endif // NFA_H

 
