#include "s21_map.h"

int main() {
    s21::map<int, int> m;
    //s21::map<int, int> m_temp;
    m.insert(std::make_pair(12, 12));
    //std::initializer_list<std::make_pair(int , int)> ;
    m.insert(std::make_pair(14, 14));



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
    // s21::map<int, int> myMap = { {1, 1}, {2, 2}, {3, 3} };
    // m.insert_or_assign(std::string("12"), 30);

    //m.erase(it.current_node);

    //m.erase(it_q.current_node);
    //m.print_laef();
    //s21::map<int, int> m_temp = m;
    //m_temp.printTree();
    //m.print_laef();
    //s21::map<int, int>::iterator ittt = m.begin().current_node;
    //s21::map<int, int>::iterator itt_e = m.end().current_node;

    //++ittt;
     //++ittt;
     //++ittt;
     //++ittt;
    std::cout << "-----------------------------------" << '\n';
    
    m.printTree();
    // std::cout << "-----------------------------------" << '\n';
    // myMap.printTree();
     //std::cout << ittt.current_node->value << '\n';
     //std::cout << itt_e.current_node->value << '\n';
}
