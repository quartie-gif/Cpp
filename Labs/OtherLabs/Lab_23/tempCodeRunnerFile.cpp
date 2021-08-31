	// cout << "Suma ocen: " << stud.getSum() << endl;
	// cout << "Srednia: " << averageScore(stud) << endl;
 	// auto result = stud.notIntScores(); // znajduje pierwszą niecałkowitą ocenę
	// cout << "Znaleziono ocene niecalkowita: " << *result << endl; //zadanie dodatkowe na później: znajdź wszystkie wystąpienia. zwracając je w postaci wektora
	// int neg = count_if(val.begin(), val.end(), badScores()); // badScores zlicza wszystkie oceny negatywne
    // cout << "Liczba ocen negatywnych: " << neg << endl; // 2.5 jest oceną negatywną
	// cout << "Liczba ocen pozytywnych: " << stud.countGoodScores() << endl << endl; // od 3.0 w górę

	// cout << "************  Baza danych  *************" << endl;
 	// Data tab;
	// tab += stud;
	// tab += Person("Student2", {3, 3, 2,3,2});
	// tab += Person("Student3", {3.5, 2, 2.5, 3, 3.5});

	// tab.fullprint();  //wykorzystać std::setw(n) z biblioteki iomanip (n=4)
	// cout << "Liczba ocen pozytywnych dla Student2: " << tab[1].countGoodScores() << endl;
	// // dodajemy na koniec nową ocenę dla Student2
	// tab[1].addScore(3.5);
	// cout << "Liczba ocen pozytywnych dla Student2: " << tab[1].countGoodScores() << endl;
	// cout << "Nowa srednia dla Student2: " << averageScore(tab[1]) << endl;

	// cout << "\n******* sortowanie po kolumnie 2 *******" << endl;
	// tab.sort(1).print(); 

	// cout << "******* sortowanie po kolumnie 3 *******" << endl;
	// tab.sort(2).print(); 
	// // usuwamy ocenę o wartości 2 (pierwsze znalezione wystąpienie)
	// tab[2].removeScore(2);
	// tab.sort(3); 		// uwaga, niekompletna kolumna, indeks spoza zakresu
	// // dodajemy na koniec nową ocenę, tab[2] to aktualnie Student2
	// tab[2].addScore(5);
	// cout << "Nowa srednia dla Student1: " << averageScore(tab[2]) << endl;
	// tab.sort(4); 		// uwaga, indeks spoza zakresu
	// cout << "\n********* sortowanie po sredniej *********" << endl;
	// // sortujemy po sredniej ocen, malejąco, greaterAverage to funkcja porównująca
    // tab.sortBy(greaterAverage).print();