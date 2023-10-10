
namespace s21 {
BaseNode::BaseNode() : left(nullptr), right(nullptr), parent(nullptr) {std::cout << '1';}

template <typename K, typename V>
Node<K, V>::Node() : key(), value() {}

template <typename K, typename V>
Node<K, V>::Node(K key_, V value_, BaseNode* parent_) : key(key_), value(value_){}

}