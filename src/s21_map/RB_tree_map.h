#ifndef CPP2_S21_CONTAINERS_SRC_S21_MAP_RB_TREE_MAP_H_
#define CPP2_S21_CONTAINERS_SRC_S21_MAP_RB_TREE_MAP_H_
namespace s21 {

template <typename K, typename V>
class NodeMap {
 public:
  NodeMap();
  NodeMap(K key_, V value_, NodeMap<K, V>* parent_,
          NodeMap<K, V>* leaf_tree);  // CONSTRUCTOR FOR NEW NODE
  NodeMap(K key_, V value_, NodeMap<K, V>* leaf_tree);  // CONSTURCTOR FOR ROOT
  NodeMap(K key_, V value_, NodeMap<K, V>* parent_, bool red_);
  ~NodeMap();
  NodeMap<K, V>* left;
  NodeMap<K, V>* right;
  NodeMap<K, V>* parent;
  bool red = true;
  K key;
  V value;
};
}  // namespace s21
#include "RB_tree_map.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_S21_MAP_RB_TREE_MAP_H_