#include <iostream>
#include "BazaTestu.hh"
//#include "WyrazenieZesp.hh"

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
  }//



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

 LZespolona L1;
 //std::cin >>L1;
int licznik = 0;
wczytajLZ(L1);

cout << L1;
  //WyrazenieZesp WZ1 = wczytaj(WZ1);
  //wyswietl(WZ1);


}
