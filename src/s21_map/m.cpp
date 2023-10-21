#include "s21_map.h"
#include <iostream>
#include <map>
int main() { 
    s21::map<int,int> a { {1,2}, {3,4} };
        auto f = []( auto& v) { 
        for  (auto it = v.begin(); it <= v.end(); ++it ) { 
            std::cout << it.get_key() << " " << it.get_value()  << '\n';
        }
        std::cout << "\n";
    };

            auto ff = []( auto& v) { 
        for  (auto it = v.begin(); it != v.end(); ++it ) { 
            std::cout << it->first << " " << it->second  << '\n';
        }
        std::cout << "\n";
    };


 s21::map<int, std::string> my_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};
  std::map<int, std::string> std_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};

  std::map<int, std::string> std_map2{
      std::make_pair(42, "foo"), std::make_pair(323, "basdar"),
      std::make_pair(343, "abobaaWD"), std::make_pair(-3, "ba")};

  std_map.merge(std_map2);
  my_map.insert_many(std::make_pair(42, "foo"), std::make_pair(323, "basdar"),
                 std::make_pair(343, "abobaaWD"), std::make_pair(-3, "ba"));

 auto my_iter = my_map.begin();
  auto std_iter = std_map.begin();

  while (my_iter <= my_map.end()) {
    std::cout << my_iter->first << " " << std_iter->first << '\n';
   std::cout << my_iter->second << " " << std_iter->second << '\n';
    ++my_iter;
    ++std_iter;
  }

//   f(my_map);
//   std::cout << "============\n";
//   ff(std_map);
    // int z = 1;
    // int y = 2;
    // auto ii = std::make_pair<int,int>(std::move(z),std::move(y));

}