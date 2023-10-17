
namespace s21 {

template <typename K, typename V>
Node<K, V>::Node() {this->red=false; this->value = 0;}

template <typename K, typename V>
Node<K, V>::Node(K key_, V value_,Node<K, V>* leaf_tree) : left(leaf_tree), right(leaf_tree), parent(nullptr), red(false), key(key_), value(value_), leaf_tree_(leaf_tree){}

template <typename K, typename V>
Node<K, V>::Node(K key_, V value_, Node<K, V>* parent_, bool red_) : left(nullptr), right(nullptr), parent(parent_), red(red_), key(key_), value(value_) {}


template <typename K, typename V>
Node<K, V>::Node(K key_, V value_, Node<K,V>* parent_, Node<K, V>* leaf_tree) : key(key_), value(value_), parent(parent_), left(leaf_tree), right(leaf_tree) {}

// template <typename K, typename V>
// Node<K, V>::~Node() {
//     std::cout << leaf_tree_ << '\n';
//     if (left && left != leaf_tree_) {
//         delete left;
//     }
//     if (right && right != leaf_tree_) {
//         delete right;
//     }
// }

}