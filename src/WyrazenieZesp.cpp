#include "WyrazenieZesp.hh"
#include <iostream>

/*!
 * Realizuje operacje wczytania wyrazenia zespolonego
 * Argumenty:
 *    czyt - nazwa strumienia
 *    WZ - wyrazenie do wczytania.
 * Zwraca:
 *    wartosc strumienia
 */
std::istream &operator >> (std ::istream &czyt, WyrazenieZesp &WZ)
{
  LZespolona L1,L2;
  char znak;
  std::cin >> L1;
  std::cin >> znak;
  std::cin >> L2;
  WZ.Arg1=L1;
  WZ.Arg2=L2;
  if (znak=='+')
  {
    WZ.Op=Op_Dodaj;
    return czyt;
  }
  else if (znak=='-')
  {
    WZ.Op=Op_Odejmij;
    return czyt;
  }
  else if (znak=='*')
  {
    WZ.Op=Op_Mnoz;
    return czyt;
  }
  else if (znak=='/')
  {
    WZ.Op=Op_Dziel;
    return czyt;
  }
  else
  {
    std::cerr<<"Błędny znak."<<std::endl;
    exit(EXIT_FAILURE);
  }

}
/*!
 * Realizuje operacje wyswietlenia wyrazenia zespolonego
 * Argumenty:
 *    czyt - nazwa strumienia
 *    WZ - wyrazenie do wyswietlenia.
 * Zwraca:
 *    wartosc strumienia
 */
std::ostream &operator << (std ::ostream &wys, WyrazenieZesp WZ)
{
  LZespolona L1,L2;
  char znak;
  L1=WZ.Arg1;
  L2=WZ.Arg2;
  if(WZ.Op==Op_Dodaj)
  {
    znak='+';
    wys<<L1<<znak<<L2;
  }
  if(WZ.Op==Op_Odejmij)
  {
    znak='-';
    wys<<L1<<znak<<L2;
  }
  if(WZ.Op==Op_Mnoz)
  {
    znak='*';
    wys<<L1<<znak<<L2;
  }
  if(WZ.Op==Op_Dziel)
  {
    znak='/';
    wys<<L1<<znak<<L2;
  }
  return wys;
}
/*!
 * Realizuje operacje obliczania wartosci wyrazenia zespolonego
 * Argumenty:
 *    WZ - wyrazenie do obliczenia.
 * Zwraca:
 *    liczbe zespolona bedaca wynikiem dzialania
 */
LZespolona Oblicz(WyrazenieZesp WZ)
{
  LZespolona L1;
  switch (WZ.Op)
  {
    case Op_Dodaj:
      L1=WZ.Arg1+WZ.Arg2;
      return L1;
      break;

    case Op_Odejmij:
      L1=WZ.Arg1-WZ.Arg2;
      return L1;
      break;

    case Op_Mnoz:
      L1=WZ.Arg1*WZ.Arg2;
      return L1;
      break;

    case Op_Dziel:
      L1=WZ.Arg1/WZ.Arg2;
      return L1;
      break;
    default : exit(EXIT_FAILURE);
  }
}
