#ifndef SRC_RB_TREE_H_
#define SRC_RB_TREE_H_
#include <iostream>
namespace s21 {

template <typename K, typename V>
class Node{
public:
    Node();
    Node(K key_, V value_, Node<K, V>* parent_, Node<K, V>* leaf_tree);  // CONSTRUCTOR FOR NEW NODE
    Node(K key_, V value_, Node<K, V>* leaf_tree);                       // CONSTURCTOR FOR ROOT
    Node(K key_, V value_, Node<K, V>* parent_, bool red_);
    Node<K, V>* left;
    Node<K, V>* right;
    Node<K, V>* parent;
    bool red = true;
    K key;
    V value;
    //~Node();
private:
Node<K, V>* leaf_tree_;

};
} // namespace s21  

#include "RB_tree.tpp"

#endif //SRC_RB_TREE_H_