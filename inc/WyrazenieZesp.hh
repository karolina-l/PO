#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH
#include <iostream>


#include "LZespolona.hh"



/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};



std::istream &operator >> (std ::istream &czyt, WyrazenieZesp &WZ);
std::ostream &operator << (std ::ostream &wys, WyrazenieZesp WZ);
LZespolona Oblicz(WyrazenieZesp  WZ);



#endif
