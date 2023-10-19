
namespace s21 {


template <typename K, typename V>
Node<K, V> map<K, V>::leaf = Node<K, V>();


template <typename K, typename V>
Node<K, V>* map<K, V>::leaf_tree = &leaf;


template <typename K, typename V>
map<K, V>::map() : Node_tree_(nullptr) {}

template <typename K, typename V>
map<K, V>::map(std::initializer_list<value_type> const &items) : Node_tree_(nullptr) {
    for (const value_type &item : items) {
        insert(item);
    }
}

template <typename K, typename V>
map<K, V>::map(const map &m) : map() {
    try {
        copyNodes(m.Node_tree_, Node_tree_);
    } catch (...) {
        clear(Node_tree_);
    }
}

template <typename K, typename V>
map<K, V>::map(map &&m) : Node_tree_(nullptr){
    moveNodes(m.Node_tree_, this->Node_tree_);
} 

template <typename K, typename V>
map<K, V>& map<K, V>::operator=(map &&m) {
    moveNodes(m.Node_tree_, Node_tree_);
    return *this;
}

template <typename K, typename V>
map<K, V>::~map() {
    clear();
}

template <typename K, typename V>
void map<K, V>::clear() noexcept {
    clear(Node_tree_);
    Node_tree_ = nullptr;
}

template <typename K, typename V>
bool map<K, V>::empty() noexcept {
    return Node_tree_;
}

template <typename K, typename V>
typename map<K, V>::size_type map<K, V>::size() noexcept {
    return size(Node_tree_);
}

template <typename K, typename V>
typename map<K, V>::size_type map<K, V>::max_size() noexcept {
    return std::numeric_limits<size_type>::max();
}

template <typename K, typename V>
std::pair<typename map<K, V>::iterator, bool> map<K, V>::insert(const value_type& value) {
    return insert(value, Node_tree_, nullptr, 0);
}

template <typename K, typename V>
std::pair<typename map<K, V>::iterator, bool> map<K, V>::insert(const K& key, const V& obj) {
    return insert(std::make_pair(key, obj), 0);
}

template <typename K, typename V>
std::pair<typename map<K, V>::iterator, bool> map<K, V>::insert_or_assign(const K& key, const V& obj) {
    return insert(std::make_pair(key, obj), Node_tree_, nullptr, 1);
}

template <typename K, typename V>
void map<K, V>::erase(iterator pos) noexcept {
    Node<K, V>* x_node, * y_node; 
    if(pos.current_node == end_node) end_node = pos.current_node->parent;
    if(pos.current_node == begin_node) begin_node = pos.current_node->parent;
    if (!pos.current_node || pos.current_node == leaf_tree) return;

    if (pos.current_node->left == leaf_tree || pos.current_node->right == leaf_tree) {
        y_node = pos.current_node;
    } else {
        y_node = pos.current_node->left;
        while (y_node->right != leaf_tree) y_node = y_node->right;
    }

    if (y_node->left != leaf_tree) x_node = y_node->left;
    else x_node = y_node->right;

    x_node->parent = y_node->parent;
    if (y_node->parent) {
        if (y_node == y_node->parent->left) y_node->parent->left = x_node;
        else y_node->parent->right = x_node;
    } else Node_tree_ = x_node;

    if (y_node != pos.current_node) {
        pos.current_node->key = y_node->key;
        pos.current_node->value = y_node->value;
    }
    if (!y_node->red) deleteBalanceTree(x_node);
    delete y_node;
}

template <typename K, typename V>
void map<K, V>::printTree() noexcept {
    printTree(Node_tree_, 0);
}

template <typename K, typename V>
void map<K, V>::swap(map& other) noexcept {
    Node<K, V>* temp = Node_tree_;
    Node_tree_ = other.Node_tree_;
    other.Node_tree_ = temp;
}

template <typename K, typename V>
void map<K, V>::merge(map& other) noexcept {
    for (auto it = other.begin(); it <= other.end(); ++it) {
        insert(std::make_pair(it.current_node->key, it.current_node->value));
    }
}

template <typename K, typename V>
V& map<K, V>::at(const K& key) {
    for (auto it = begin(); it <= end(); ++it) {
        if (it.current_node->key == key) return it.current_node->value;
    }
    throw std::out_of_range("Key not found");
}

template <typename K, typename V>
V& map<K, V>::operator[](const K& key) noexcept {
    for (auto it = begin(); it <= end(); ++it) {
        if (it.current_node->key == key) return it.current_node->value;
    }
    return insert(std::make_pair(key, V())).first.current_node->value;
}

template <typename K, typename V>
bool map<K, V>::contains(const K& key) noexcept {
    for (auto it = begin(); it <= end(); ++it) {
        if(it.current_node->key == key) return 1;
    }
    return 0;
}


template <typename K, typename V>
std::pair<typename map<K, V>::iterator, bool> map<K, V>::insert(const value_type& value, Node<K, V>* current_node, Node<K, V>* parent, int assign){
    Node<K, V>* temp;
    if (!Node_tree_) {
        Node_tree_ = new Node<K, V>(value.first, value.second, leaf_tree);
        begin_node = Node_tree_;
        end_node = Node_tree_;
        return std::make_pair(iterator(Node_tree_), true);
    }
    if (value.first < current_node->key && value.first != current_node->key) {
        if (current_node->left == leaf_tree) {
            current_node->left = new Node<K, V>(value.first, value.second, current_node, leaf_tree);
            insertBalanceTree(current_node->left);
            if (begin_node->key > value.first) begin_node = current_node->left;
            return std::make_pair(iterator(current_node->left), true);
        } else {
            return insert(value, current_node->left, current_node, assign);
        }
    } else if (value.first != current_node->key){
        if (current_node->right == leaf_tree) {
            current_node->right = new Node<K, V>(value.first, value.second, current_node, leaf_tree);
            insertBalanceTree(current_node->right);
            if (end_node->key < value.first) end_node = current_node->right;
            return std::make_pair(iterator(current_node->right), true);
        } else {
            return insert(value, current_node->right, current_node, assign);
        }
    } else {
        if (assign == 0){
            return std::make_pair(iterator(current_node), false);
        }
        current_node->value = value.second;
        return std::make_pair(iterator(current_node), true);
    }
}

template <typename K, typename V>
void map<K, V>::insertBalanceTree(Node<K, V>* newNode) noexcept {
    if (!begin_node || newNode->key < begin_node->key) begin_node = newNode;
    if (!end_node || newNode->key > end_node->key) end_node = newNode;
    while (newNode != Node_tree_ && newNode->parent->red && newNode->parent->parent != nullptr) {
        if (newNode->parent == newNode->parent->parent->left) {
            Node<K, V>* uncle = newNode->parent->parent->right;
            if (uncle->red) {
                newNode->parent->red = false;
                uncle->red = false;
                newNode->parent->parent->red = true;
                newNode = newNode->parent->parent;
            } else {
                if (newNode == newNode->parent->right) {
                    smallPivot(newNode);
                    newNode = newNode->left;
                }
                newNode->parent->red = false;
                newNode->parent->parent->red = true;
                bigPivot(newNode);
            }
        }
        else {
            Node<K, V>* uncle = newNode->parent->parent->left;
            if(uncle->red) {
                newNode->parent->red = false;
                uncle->red = false;
                newNode->parent->parent->red = true;
                newNode = newNode->parent->parent;
            } else {
                if (newNode == newNode->parent->left) {
                    smallPivot(newNode);
                    newNode = newNode->right;
                }
                newNode->parent->red = false;
                newNode->parent->parent->red = true;
                bigPivot(newNode);
            }
        }
    }
    Node_tree_->red = false;
    if (!begin_node || newNode->key < begin_node->key) begin_node = newNode;
    if (!end_node || newNode->key > end_node->key) end_node = newNode;
}

template <typename K, typename V>
void map<K, V>::smallPivot(Node<K, V>* node) noexcept {
    Node<K, V>* grand_ = node->parent->parent;
    Node<K, V>* parent_ = node->parent;

    if(node == node->parent->right){
        parent_->right = node->left;
        if (node->right != leaf_tree) node->left->parent = parent_;
        node->parent = parent_->parent;
        if (parent_->parent) {
            if (parent_ == parent_->parent->left)
                parent_->parent->left = node;
            else
                parent_->parent->right = node;
        }
        node->left = parent_;
        if (parent_ != leaf_tree) parent_->parent = node;
    } else {
        parent_->left = node->right;
        if (node->right != leaf_tree) node->right->parent = parent_;
        node->parent = parent_->parent;
        if (parent_->parent) {
            if (parent_ == parent_->parent->right)
                parent_->parent->right = node;
            else
                parent_->parent->left = node;
        }
        node->right = parent_;
        if (parent_ != leaf_tree) parent_->parent = node;
    }
}

template <typename K, typename V>
void map<K, V>::bigPivot(Node<K, V>* node) noexcept {
    Node<K, V>* grand_ = node->parent->parent;
    Node<K, V>* parent_ = node->parent;
    
    if (parent_ == grand_->left) {
        grand_->left = parent_->right;
        parent_->parent = grand_->parent;
        if (grand_->parent) {
            if (grand_ == grand_->parent->right) grand_->parent->right = parent_;
            else grand_->parent->left = parent_;
        } else {
            Node_tree_ = parent_;
        }
        parent_->right = grand_;
        grand_->left->parent = grand_;
        grand_->parent = parent_;
    } else {
        grand_->right = parent_->left;
        parent_->parent = grand_->parent;
        if (grand_->parent) {
            if (grand_ == grand_->parent->right) grand_->parent->right = parent_;
            else grand_->parent->left = parent_;
        } else {
            Node_tree_ = parent_;
        }
        parent_->left = grand_;
        grand_->right->parent = grand_;
        grand_->parent = parent_;
    }
}

template <typename K, typename V>
void map<K, V>::printTree(Node<K, V>* node, int level) noexcept {
    if (node != leaf_tree && node) {
        if (node->right) {
            printTree(node->right, level + 4);
        }
        if (level > 0) {
            std::cout << std::setw(level) << " ";
        }
        if (node->right) std::cout << " /\n" << std::setw(level) << " ";
        std::cout << node->value << (node->red ? " (R)" : " (B)") << "\n ";
        if (node->left) {
            std::cout << std::setw(level) << " " << " \\\n";
            printTree(node->left, level + 4);
        }
    } else {
        std::cout << std::setw(level) << " ";
        std::cout << leaf_tree->value << (leaf_tree->red ? " (R)" : " (B)") << "\n ";
    }
}

template <typename K, typename V>
typename map<K, V>::size_type map<K, V>::size(Node<K, V>* node) noexcept {
    if (!node || node == leaf_tree) {
        return 0;
    }
    return size(node->left) + size(node->right) + 1;
}

template <typename K, typename V>
bool map<K, V>::nodeExist(Node<K, V>* node) noexcept {
    return node != leaf_tree;
}

template <typename K, typename V>
void map<K, V>::deleteBalanceTree(Node<K, V>* node) noexcept {
    while (node != Node_tree_ && node->red == false) {
        if (node == node->parent->left) {
            Node<K, V>* brother = node->parent->right;
            if (brother->red == true) {
                brother->red = false;
                node->parent->red = true;
                bigPivot(brother->right);
                brother = node->parent->right;
            }

            if (brother->left->red == false && brother->right->red == false) {
                brother->red = true;
                node = node->parent;
            } else {
                if (brother->right->red == false) {
                    brother->left->red = false;
                    brother->red = true;
                    smallPivot(brother->left);
                    brother = brother->parent;
                }
                brother->red = node->parent->red;
                node->parent->red = false;
                brother->right->red = false;
                bigPivot(brother->right );
                node = Node_tree_;
            }
        } else {
            Node<K, V>* brother = node->parent->left;
            if (brother->red == true) {
                brother->red = false;
                node->parent->red = true;
                bigPivot(brother->left);
                brother = node->parent->left;
            }
            if (brother->left->red == false && brother->right->red == false) {
                brother->red = true;
                node = node->parent;
            } else {
                if (brother->left->red == false) {
                    brother->right->red = false;
                    brother->red = true;
                    smallPivot(brother->right);
                    brother = brother->parent;
                }
                brother->red = node->parent->red;
                node->parent->red = false;
                brother->left->red = false;
                bigPivot(brother->left);                
                node = Node_tree_;
            }
        }
    }
    node->red = false;
}

template <typename K, typename V>
void map<K, V>::copyNodes(Node<K, V>* sourceNode, Node<K, V>*& targetNode) {
    if (sourceNode) {
        
        targetNode = new Node<K, V>(sourceNode->key, sourceNode->value, sourceNode->parent, sourceNode->red);
    }

    if (sourceNode->right) {
        copyNodes(sourceNode->right, targetNode->right);
    }
    if (sourceNode->left) {
        copyNodes(sourceNode->left, targetNode->left);
    }
}

template <typename K, typename V>
void map<K, V>::moveNodes(Node<K, V>*& sourceNode, Node<K, V>*& targetNode) noexcept {
    targetNode = sourceNode;
    sourceNode = nullptr;
}

template <typename K, typename V>
void map<K, V>::clear(Node<K, V>* delete_ptr) noexcept {
    if (delete_ptr && delete_ptr != leaf_tree) {
        if (delete_ptr->right && delete_ptr->right != leaf_tree) {
            clear(delete_ptr->right);
        }
        if (delete_ptr->left && delete_ptr->left != leaf_tree) {
            clear(delete_ptr->left);
        }
        delete delete_ptr;
    }
}

template <typename K, typename V>
template <class... Args>
std::vector<std::pair<typename map<K, V>::iterator, bool>> map<K, V>::insert_many(Args&&... args) {
    std::vector<std::pair<iterator, bool>> results;
    return results;
}



}  // namespace s21
