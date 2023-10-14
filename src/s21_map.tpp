
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
    Node<K, V>* temp;
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
    Node<K, V>* tempNode = newNode;
    bool recursive_up = 0;
    while (tempNode->parent->parent != leaf_tree && tempNode->parent->red) {
        if (tempNode->parent == tempNode->parent->parent->left) {
            uncle = tempNode->parent->parent->right;
            if (uncle->red) {
                tempNode->parent->red = false;
                uncle->red = false;
                tempNode->parent->parent->red = true;
                tempNode = tempNode->parent->parent;
            } else {
                if (tempNode == tempNode->parent->right) {
                    leftRotate(tempNode);
                    tempNode = tempNode->left;
                    recursive_up = 1;
                }
                tempNode->parent->red = false;
                tempNode->parent->parent->red = true;
                rightRotate(tempNode);
            }
        }
        else {
            uncle = tempNode->parent->parent->left;
            if(uncle->red) {
                tempNode->parent->red = false;
                uncle->red = false;
                tempNode->parent->parent->red = true;
                tempNode = tempNode->parent->parent;
            } else {
                if (tempNode == tempNode->parent->left) {
                    leftRotate(tempNode);
                    tempNode = tempNode->right;
                    recursive_up = 1;
                }
                tempNode->parent->red = false;
                tempNode->parent->parent->red = true;
                rightRotate(tempNode);
            }
        } 
    }
    Node_tree_->red = false;
}




template <typename K, typename V>
void map<K, V>::leftRotate(Node<K, V>*& node) {
    Node<K, V>* grand_ = node->parent->parent;
    Node<K, V>* parent_ = node->parent;
    if(node == node->parent->right) {
        grand_->left = node;
        node->parent = grand_;
        parent_->parent = node;
        parent_->right = node->left;
        parent_->right->parent = parent_;
        node->left = parent_;

    } else {
        grand_->right = node;
        node->parent = grand_;
        parent_->parent = node;
        parent_->left = node->right;
        parent_->left->parent = parent_;
        node->right = parent_;
    }
}

template <typename K, typename V>
void map<K, V>::rightRotate(Node<K, V>*& node) {
    Node<K, V>* grand_ = node->parent->parent;
    Node<K, V>* parent_ = node->parent;
    
    if (parent_ == grand_->left) {
        if (grand_->parent) {
            if (grand_ == grand_->parent->right) grand_->parent->right = parent_;
            else grand_->parent->left = parent_;
            parent_->parent = grand_->parent;
        } else {
            Node_tree_ = parent_;
            parent_->parent = leaf_tree;
        }
        grand_->left = parent_->right;
        grand_->left->parent = grand_;
        grand_->parent = parent_;
        parent_->right = grand_;
    } else {
        if (grand_->parent) {
            if (grand_ == grand_->parent->right) grand_->parent->right = parent_;
            else grand_->parent->left = parent_;
            parent_->parent = grand_->parent;
        } else {
            Node_tree_ = parent_;
            parent_->parent = leaf_tree;
        }
        grand_->right = parent_->left;
        grand_->right->parent = grand_;
        grand_->parent = parent_;
        parent_->left = grand_;

    }
}



}  // namespace s21



// template <typename K, typename V>
// void map<K, V>::rightRotate(Node<K, V>*& node) {
//     Node<K, V>* grand_ = node->parent->parent;
//     Node<K, V>* parent_ = node->parent;
    
//     if (parent_ == grand_->left) {
//         grand_->left = parent_->right;
//         parent_->right->parent = grand_;
//         parent_->right = grand_;
//         if (grand_ == Node_tree_) {
//             Node_tree_ = parent_;
//             parent_->parent = leaf_tree;
//         } else {
//             parent_->parent = grand_->parent;
//             grand_->parent = parent_;
//         }
//     } else {
//         grand_->right = parent_->left;
//         parent_->left->parent = grand_;
//         parent_->left = grand_;
//         if (grand_ == Node_tree_) {
//             Node_tree_ = parent_;
//             parent_->parent = leaf_tree;
//         } else {
//             parent_->parent = grand_->parent;
//             grand_->parent = parent_;
//         }
//     }
// }