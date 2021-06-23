// wektor z metoda sortujaca wykorzystujaca zoptymalizowana funkcje swap
//
// Nalezy napisac prosty szablon  Vect (opakowanie na tablice). 
// Klasa poza operatorem [] ma miec tylko jeszcze jedna publiczna metode
// buble_sort (implementacja jest trywialna)
// for ( i = 0; i < N; i++ )
//    for (j = i+1; j < N; ++j ) 
//       if (porownanie(tablica[j], tablica[k]))
//          swap(tablica[j], tablica[k])
//
// Tu uogolnieniem powinnoa byc mozliwosc podania funkcji porownania (obie sa ponizej)
// Funkcja swap powinna istniec w dwoch wariantach: 
//   dla typow "pod" (Plain Old Data) powinna korzystac z memcpy (#include <string.h>)
//       memcpy(cel, zrodlo, ilosc_bajtow);  x 3
//   a dla skomplikowanych typow (nie "pod") nalezy uzyc obiektu tymczasowego 
//   i jego konstruktora kopiujacego z obiektem tymczasowym itp. 
// 
// Ponizej dwie klasy: ProstaKlasa, ktorej obiekty mozna kopiowac za pomoca memcpy
// i SkomplikowanaKlasa obiektow, ktorej nie mozna tak kopiowac.
//
// Kompilowac z -Wall -g do wykonywalnego "vtest".

#include <iostream>
#include "Vect.h"

class ProstaKlasa {
public:
  ProstaKlasa() : data(0) {}
  ProstaKlasa& operator=(int rhs) {
    data = rhs;
    return *this;
  }
  int data;

private:
  ProstaKlasa& operator=(const ProstaKlasa& rhs) {
    std::cout  << " Dzialania tego operatora nie chcemy widziec " << std::endl;
    data = rhs.data;
    return *this;
  }

};

template<> struct is_pod<ProstaKlasa> {
  const static bool value = true;
};

template<> struct is_pod<int> {
  const static bool value = true;
};

struct SkomplikowanaKlasa {

  SkomplikowanaKlasa() : data("") {}
  SkomplikowanaKlasa& operator=(const std::string& rhs) {
    data = rhs;
    return *this;
  }
  SkomplikowanaKlasa& operator=(const SkomplikowanaKlasa& rhs) {
    std::cout  << " Dzialane tego konstruktora musimy widziec " << std::endl;
    data = rhs.data;
    return *this;
  }
  std::string data;
};



struct tools {
  template<class T>
  static bool desc( const T& a, const T& b) {
    return a.data < b.data;
  }

  template<class T>
  static bool asc( const T& a, const T& b) {
    return a.data > b.data;
  }
};


int main() {
  using namespace std;
  Vect<ProstaKlasa> k(5);
  k[0] = 3;
  k[1] = 1;
  k[2] = 4;
  k[3] = 2;
  k[4] = 5;

  for (unsigned index = 0 ; index < k.size(); ++index ) {cout << k[index].data  << endl;}

  cout << "posortowane od max do min" << endl;
  k.buble_sort(tools::desc<ProstaKlasa>);
  for (unsigned index = 0 ; index < k.size(); ++index ) {cout << k[index].data  << endl;}

  cout << "posortowane od min do max" << endl;
  k.buble_sort(tools::asc<ProstaKlasa>);
  for (unsigned index = 0 ; index < k.size(); ++index ) {cout << k[index].data  << endl;}

  cout << "klasa skomplikowana" << endl;
  Vect<SkomplikowanaKlasa> l(4);
  l[0] = "3";
  l[1] = "A";
  l[2] = "4";
  l[3] = "5555";
  
  l.buble_sort(tools::desc<SkomplikowanaKlasa>);
  for (unsigned index = 0 ; index < l.size(); ++index ) {cout << l[index].data  << endl;}



}
/* wyniki
3
1
4
2
5
posortowane od max do min
5
4
3
2
1
posortowane od min do max
1
2
3
4
5
klasa skomplikowana
 Dzialane tego konstruktora musimy widziec 
 Dzialane tego konstruktora musimy widziec 
 Dzialane tego konstruktora musimy widziec 
 Dzialane tego konstruktora musimy widziec 
 Dzialane tego konstruktora musimy widziec 
 Dzialane tego konstruktora musimy widziec 
 Dzialane tego konstruktora musimy widziec 
 Dzialane tego konstruktora musimy widziec 
A
5555
4
3

 */