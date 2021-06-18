// uzupełnij
#include <iostream>
#include <vector>

using namespace std;

int main()
{
vector<int> veci;
vector<double> vecd;
for(int i = 0;i<10;++i){

veci.push_back(i);
vecd.push_back(i);
}
vecd = veci;
cout << veci << endl << vecd << endl;
}