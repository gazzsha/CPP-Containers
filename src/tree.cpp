#include "s21_map.h"

int main() {
    s21::map<std::string, int> m;

    m.insert(std::make_pair(std::string("key"), 12));

    // std::cout << m.Node_tree_->key << '\n';
    // std::cout << m.Node_tree_->value << '\n';
    // std::cout << (m.Node_tree_->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';

    m.insert(std::make_pair(std::string("kaka"), 14));

    // std::cout << m.Node_tree_->right->key << '\n';
    // std::cout << m.Node_tree_->right->value << '\n';
    // std::cout << (m.Node_tree_->right->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';


    m.insert(std::make_pair(std::string("mds"), 13));

    m.insert(std::make_pair(std::string("masdfma"), 15));


    m.insert(std::make_pair(std::string("mafdsma"), 16));

     m.insert(std::make_pair(std::string("madma"), 18));

     m.insert(std::make_pair(std::string("maama"), 20));

     m.insert(std::make_pair(std::string("maama"), 19));
    // m.insert(std::make_pair(std::string("mama"), 7));

    // std::cout << m.Node_tree_->left->key << '\n';
    // std::cout << m.Node_tree_->left->value << '\n';
    // std::cout << (m.Node_tree_->left->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';

    // m.insert(std::make_pair(std::string("mama"), 8));

    // m.insert(std::make_pair(std::string("mama"), 9));

    // m.insert(std::make_pair(std::string("mama"), 7));
//    m.insert(std::make_pair(std::string("mama"), 10));

   // m.insert(std::make_pair(std::string("mama"), 23));

    // std::cout << m.Node_tree_->left->right->key << '\n';
    // std::cout << m.Node_tree_->left->right->value << '\n';
    // std::cout << (m.Node_tree_->left->right->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';

    // m.insert(std::make_pair(std::string("mama"), 8));

    // m.insert(std::make_pair(std::string("lala"), 25));

    // m.insert(std::make_pair(std::string("lala"), 26));

    // m.insert(std::make_pair(std::string("lala"), 7));
    // m.insert(std::make_pair(std::string("lala"), 6));

    // std::cout << m.Node_tree_->key << '\n';
    // std::cout << m.Node_tree_->value << '\n';
    // std::cout << (m.Node_tree_->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';

    // std::cout << m.Node_tree_->right->key << '\n';
    // std::cout << m.Node_tree_->right->value << '\n';
    // std::cout << (m.Node_tree_->right->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';

    // std::cout << m.Node_tree_->left->key << '\n';
    // std::cout << m.Node_tree_->left->value << '\n';
    // std::cout << (m.Node_tree_->left->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';

    // std::cout << m.Node_tree_->left->left->key << '\n';
    // std::cout << m.Node_tree_->left->left->value << '\n';
    // std::cout << (m.Node_tree_->left->left->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';

    // std::cout << m.Node_tree_->left->right->key << '\n';
    // std::cout << m.Node_tree_->left->right->value << '\n';
    // std::cout << (m.Node_tree_->left->right->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';

    // std::cout << m.Node_tree_->right->right->key << '\n';
    // std::cout << m.Node_tree_->right->right->value << '\n';
    // std::cout << (m.Node_tree_->right->right->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';

    // std::cout << m.Node_tree_->right->left->key << '\n';
    // std::cout << m.Node_tree_->right->left->value << '\n';
    // std::cout << (m.Node_tree_->right->left->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';

    // std::cout << m.Node_tree_->key << '\n';
    // std::cout << m.Node_tree_->value << '\n';
    // std::cout << (m.Node_tree_->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';

    // std::cout << m.Node_tree_->right->key << '\n';
    // std::cout << m.Node_tree_->right->value << '\n';
    // std::cout << (m.Node_tree_->right->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';

    // std::cout << m.Node_tree_->left->key << '\n';
    // std::cout << m.Node_tree_->left->value << '\n';
    // std::cout << (m.Node_tree_->left->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';

    // std::cout << m.Node_tree_->left->left->key << '\n';
    // std::cout << m.Node_tree_->left->left->value << '\n';
    // std::cout << (m.Node_tree_->left->left->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';

    // std::cout << m.Node_tree_->left->right->key << '\n';
    // std::cout << m.Node_tree_->left->right->value << '\n';
    // std::cout << (m.Node_tree_->left->right->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';

    // std::cout << m.Node_tree_->left->left->left->key << '\n';
    // std::cout << m.Node_tree_->left->left->left->value << '\n';
    // std::cout << (m.Node_tree_->left->left->left->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';

    // std::cout << m.Node_tree_->right->left->key << '\n';
    // std::cout << m.Node_tree_->right->left->value << '\n';
    // std::cout << (m.Node_tree_->right->left->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';


    
    std::cout << m.Node_tree_->key << '\n';
    std::cout << m.Node_tree_->value << '\n';
    std::cout << (m.Node_tree_->red ? "RED" : "BLACK") << '\n';
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


    std::cout << m.Node_tree_->right->key << '\n';
    std::cout << m.Node_tree_->right->value << '\n';
    std::cout << (m.Node_tree_->right->red ? "RED" : "BLACK") << '\n';
    std::cout << '\n';

    std::cout << m.Node_tree_->right->left->key << '\n';
    std::cout << m.Node_tree_->right->left->value << '\n';
    std::cout << (m.Node_tree_->right->left->red ? "RED" : "BLACK") << '\n';
    std::cout << '\n';


    std::cout << m.Node_tree_->right->right->key << '\n';
    std::cout << m.Node_tree_->right->right->value << '\n';
    std::cout << (m.Node_tree_->right->right->red ? "RED" : "BLACK") << '\n';
    std::cout << '\n';


    std::cout << m.Node_tree_->left->left->key << '\n';
    std::cout << m.Node_tree_->left->left->value << '\n';
    std::cout << (m.Node_tree_->left->left->red ? "RED" : "BLACK") << '\n';
    std::cout << '\n';


    // std::cout << m.Node_tree_->right->right->right->key << '\n';
    // std::cout << m.Node_tree_->right->right->right->value << '\n';
    // std::cout << (m.Node_tree_->right->right->right->red ? "RED" : "BLACK") << '\n';
    // std::cout << '\n';



}