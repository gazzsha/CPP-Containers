
namespace s21 {

template <typename K>
Node<K>::Node() {this->red=false;}

template <typename K>
Node<K>::Node(K key_, Node<K>* leaf_tree) : left(leaf_tree), right(leaf_tree), parent(nullptr), red(false), key(key_){}

template <typename K>
Node<K>::Node(K key_, Node<K>* parent_, bool red_) : left(nullptr), right(nullptr), parent(parent_), red(red_), key(key_) {}


template <typename K>
Node<K>::Node(K key_, Node<K>* parent_, Node<K>* leaf_tree) : key(key_), parent(parent_), left(leaf_tree), right(leaf_tree) {}

template <typename K>
Node<K>::~Node() {}

}