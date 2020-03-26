#include "WyrazenieZesp.hh"
#include <iostream>


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

/*{
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
}*/




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
  }

}

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

LZespolona Oblicz(WyrazenieZesp WZ)
{
  LZespolona L1;
  switch (WZ.Op) {
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
  }
}
