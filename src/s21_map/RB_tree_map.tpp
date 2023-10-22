
namespace s21 {

template <typename K, typename V>
NodeMap<K, V>::NodeMap() {
  this->red = false;
}

template <typename K, typename V>
NodeMap<K, V>::NodeMap(K key_, V value_, NodeMap<K, V>* leaf_tree)
    : left(leaf_tree),
      right(leaf_tree),
      parent(nullptr),
      red(false),
      key(key_),
      value(value_) {}

template <typename K, typename V>
NodeMap<K, V>::NodeMap(K key_, V value_, NodeMap<K, V>* parent_, bool red_)
    : left(nullptr),
      right(nullptr),
      parent(parent_),
      red(red_),
      key(key_),
      value(value_) {}

template <typename K, typename V>
NodeMap<K, V>::NodeMap(K key_, V value_, NodeMap<K, V>* parent_,
                       NodeMap<K, V>* leaf_tree)
    : left(leaf_tree),
      right(leaf_tree),
      parent(parent_),
      key(key_),
      value(value_) {}

template <typename K, typename V>
NodeMap<K, V>::~NodeMap() {}

}  // namespace s21