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

int  sprzezenie (LZespolona  L1)
{
  LZespolona czynnik;
  int wynik;
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

/* tworzenie liczby zespolonej*/
LZespolona utworz(double re, double im)
{
  LZespolona L1;
  L1.re = re;
  L1.im = im;
  return L1;
}

/*wyswietlanie liczby zespolonej*/
void wyswietl(LZespolona L1)
{
  std::cout<< "(" << L1.re << std::showpos << L1.im << std::noshowpos << "i)";
}
/*Wczytanie i utworzenie liczby zespolonej*/
LZespolona wczytaj(LZespolona L1)
{
  double re, im;
  char n1, n2, i;
  std ::cin>>n1>>re>>im>>i>>n2;
  L1=utworz(re, im);
  return L1;
}
