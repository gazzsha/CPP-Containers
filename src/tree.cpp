#include "s21_map.h"

int main() {
    s21::map<std::string, int> m;
    m.insert(std::make_pair(std::string("1"), 12));

    //m.insert
    m.insert(std::make_pair(std::string("11"), 14));



    m.insert(std::make_pair(std::string("111"), 13));

    m.insert(std::make_pair(std::string("11111"), 15));


    m.insert(std::make_pair(std::string("1111111"), 16));

    m.insert(std::make_pair(std::string("6"), 18));

    s21::map<std::string, int>::iterator it = m.insert(std::make_pair(std::string("7"), 20)).first;

    m.insert(std::make_pair(std::string("8"), 19));

    m.insert(std::make_pair(std::string("9"), 17));

    m.insert(std::make_pair(std::string("10"), 23));

    m.insert(std::make_pair(std::string("11"), 24));

    m.insert(std::make_pair(std::string("12"), 25));

    m.insert(std::make_pair(std::string("13"), 26));


    m.insert_or_assign(std::string("12"), 30);

    //m.erase(it.current_node);

    //m.erase(it_q.current_node);

    m.printTree();

}
