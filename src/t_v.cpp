#include <iostream> 
#include "s21_vector.h"
#include <vector>
#include <algorithm>
int main() { 
    
    s21_vector<int> n(10); 
    s21_vector <int> v = n;
    std::vector<int> vv(10);


   std::cout << v.capacity();
   std::cout << v.at(5);
   v[9] = 10;  
    
    for (auto i = 0; i < v.size(); i++) { 
        std::cout << v[i] << " ";
    }

    std::cout << "\n";
    s21_vector<int>::iterator it = v.begin();
    *it = 2131;
    std::cout << *it; 
    s21_vector<std::string> ss;
   std::for_each(v.begin(), v.end(), [](const int n) { std::cout << n << ' '; });
   std::cout << "\n";
   std::cout << ss.empty();
    
    // int * p = v.data(); 
    // std::cout << *(p+9);
    // std::vector<int>::iterator it = vv.begin(); 
    // std::cout << *it;
    // s21_vector<int>::iterator it; 
    // std::cout << *it;



    // std::vector<int> b(55);
    // std::cout << b.at(100);

}