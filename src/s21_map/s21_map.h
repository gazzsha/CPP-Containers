#ifndef CPP2_S21_CONTAINERS_SRC_S21_MAP_S21_MAP_H
#define CPP2_S21_CONTAINERS_SRC_S21_MAP_S21_MAP_H

#include <algorithm>
#include <functional>
#include <iomanip>
#include <string>

#include "../s21_vector.h"
#include "RB_tree_map.h"
#include "iterators_map.h"

namespace s21 {
template <typename K, typename V, typename Comp = std::less<K>>
class map {
 public:
  using key_type = K;
  using mapped_type = V;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = IteratorMap<K, V, Comp>;
  using const_iterator = ConstIteratorMap<K, V, Comp>;
  using size_type = size_t;

  map();  // default constructor

  map(std::initializer_list<value_type> const& items);
  map(const map& m);
  map(map&& m);
  map& operator=(map&& m);
  // Destructor
  ~map();

  // pub methods
  iterator begin() {
    if (!Node_tree_) throw std::out_of_range("nope");
    NodeMap<K, V>* temp = Node_tree_;
    while (temp->left->left != nullptr) {
      temp = temp->left;
    }
    return iterator(temp);
  }
  iterator end() {
    if (!Node_tree_) throw std::out_of_range("nope");
    NodeMap<K, V>* temp = Node_tree_;
    while (temp->right->right != nullptr) {
      temp = temp->right;
    }
    return iterator(temp);
  }

  void clear() noexcept;
  bool empty() noexcept;
  size_type size() noexcept;
  size_type max_size() noexcept;
  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(const K& key, const V& obj);
  std::pair<iterator, bool> insert_or_assign(const K& key, const V& obj);
  void erase(iterator pos) noexcept;
  // void printTree() noexcept;
  void swap(map& other) noexcept;
  void merge(map& other) noexcept;
  V& at(const K& key);
  V& operator[](const K& key) noexcept;
  bool contains(const K& key);

  template <class... Args>
  vector<std::pair<iterator, bool>> insert_many(Args&&... args);
  NodeMap<K, V>* Node_tree_;
  static NodeMap<K, V>* leaf_tree;  // nil leaf
  static NodeMap<K, V> leaf;
  NodeMap<K, V>* begin_node;
  NodeMap<K, V>* end_node;
  size_t size_map;

 private:
  std::pair<iterator, bool> insert(const value_type& value,
                                   NodeMap<K, V>* current_node, int assign);
  void insertBalanceTree(NodeMap<K, V>* newNode) noexcept;
  void smallPivot(NodeMap<K, V>* node) noexcept;
  void bigPivot(NodeMap<K, V>* node) noexcept;
  //   void printTree(NodeMap<K, V>* node, int level) noexcept;
  bool nodeExist(NodeMap<K, V>* node) noexcept;
  void deleteBalanceTree(NodeMap<K, V>* node) noexcept;
  void copyNodes(NodeMap<K, V>* sourceNode, NodeMap<K, V>*& targetNode);
  void moveNodes(NodeMap<K, V>*& sourceNode,
                 NodeMap<K, V>*& targetNode) noexcept;
  void clear(NodeMap<K, V>* delete_ptr) noexcept;
};

}  // namespace s21

#include "s21_map.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_S21_MAP_S21_MAP_H