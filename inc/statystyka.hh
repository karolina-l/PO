#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH
#include <iostream>


struct Stat{
  int dobre; //pole na dobre odpowiedzi
  int zle;  //pole na zle odpowiedzi
  double procent;  //pole na procent dobrych odpowiedzi
};

void dodaj_dobra(Stat &stat);
void dodaj_zla(Stat &stat);
int zeruj (Stat &stat);
int ile_dobrych (Stat &stat);
int ile_w_sumie (Stat &stat);
double procent_dobrych (Stat &stat);
std::ostream &operator << (std::ostream &wys, Stat stat);


#endif
