#include "statystyka.hh"
#include <iostream>
#include <cstdlib>

//funkcja jest licznikiem dobrych odpowiedzi
void dodaj_dobra(Stat &stat)
{
  stat.dobre++;
}
//funkcja jest licznikiem zlych odpowiedzi
void dodaj_zla(Stat &stat)
{
stat.zle++;
}
//funkcja zeruje pola structa z pliku statystyka.hh
int zeruj (Stat &stat)
{
  stat.dobre=0;
  stat.zle=0;
  stat.procent=0;
}
//funkcja zwraca ilosc dobrych odpowiedzi
int ile_dobrych (Stat &stat)
{
  int ile;
  ile=stat.dobre;
  return ile;
}
//funkcja zwrca ilosc wszystkich odpowiedzi
int ile_w_sumie (Stat &stat)
{
  int ile_w;
  ile_w=stat.dobre+stat.zle;
  return ile_w;
}
//funkcja oblicza i zwraca procent poprawnych odpowiedzi
double procent_dobrych (Stat &stat)
{
  int razem=ile_w_sumie(stat);
  stat.procent=(double)stat.dobre/(double)razem;
  stat.procent*=100;
  return stat.procent;
}
//funkcja wypisuje statystyke testu
std::ostream &operator << (std::ostream &wys, Stat stat)
{
  wys<<std::endl;
  wys<<"Uzyskano "<<stat.dobre<<"/"<<ile_w_sumie(stat)<<std::endl;
  wys<<"Jest to: "<<stat.procent<<"% poprawnych odpowiedzi"<<std::endl;
}
