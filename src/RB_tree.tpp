
namespace s21 {

template <typename K, typename V>
BaseNode<K,V>::BaseNode() : left(nullptr), right(nullptr), parent(nullptr) {}

template <typename K, typename V>
Node<K, V>::Node() {this->red=false;}

template <typename K, typename V>
Node<K, V>::Node(Node<K, V>* leaf_tree) {
    this->left = leaf_tree;
    this->right = leaf_tree;
    this->parent = leaf_tree;
}

template <typename K, typename V>
Node<K, V>::Node(K key_, V value_, Node<K,V>* parent_, Node<K, V>* leaf_tree) : key(key_), value(value_){
    this->parent = parent_;
    this->left = leaf_tree;
    this->right = leaf_tree;
}

}