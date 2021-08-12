/* 
   Celem zadania jest napisanie pomocniczej klasy DoUndo, ktora pozwala 
   na odwolanie operacji.

   Jak to jest robione powinno byc ewidentne po przeczytaniu zawartosci klasy Msg.

   UWAGA: Prosze zauwazyc ze w trFail ostania funkcja statyczna
   DoUndo::allok() nie jest wywolywana, jest to f. statyczna!  

   UWAGA: KeepInt musi przechowac zarowno wartosc poczatkow jak i
   referencje do miejsca gdzie mozna odlozyc te wartosc jesli undo jest wolane.   
 */
#include <iostream>
#include <stdexcept>
#include "DoUndo.h"


class Msg : public DoUndoAction {
  void dodo() {
    std::cout << "Entering transaction" << std::endl;
  }    
  void undoOk() {
    std::cout << "Finished transaction" << std::endl;
  }
  void undoFail() {
    std::cout << "Broken transaction" << std::endl;
  }
  
};

int konto1 = 100;
int konto2 = 20;

void trOK() {
  DoUndo msg(new Msg());
  const int wartoscPrzelewu = 11;
  DoUndo k1(new KeepInt(konto1)); // trick w tym zadaniu jest tutaj, musimy przechowac referencje do int: konto1 aby, moc potencjalnie zmienic jego wartosc gdy transakcja si enie powiedzie
  DoUndo k2(new KeepInt(konto2));
  konto1 -= wartoscPrzelewu;
  konto2 += wartoscPrzelewu;
  DoUndo::allok();
}


void trFail() {
  DoUndo msg(new Msg());
  const int wartoscPrzelewu = 14;
  DoUndo k1(new KeepInt(konto1));
  DoUndo k2(new KeepInt(konto2));
  konto1 -= wartoscPrzelewu;
  throw std::runtime_error("Tranzakcja przerwana z nieznanej przyczyny");
  konto2 += wartoscPrzelewu;  
  DoUndo::allok();
}


int main() {
  try {
    trOK();
    std::cout  << "konto1 " << konto1 << " konto2 " << konto2 << std::endl;
    trFail();
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    std::cout  << "konto1 " << konto1 << " konto2 " << konto2 << std::endl;
  }
  
}
/* wynik
Entering transaction
Finished transaction
konto1 89 konto2 31
Entering transaction
Broken transaction
Tranzakcja przerwana z nieznanej przyczyny
konto1 89 konto2 31
 */
