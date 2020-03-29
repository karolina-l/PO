#include <iostream>
#include "BazaTestu.hh"
#include "statystyka.hh"
//#include "WyrazenieZesp.hh"

using std :: cout;

int main(int argc, char **argv)
{
  LZespolona odp, wyn;
  Stat stat;
  zeruj(stat);

  if (argc < 2) {
    cout << std::endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << std::endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." <<std:: endl;
    cout << std::endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    std::cerr << " Inicjalizacja testu nie powiodla sie." << std::endl;
    return 1;
  }



  cout << std::endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << std::endl;
  cout << std::endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
//////////////////////////////////////////////////////////////
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe))
  {
    cout<< std::endl << " Oblicz ";
    cout << WyrZ_PytanieTestowe << ":"<<std::endl;
    wyn=Oblicz(WyrZ_PytanieTestowe);
    int licznik_prob=0;

    while (licznik_prob<4)
    {
      std::cin>>odp;
      if(std::cin.fail())
      {
        licznik_prob++;
        std::cin.clear();
        std::cin.ignore(9999,'\n');
        std::cerr<<"Bledny zapis liczby zespolonej."<<std::endl;
      }
      else
      {
        break;
      }
    }

    if(odp==wyn)
    {
      dodaj_dobra(stat);
      cout<<"dobra odpowiedz! "<<std::endl;
    }
    else
    {
      dodaj_zla(stat);
      cout<< "zla odpowiedz :("<<std::endl;
    }
  }

  procent_dobrych(stat);
  cout << std::endl;
  cout << " Koniec testu" << std::endl;
  cout <<stat;
  cout << std::endl;

  return 0;
}
