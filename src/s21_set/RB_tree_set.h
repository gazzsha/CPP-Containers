#ifndef SRC_RB_TREE_SET_H_
#define SRC_RB_TREE_SET_H_
#include <iostream>
namespace s21 {

template <typename K>
class Node {
public:
    Node();
    Node(K key_, Node<K>* parent_, Node<K>* leaf_tree);  // CONSTRUCTOR FOR NEW NODE
    Node(K key_, Node<K>* leaf_tree);                       // CONSTURCTOR FOR ROOT
    Node(K key_, Node<K>* parent_, bool red_);
    Node<K>* left;
    Node<K>* right;
    Node<K>* parent;
    bool red = true;
    K key;
    ~Node();
private:

};
} // namespace s21  

#include "RB_tree_set.tpp"

#endif //SRC_RB_TREE_SET_H_