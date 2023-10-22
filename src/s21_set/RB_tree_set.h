#ifndef CPP2_S21_CONTAINERS_SRC_S21_SET_RB_TREE_SET_H_
#define CPP2_S21_CONTAINERS_SRC_S21_SET_RB_TREE_SET_H_

namespace s21 {

template <typename K>
class Node {
 public:
  Node();
  Node(K key_, Node<K>* parent_,
       Node<K>* leaf_tree);          // CONSTRUCTOR FOR NEW NODE
  Node(K key_, Node<K>* leaf_tree);  // CONSTURCTOR FOR ROOT
  Node(K key_, Node<K>* parent_, bool red_);
  Node<K>* left;
  Node<K>* right;
  Node<K>* parent;
  bool red = true;
  K key;
  ~Node();
};
}  // namespace s21

#include "RB_tree_set.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_S21_SET_RB_TREE_SET_H_