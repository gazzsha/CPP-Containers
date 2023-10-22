#ifndef CPP2_S21_CONTAINERS_SRC_S21_MAP_ITERATORS_MAP_H_
#define CPP2_S21_CONTAINERS_SRC_S21_MAP_ITERATORS_MAP_H_
#include <functional>
namespace s21 {
template <typename key_type, typename mapped_type,
          typename Comp = std::less<key_type>>
class IteratorMap {
 public:
  key_type& get_key() { return current_node->key; }
  mapped_type& get_value() { return current_node->value; }
  NodeMap<key_type, mapped_type>* get_current_node() { return current_node; }
  IteratorMap(NodeMap<key_type, mapped_type>* node);
  IteratorMap& operator++();
  IteratorMap& operator--();
  std::pair<key_type, mapped_type> operator*();
  std::pair<key_type, mapped_type>* operator->();
  bool operator<=(IteratorMap<key_type, mapped_type, Comp> node) const;
  std::pair<key_type, mapped_type> pairIter;

 private:
  NodeMap<key_type, mapped_type>* current_node;
  template <typename K, typename V>
  friend NodeMap<key_type, mapped_type>* findMin(
      NodeMap<key_type, mapped_type>* node) noexcept;

  template <typename K, typename V>
  friend NodeMap<key_type, mapped_type>* findMax(
      NodeMap<key_type, mapped_type>* node) noexcept;
};

template <typename key_type, typename mapped_type,
          typename Comp = std::less<key_type>>
class ConstIteratorMap {
 public:
  const key_type& get_key_const() { return current_node->key; }
  const mapped_type& get_value_const() { return current_node->value; }
  ConstIteratorMap(const NodeMap<key_type, mapped_type>* node);
  ConstIteratorMap& operator++();
  ConstIteratorMap& operator--();
  ConstIteratorMap& operator*();
  bool operator<=(ConstIteratorMap<key_type, mapped_type, Comp> node) const;

 private:
  const NodeMap<key_type, mapped_type>* current_node;

  template <typename K, typename V>
  friend NodeMap<key_type, mapped_type>* findMin(
      NodeMap<key_type, mapped_type>* node) noexcept;

  template <typename K, typename V>
  friend NodeMap<key_type, mapped_type>* findMax(
      NodeMap<key_type, mapped_type>* node) noexcept;
};
}  // namespace s21

#include "iterators_map.tpp"
#endif  // CPP2_S21_CONTAINERS_SRC_S21_MAP_ITERATORS_MAP_H_