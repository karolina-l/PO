#include <iostream>
#include "BazaTestu.hh"

using std :: cout;




int main(int argc, char **argv)
{

  /* if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }



  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " Czesc rzeczywista pierwszego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg1.re << endl;
  }


  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
  */


  //moje nowe
  /*
  LZespolona L1=utworz(2,3);
    wyswietl(L1);
  LZespolona L2=utworz(2,4);
  wyswietl(L2);
  LZespolona L8=utworz(2,-4);
  wyswietl (L8);
    LZespolona L3=L1+L2;
    wyswietl(L3);
    LZespolona L4=L1-L2;
    wyswietl(L4);
    LZespolona L5=L1*L8;
    wyswietl(L5);
     LZespolona L6=L1/L2;
     wyswietl(L6);
    int l7=sprzezenie(L2);
    cout<< l7; */
  //LZespolona l= wczytaj(l);
  //wyswietl(l);
  WyrazenieZesp w= wczytajWyr(w);
  WyswietlWyr(w);
}
