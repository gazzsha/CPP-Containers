#ifndef CPP2_S21_CONTAINERS_SRC_S21_SET_S21_SET_H_
#define CPP2_S21_CONTAINERS_SRC_S21_SET_S21_SET_H_
#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "../s21_vector.h"
#include "RB_tree_set.h"
#include "iterators_set.h"

namespace s21 {
template <typename K, typename Comp = std::less<K>>
class set {
 public:
  using key_type = K;
  using value_type = K;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = Iterator<K, Comp>;
  using const_iterator = ConstIterator<K, Comp>;
  using size_type = size_t;

  set();  // default constructor

  set(std::initializer_list<value_type> const& items);
  set(const set& m);
  set(set&& m);
  set& operator=(set&& m);
  // Destructor
  ~set();

  // pub methods
  iterator begin() {
    if (!Node_tree_) throw std::out_of_range("nope");
    Node<K>* temp = Node_tree_;
    while (temp->left->left != nullptr) {
      temp = temp->left;
    }
    return iterator(temp);
  }
  iterator end() {
    if (!Node_tree_) throw std::out_of_range("nope");
    Node<K>* temp = Node_tree_;
    while (temp->right->right != nullptr) {
      temp = temp->right;
    }
    return iterator(temp);
  }

  void clear() noexcept;
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;
  virtual std::pair<iterator, bool> insert(const value_type& value);
  void erase(iterator pos) noexcept;
  void printTree() noexcept;
  void swap(set& other) noexcept;
  void merge(set& other) noexcept;
  bool contains(const K& key);
  iterator find(const K& key);

  template <class... Args>
  vector<std::pair<iterator, bool>> insert_many(Args&&... args);

 protected:
  Node<K>* Node_tree_;
  static Node<K>* leaf_tree;  // nil leaf
  static Node<K> leaf;
  Node<K>* begin_node;
  Node<K>* end_node;
  size_t size_set = 0;

  virtual std::pair<iterator, bool> insert(const value_type& value,
                                           Node<K>* current_node, int assign);
  void insertBalanceTree(Node<K>* newNode) noexcept;
  void smallPivot(Node<K>* node) noexcept;
  void bigPivot(Node<K>* node) noexcept;
  void printTree(Node<K>* node, int level) noexcept;
  size_type size(Node<K>* node) noexcept;
  bool nodeExist(Node<K>* node) noexcept;
  void deleteBalanceTree(Node<K>* node) noexcept;
  void copyNodes(Node<K>* sourceNode, Node<K>*& targetNode);
  void moveNodes(Node<K>*& sourceNode, Node<K>*& targetNode) noexcept;
  void clear(Node<K>* delete_ptr) noexcept;
  iterator find(Node<K>* Node, const K& key);
};

}  // namespace s21

#include "s21_set.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_S21_SET_S21_SET_H_