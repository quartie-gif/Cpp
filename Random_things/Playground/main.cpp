#include<iostream>
#include<vector>
#include<chrono>


int main(int argc, char const *argv[])
{
    std::cout << std::endl;
    std::vector<int> Vec;

    Vec.reserve(1000);


    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 300; i++)
    {
        Vec.push_back(i);
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = duration_cast< std::chrono::microseconds>(stop - start);
    std::cout << "Time:\t" << static_cast<double>(duration.count())/1000.0 << " seconds " << std::endl;

    std::cout << "Vec.capacity(): " << Vec.capacity() <<  std::endl;
    std::cout << "Vec.size(): " << Vec.size() <<  std::endl;
    
    Vec.shrink_to_fit();
    
    std::cout << "(After shrink_to_fit)Vec.capacity(): " << Vec.capacity() <<  std::endl; 
    std::cout << "Vec.size(): " << Vec.size() <<  std::endl;
    std::cout << std::endl;

    

    return 0;
}
