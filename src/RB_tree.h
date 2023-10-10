#ifndef SRC_RB_TREE_H_
#define SRC_RB_TREE_H_
#include <iostream>
namespace s21 {

class BaseNode {
public:
    BaseNode();
    BaseNode* left;
    BaseNode* right;
    BaseNode* parent;
    bool red;
private:

};

template <typename K, typename V>
class Node : public BaseNode {
public:
    Node();
    Node(K key_, V value_, BaseNode* parent_);
    K key;
    V value;
private:

};
} // namespace s21

#include "RB_tree.tpp"

#endif //SRC_RB_TREE_H_