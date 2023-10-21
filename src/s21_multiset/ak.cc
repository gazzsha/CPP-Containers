#include <iostream>
#include "s21_multiset.h"
#include <set>

int main() {
    auto f = []( auto& v) { 
        for  (auto it = v.begin(); it <= v.end(); ++it ) { 
            std::cout << *it << " ";
        }
        std::cout << "\n";
    };
//     s21::multiset<int> a {1, 1, 1,2,3,4,5};
//      auto it1 = a.equal_range(1);
//     //a.printTree();
//     std::cout << *it1.second << "\n";


//     for (auto it = it1.first; it <= it1.second; ++it) { 
//         std::cout << *it << " ";
//     }


//     std::multiset<int> b {1,2,3,4,5,5,5};
//         for (auto it  = --b.end(); it != --b.begin() ;it--) { 
//         std::cout << *it;
//     }
//     auto it2 = b.lower_bound(55);
//     std::cout << "\n";
//     std::cout << *it2;
//     std::cout << "==============\n";

//       std::initializer_list<int> items{10, 50, 30, 30, 60, 20, 23, 40};
//   s21::multiset<int> my_multiset(items);
//   std::multiset<int> std_multiset(items);

//  // auto my_iter = my_multiset.upper_bound(60);
//   auto std_iter = std_multiset.upper_bound(60);
//   std::cout  << *std_iter;

s21::multiset<int> a {1,2};
auto vec = a.insert_many(1,1,3,4,2);
f(a);
std::cout << *vec[4].first;
}