#include "s21_map.h"
#include <map>
//#include "s21_set.h"

int main() {
    s21::map<int, int> m;
    //s21::map<int, int> m_temp;
    m.insert(std::make_pair(12, 12));
    //std::initializer_list<std::make_pair(int , int)> ;
    m.insert(std::make_pair(14, 14));
    //m.insert(144, 144);

    s21::map<int, std::string> s21_map = {
      {1, "aboba"}, {2, "shleppa"}, {3, "amogus"}, {4, "abobus"}};
    std::map<int, std::string> std_map = {
      {1, "aboba"}, {2, "shleppa"}, {3, "amogus"}, {4, "abobus"}};
  //std::cout << s21_map.size() << "  "<< std_map.size() << '\n';
  //std::cout << s21_map.empty() << "   " << std_map.empty() << '\n';



    m.insert(std::make_pair(13, 13));

    s21::map<int, int>::iterator it_d_d = m.insert(std::make_pair(15, 15)).first;


    m.insert(std::make_pair(16, 16));

    m.insert(std::make_pair(18, 18));

    s21::map<int, int>::iterator it = m.insert(std::make_pair(20, 20)).first;

    m.insert(std::make_pair(19, 19));

    m.insert(std::make_pair(17, 17));

    m.insert(std::make_pair(23, 23));

    m.insert(std::make_pair(24, 24));

    m.insert(std::make_pair(25, 25));

    s21::map<int, int>::iterator it_d = m.insert(std::make_pair(26, 26)).first;
    //m.erase(it_d.current_node);
    //m.erase(it_d_d.current_node);
     s21::map<int, int> myMap = { {1, 1}, {2, 2}, {3, 3} };
    // m.insert_or_assign(std::string("12"), 30);

    //m.erase(it.current_node);

    //m.erase(it_q.current_node);
    //m.print_laef();
    s21::map<int, int> m_temp = m;
    //m_temp.printTree();
    //m.print_laef();
     s21::map<int, int>::iterator ittt = m.begin();
    // s21::map<int, int>::iterator itt_e = m.end().current_node;
    // for (auto it = m.begin(); it <= m.end(); ++it) {
    //     std::cout << it.current_node->key << '\n';
    // }
    //   ++ittt;
    //   ++ittt;
    //  ++ittt;
    //std::cout << m.size();

    // auto results = myMap.insert_many(
    //     std::make_pair(4, "One"),
    //     std::make_pair(5, "Two"),
    //     std::make_pair(6, "Three")
    // );

  s21::map<char, int> s21_map_1 = {{'b', 228}, {'c', 1337}};
  s21::map<char, int> s21_map_2 = {
      {'b', 228},
      {'c', 1337},
      {'d', 322},
      {'a', 5},
  };

  std::cout << s21_map_1.insert('d', 322).second;
  std::cout <<s21_map_1.insert('d', 14).second;

  std::pair<char, int> pair1('a', 5);
  std::pair<char, int> pair2('a', 28);

  std::cout << s21_map_1.insert(pair1).second;
  std::cout <<s21_map_1.insert(pair2).second;

  auto it1 = s21_map_1.begin();
  auto it2 = s21_map_2.begin();
 // while (it1 <= s21_map_1.end()) {
    std::cout << *it1;
    std::cout << *it2;
  //}



    //m.merge(myMap);
    //std::cout << m.contains(5);
    m.printTree();
    std::cout << "-----------------------------------" << '\n';
    
    m_temp.printTree();
    // std::cout << "-----------------------------------" << '\n';
     //myMap.printTree();
     //std::cout << ittt.current_node->value << '\n';
     //std::cout << itt_e.current_node->value << '\n';
}
