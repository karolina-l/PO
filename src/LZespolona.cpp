#include "LZespolona.hh"
#include <iostream>
#include <cstdlib>


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwszy skladnik dodawania,
 *    L2 - drugi skladnik dodawania.
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

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwszy skladnik odejmowania,
 *    L2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  L1,  LZespolona L2)
{
  LZespolona  Wynik;

  Wynik.re = L1.re - L2.re;
  Wynik.im = L1.im - L2.im;
  return Wynik;
}

/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwszy skladnik mnozenia,
 *    L2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
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
  double wynik;
  wynik = (L1.re * L1.re) + (L1.im * L1.im);
  return wynik;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwszy skladnik dzielenia,
 *    L2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  L1,  LZespolona  L2)
{
  LZespolona wynik, czynnik;
  double  sprz;
  sprz = sprzezenie(L2);
  if(sprz==0)
  {
    std::cerr<<"nie można dzielić przez 0";
    exit(EXIT_FAILURE);
  }
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
  char znak1, znak2, znak3;
  double a,b;
  int proba=0;
while(proba<4)
  {
      czyt >> znak1;
      if(znak1!= '(')
  {
    czyt.setstate(std::ios::failbit);
    std::cerr<<"Błąd zapisu liczby zespolonej: nie ma (."<<std::endl;
    std::cin.clear(); std::cin.sync();
    proba++;
    break;
  }

  czyt>>a;
  czyt>>b;
  czyt>>znak2;
  if(znak2!= 'i')
  {
    czyt.setstate(std::ios::failbit);
    std::cerr<<"Błąd zapisu liczby zespolonej: nie ma i."<<std::endl;
    std::cin.clear(); std::cin.sync();
    proba++;
    break;
  }

  czyt>>znak3;
  if(znak3!= ')')
  {
    czyt.setstate(std::ios::failbit);
    std::cerr<<"Błąd zapisu liczby zespolonej: nie ma )."<<std::endl;
    std::cin.clear(); std::cin.sync();
    proba++;
    break;
  }
  else
  {
    L1=utworz(a,b);
    return czyt;
  }

}
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
