#include "LZespolona.hh"
#include <iostream>


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  L1,  LZespolona L2)
{
  LZespolona  Wynik;

  Wynik.re = L1.re + L2.re;
  Wynik.im = L1.im + L2.im;
  return Wynik;
}

LZespolona  operator - (LZespolona  L1,  LZespolona L2)
{
  LZespolona  Wynik;

  Wynik.re = L1.re - L2.re;
  Wynik.im = L1.im - L2.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  L1,  LZespolona  L2)
{
  LZespolona  wynik, czynnik;

  wynik.re = L1.re * L2.re;
  czynnik.re = (-1) * L1.im * L2.im;
  wynik.im = L1.im * L2.re;
  czynnik.im = L1.re * L2.im;
  wynik.re += czynnik.re;
  wynik.im += czynnik.im;
  return wynik;
}

double  sprzezenie (LZespolona  L1)
{
  LZespolona czynnik;
  double wynik;
  czynnik.re = L1.re;
  czynnik.im = (-1)*L1.im;
  wynik = (czynnik.re * L1.re) + (czynnik.im * L1.im);
  return wynik;
}

LZespolona  operator / (LZespolona  L1,  LZespolona  L2)
{
  LZespolona wynik, czynnik;
  int  sprz;
  sprz = sprzezenie(L2);
  czynnik.re = L2.re;
  czynnik.im = L2.im * (-1);
  wynik = L1 * czynnik;
  wynik.re = wynik.re/sprz;
  wynik.im = wynik.im/sprz;
  return wynik;
}
///////////////////////
 std::istream  &operator >> (std::istream & czyt, LZespolona &L1)
{
  char znak;
  czyt >> znak;
  if(znak!= '(')
  {
    czyt.setstate(std::ios::failbit);
    std::cerr<<"Błąd zapisu liczby zespolonej: nie ma (."<<std::endl;
  }
  czyt>>L1.re;
  czyt>>L1.im;
  czyt>>znak;
  if(znak!= 'i')
  {
    czyt.setstate(std::ios::failbit);
    std::cerr<<"Błąd zapisu liczby zespolonej: nie ma i."<<std::endl;
  }
  czyt>>znak;
  if(znak!= ')')
  {
    czyt.setstate(std::ios::failbit);
    std::cerr<<"Błąd zapisu liczby zespolonej: nie ma )."<<std::endl;
  }
  return czyt;
}

std::ostream  &operator << (std::ostream &wys, LZespolona L1)
{
    wys << "(" << L1.re  << std::showpos << L1.im  << std::noshowpos <<  "i)";
    return wys;
}

//////////////////////
/* tworzenie liczby zespolonej*/
LZespolona utworz(double re, double im)
{
  LZespolona L1;
  L1.re = re;
  L1.im = im;
  return L1;
}
