#include <iostream>
#include <vector>

template<typename T>
struct vector
{
    void push_back(unsigned val)
    {
        m_vec.push_back(val);
    }

    void operator = (const vector<int>& v)
    {

    }

    std::vector<T> m_vec;

};

template<typename T>
std::ostream & operator << (std::ostream &o, const vector<T>& vec)
{
    for(const auto &it: vec.m_vec)
    {
        o << it << ", ";
    }
    return o;
}






using std::cout;
using std::endl;


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