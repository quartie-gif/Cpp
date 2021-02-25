// Nazwa pliku wykonywalnego: Complex

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klase ComplexNumber, ktora reprezentuje liczbe
// zespolona. Prosze, zaimplementowac tylko te funkcje i operatory,
// ktore sa wykorzystywane w ponizszym programie. Za kazdy
// zaimplementowany zbednych operator ocena bedzie obnizona o 0.5
// punktu.

// Porownujac dwie liczby zespolone prosze porownac ich moduly, czyli
// R = re*re + im*im.

// UWAGA!!!
// Po uruchomieniu linii ERROR, powinien pojawic sie blad kommpilacji
// dokladnie w tej linii. Brak bledu oznacza -2 punkty.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Complex. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy wgrac
// do UPEL: http://upel.agh.edu.pl/wfiis/course/view.php?id=20

#include"ComplexNumber.h"
#include<iostream>

//#define ERROR

int main ()
{
    using namespace std;

    const ComplexNumber first (1, 11);
    const ComplexNumber second (2, 22);

    cout<<first<<"\t"<<second<<"\n";

    ComplexNumber sum = first + second, product (1 + (ComplexNumber::i*2));
    cout<<"Sum: "<<sum<<"\tproduct: "<<product<<"\n";

    const ComplexNumber& productRef = product = sum = first*second;
    cout<<"Sum: "<<sum<<"\tproduct: "<<product<<"\tproductRef: "<<productRef<<"\n";

    product *= 3;
    cout<<"After product times 3\n";
    cout<<"Sum: "<<sum<<"\tproduct: "<<product<<"\tproductRef: "<<productRef<<"\n";

    ComplexNumber result (2 - ComplexNumber::i + first*second - (product++) + (++sum) );
    cout<<"Sum: "<<sum<<"\tproduct: "<<product<<"\tresult: "<<result<<"\n";

    result[(first > result) ? ComplexNumber::IMAGINARY : ComplexNumber::REAL] += 3;

    cout<<"After result real plus 3\n";
    cout<<"Sum: "<<sum<<"\tproduct: "<<product<<"\tresult: "<<result<<"\n";

    result[(result > first) ? ComplexNumber::IMAGINARY : ComplexNumber::REAL] += 3;
    cout<<"After result imaginary plus 3\n";
    cout<<"Sum: "<<sum<<"\tproduct: "<<product<<"\tresult: "<<result<<"\n";

#ifdef ERROR
    ComplexNumber::i = result;
#endif

    return 0;
}
/*
1 + 11i	2 + 22i
Sum: 3 + 33i	product: 1 + 2i
Sum: -240 + 44i	product: -240 + 44i	productRef: -240 + 44i
After product times 3
Sum: -240 + 44i	product: -720 + 132i	productRef: -720 + 132i
Sum: -241 + 44i	product: -721 + 132i	result: 241 + -45i
After result real plus 3
Sum: -241 + 44i	product: -721 + 132i	result: 244 + -45i
After result imaginary plus 3
Sum: -241 + 44i	product: -721 + 132i	result: 244 + -42i
*/
