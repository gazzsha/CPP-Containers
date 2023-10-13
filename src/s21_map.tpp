
namespace s21 {

// template <typename key, typename T>
// Node<key, T> map<key, T>::leaf_tree;

template <typename K, typename V>
map<K, V>::map() : Node_tree_(nullptr) , leaf_tree(new Node<K, V>()) {}   // DEFAULT CONSTRUCTOR

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
    
    if (!Node_tree_) {
        Node_tree_ = new Node<K, V>(value.first, value.second, leaf_tree);
        return std::make_pair(iterator(Node_tree_), true);
    }
    if (value.second < current_node->value) {
        if (current_node->left == leaf_tree) {
            current_node->left = new Node<K, V>(value.first, value.second, current_node, leaf_tree);
            balanceTree(current_node->left);
            return std::make_pair(iterator(current_node->left), true);
        } else {
            return insert(value, current_node->left, current_node);
        }
    } else {
        if (current_node->right == leaf_tree) {
            current_node->right = new Node<K, V>(value.first, value.second, current_node, leaf_tree);
            balanceTree(current_node->right);
            return std::make_pair(iterator(current_node->right), true);
        } else {
            return insert(value, current_node->right, current_node);
        }
    }
}

template <typename K, typename V>
bool map<K, V>::nodeExist(Node<K, V>*& node){
    return node != leaf_tree;
}


template <typename K, typename V>
void map<K, V>::balanceTree(Node<K, V>*& newNode) {
    Node<K, V>* uncle;
    while (newNode->parent != nullptr && newNode->parent->parent != nullptr && newNode->parent->red) {
        if (newNode->parent == newNode->parent->parent->left) {
            uncle = newNode->parent->parent->right;
            if (uncle->red) {
                newNode->parent->red = false;
                uncle->red = false;
                newNode->parent->parent->red = true;
                if(Node_tree_ != newNode->parent->parent) newNode = newNode->parent->parent;
            } else {
                if (newNode == newNode->parent->right) {
                    newNode = newNode->parent;
                    leftRotate(newNode);
                }
                newNode->parent->red = false;
                newNode->parent->parent->red = true;
                rightRotate(newNode->parent->parent);
            }
        }
        else {
            uncle = newNode->parent->parent->left;
            if(uncle->red) {
                newNode->parent->red = false;
                uncle->red = false;
                newNode->parent->parent->red = true;
                if(Node_tree_ != newNode->parent->parent) newNode = newNode->parent->parent;
            } else {
                if (newNode == newNode->parent->left) {
                    newNode = newNode->parent;
                    rightRotate(newNode);
                }
                newNode->parent->red = false;
                newNode->parent->parent->red = true;
                leftRotate(newNode->parent->parent);
            }
        } 
    }
    Node_tree_->red = false;
}



template <typename K, typename V>
void map<K, V>::leftRotate(Node<K, V>*& node) {
    Node<K, V>* temp = node->right;
    node->right = temp->left;
    if (temp->left != leaf_tree) {
        temp->left->parent = node;
    }
    temp->parent = node->parent;
    if (node->parent == nullptr) {
        Node_tree_ = temp;
    } else if (node == node->parent->left) {
        node->parent->left = temp;
    } else {
        node->parent->right = temp;
    }
    temp->left = node;
    node->parent = temp;
}

template <typename K, typename V>
void map<K, V>::rightRotate(Node<K, V>*& node) {
    Node<K, V>* temp = node->left;
    temp->right = node;
    node->left = leaf_tree;
    temp->parent = node->parent;
    node->parent = temp;
}


}  // namespace s21
