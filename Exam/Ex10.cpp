// 1. Co to jest const + przykładowe fragmenty kodu.

/* 
*	const jest to type qualifier, do specyfikacji niemodyfikowalności
*	obiektu, bądź metody
*/

// 2. Co to jest klasa abstrakcyjna, z jakim pojęciem jest ściśle związana, do czego służy?

/* 
*	Klasa abstrakcyjna jest to klasa, w której jest zdefiniowana lub
*	odziedziczona zoverridowana co najmniej jedna metoda czysto wirtualna
*/

// 3. Uzupełnij i uzasadnij. Coś z przeładowaniem operatora << i vectorem. Nie pamiętam kodu.


// 4. Co to jest static + przykładowe fragmenty kodu.

/* 
*	https://www.geeksforgeeks.org/static-keyword-cpp/
*/

// 5. Co to jest dziedziczenie i jakie są jego rodzaje, przykład.

/* 
*	Dziedziczenie umożliwia tworzenie hierarchii klas. Hierarchie klas
*	pozwalają tworzyć hierarchie pojęć, wyrażając w ten sposób zależności
*	między pojęciami.
*/




#include <iostream>

class  Baza1 									{ public: ~Baza1() {std::cout << "Baza1 " ;}};
class  Baza2 									{ public: ~Baza2() {std::cout << "Baza2 " ;}};
class  Baza3 									{ public: ~Baza3() {std::cout << "Baza3 " ;}};
class X: public Baza1, public Baza2 			{ public: ~X() {std::cout << "X " ;}};
class Y: private Baza3, public X, public Baza1 	{ public: ~Y() {std::cout << "Y " ;}};


int main()
{
	Y a;
	return 0;
}

// Solution: Y -> Baza1 -> X -> Baza2 -> Baza1 -> Baza3
