#include "WyrazenieZesp.hh"
#include <iostream>


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

WyrazenieZesp wczytajWyr(WyrazenieZesp WZ)
{
  double re1, re2, im1, im2;
  char n11, n12, n21, n22, i1, i2,o;
//  Operator operat;
//!!!!! pobieraj dzialanie do kropki .
//zrob cos z o xdddd, napisz bledy, ale to chyba nie problem
//tylko dlugie to
  std::cin>>n11>>re1>>im1>>i1>>n12>>o>>n21>>re2>>im2>>i2>>n22;
  WZ.Arg1=utworz(re1, im1);
  WZ.Op=Op_Dodaj;
  WZ.Arg2=utworz(re2, im2);
  return WZ;
}

void WyswietlWyr(WyrazenieZesp WZ)
{
  LZespolona L1, L2;
  L1=WZ.Arg1;
  L2=WZ.Arg2;
  wyswietl(L1);
  //wyswietl operator
  wyswietl(L2);
}
