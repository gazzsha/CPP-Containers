
namespace s21 {


template <typename K, typename V>
BaseNode<K,V>::BaseNode() : left(nullptr), right(nullptr), parent(nullptr) {}

template <typename K, typename V>
Node<K, V>::Node() : key(), value() {}

template <typename K, typename V>
Node<K, V>::Node(K key_, V value_, Node<K,V>* parent_) : key(key_), value(value_){this->parent = parent_;}

}