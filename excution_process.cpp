#include <iostream>
#include <ctime>
 
int main()
{
    std::time_t start = std::time(nullptr);
    register  double d = 1.0;
 
    // some time-consuming operation
    for (int p=0; p<100; ++p) {
        for (int q=0; q<100000; ++q) {
           d = d+p*d*q+d;
        }
    }
 
    std::cout << "Wall time passed: "
              << std::difftime(std::time(nullptr), start) << " s.\n";
}