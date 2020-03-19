#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


LZespolona  operator + (LZespolona  L1,  LZespolona  L2);
LZespolona  operator - (LZespolona  L1,  LZespolona  L2);
LZespolona  operator * (LZespolona  L1,  LZespolona  L2);
LZespolona  operator / (LZespolona  L1,  LZespolona  L2);
int  sprzezenie (LZespolona  L1);
LZespolona std::istream &operator >> (std ::istream &czyt, LZespolona &L1);
LZespolona std::ostream &operator << (std ::ostream &wys, LZespolona &L1);
LZespolona  utworz (double re, double im);
//bool wczytaj (LZespolona L1);
//void  wyswietl (LZespolona L1);


#endif
