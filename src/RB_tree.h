#ifndef SRC_RB_TREE_H_
#define SRC_RB_TREE_H_
#include <iostream>
namespace s21 {

template <typename K, typename V>
class Node;

template <typename K, typename V>
class BaseNode {
public:
    BaseNode();
    Node<K,V>* left;
    Node<K,V>* right;
    Node<K,V>* parent;
    bool red;
private:

};

template <typename K, typename V>
class Node : public BaseNode<K,V> {
public:
    Node();
    Node(K key_, V value_, Node<K,V>* parent_);
    K key;
    V value;
private:

};
} // namespace s21  

#include "RB_tree.tpp"

#endif //SRC_RB_TREE_H_