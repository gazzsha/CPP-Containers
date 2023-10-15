#include "s21_map.h"

int main() {
    s21::map<std::string, int> m;
    m.insert(std::make_pair(std::string("key"), 12));


    m.insert(std::make_pair(std::string("ka"), 14));



    m.insert(std::make_pair(std::string("msd"), 13));

    m.insert(std::make_pair(std::string("masa"), 15));


    m.insert(std::make_pair(std::string("maa"), 16));

    m.insert(std::make_pair(std::string("madaasdf"), 18));

    m.insert(std::make_pair(std::string("mdfasda"), 20));

    m.insert(std::make_pair(std::string("maama"), 19));

    m.insert(std::make_pair(std::string("maaasd"), 17));

    m.insert(std::make_pair(std::string("maa"), 23));

    m.insert(std::make_pair(std::string("masasdsma"), 24));

    s21::map<std::string, int>::iterator it = m.insert(std::make_pair(std::string("mfsma"), 25)).first;

    m.insert(std::make_pair(std::string("maama"), 26));

    m.erase(it);

    m.printTree();

}
