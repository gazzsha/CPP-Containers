#include "s21_map.h"

int main() {
    s21::map<std::string, int> m;
    m.insert(std::make_pair(std::string("key"), 12));
    std::cout << m.Node_tree_.key << '\n';
    std::cout << m.Node_tree_.value << '\n';
    // m.insert(std::make_pair(std::string("key"), 12), m.Node_tree_);
    // std::cout << m.Node_tree_.key << '\n';
    // std::cout << m.Node_tree_.value << '\n';
}