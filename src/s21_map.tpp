
namespace s21 {

// template <typename key, typename T>
// Node<key, T> map<key, T>::leaf_tree;

template <typename K, typename V>
map<K, V>::map() : Node_tree_(nullptr){}   // DEFAULT CONSTRUCTOR

template <typename K, typename V>
map<K, V>::~map() {} // DESTRUCTOR

template <typename K, typename V>
map<K, V>::map(std::initializer_list<value_type> const &items) {
    // создать мапу + загрузить initializer_list в rb_дерево
}

template <typename K, typename V>
map<K, V>::map(const map &m) { // : RB_tree(m.get_rb_tree){
    // создать в мапе rb_дерево такое же, как в m
}

template <typename K, typename V>
map<K, V>::map(map &&m) {
    // Реализация конструктора перемещения
} 

template <typename K, typename V>
map<K, V> map<K, V>::operator=(map &&m) {
    // Реализация оператора перемещения
}

template <typename K, typename V>
std::pair<typename map<K, V>::iterator, bool> map<K, V>::insert(const value_type& value) {
    return insert(value, Node_tree_, nullptr);
}

template <typename K, typename V>
std::pair<typename map<K, V>::iterator, bool> map<K, V>::insert(const value_type& value, Node<K, V>*& current_node, Node<K, V>* parent){
    
    if (Node_tree_ == nullptr) {
        Node_tree_ = new Node<K, V>(value.first, value.second, nullptr);
        Node_tree_->red = false;
        return std::make_pair(iterator(Node_tree_), true);
    }
    if (value.second < current_node->value) {
        if (current_node->left == nullptr) {
            current_node->left = new Node<K, V>(value.first, value.second, current_node);
            return std::make_pair(iterator(current_node->left), true);
        } else {
            return insert(value, current_node->left, current_node);
        }
    } else if (value.second >= current_node->value) {
        if (current_node->right == nullptr) {
            current_node->right = new Node<K, V>(value.first, value.second, current_node);
            return std::make_pair(iterator(current_node->right), true);
        } else {
            return insert(value, current_node->right, current_node);
        }
    }
    return std::make_pair(iterator(Node_tree_), true);
}
}  // namespace s21




    // if (value.second < current_node.value){
    //     if (current_node.left == nullptr) {
    //         current_node.left = new Node<key, T>(value.first, value.second);
    //         return std::make_pair(iterator(current_node.left), true);
    //     }
    //     else insert(current_node.left);
    // }