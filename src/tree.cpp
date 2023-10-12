#include "s21_map.h"

int main() {
    s21::map<std::string, int> m;
    m.insert(std::make_pair(std::string("key"), 12));

    // std::cout << m.Node_tree_->key << '\n';
    // std::cout << m.Node_tree_->value << '\n';
    // std::cout << (m.Node_tree_->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';

    m.insert(std::make_pair(std::string("kaka"), 24));

    // std::cout << m.Node_tree_->right->key << '\n';
    // std::cout << m.Node_tree_->right->value << '\n';
    // std::cout << (m.Node_tree_->right->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';


    m.insert(std::make_pair(std::string("mama"), 10));

    // std::cout << m.Node_tree_->left->key << '\n';
    // std::cout << m.Node_tree_->left->value << '\n';
    // std::cout << (m.Node_tree_->left->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';

    m.insert(std::make_pair(std::string("mama"), 9));

    // std::cout << m.Node_tree_->left->right->key << '\n';
    // std::cout << m.Node_tree_->left->right->value << '\n';
    // std::cout << (m.Node_tree_->left->right->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';

    m.insert(std::make_pair(std::string("mama"), 8));

    m.insert(std::make_pair(std::string("lala"), 20));

    std::cout << m.Node_tree_->key << '\n';
    std::cout << m.Node_tree_->value << '\n';
    std::cout << (m.Node_tree_->red ? "RED" : "BLACK") << '\n';
    std::cout << '\n';

    std::cout << m.Node_tree_->right->key << '\n';
    std::cout << m.Node_tree_->right->value << '\n';
    std::cout << (m.Node_tree_->right->red ? "RED" : "BLACK") << '\n';
    std::cout << '\n';

    std::cout << m.Node_tree_->left->key << '\n';
    std::cout << m.Node_tree_->left->value << '\n';
    std::cout << (m.Node_tree_->left->red ? "RED" : "BLACK") << '\n';
    std::cout << '\n';

    std::cout << m.Node_tree_->left->left->key << '\n';
    std::cout << m.Node_tree_->left->left->value << '\n';
    std::cout << (m.Node_tree_->left->left->red ? "RED" : "BLACK") << '\n';
    std::cout << '\n';

    std::cout << m.Node_tree_->left->right->key << '\n';
    std::cout << m.Node_tree_->left->right->value << '\n';
    std::cout << (m.Node_tree_->left->right->red ? "RED" : "BLACK") << '\n';
    std::cout << '\n';

    std::cout << m.Node_tree_->right->left->key << '\n';
    std::cout << m.Node_tree_->right->left->value << '\n';
    std::cout << (m.Node_tree_->right->left->red ? "RED" : "BLACK") << '\n';
    std::cout << '\n';

}