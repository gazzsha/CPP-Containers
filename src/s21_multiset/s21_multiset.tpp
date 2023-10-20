
namespace s21 {   
template <typename K>
std::pair<iterator, bool> multiset<K>::insert(const value_type& value, Node<K>* current_node, Node<K>* parent, int assign) override {
    Node<K>* temp;
    if (!Node_tree_) {
        Node_tree_ = new Node<K>(value, leaf_tree);
        begin_node = Node_tree_;
        end_node = Node_tree_;
        return std::make_pair(iterator(Node_tree_), true);
    }
    if (value < current_node->key && value != current_node->key) {
        if (current_node->left == leaf_tree) {
            current_node->left = new Node<K>(value, current_node, leaf_tree);
            insertBalanceTree(current_node->left);
            if (begin_node->key > value) begin_node = current_node->left;
            return std::make_pair(iterator(current_node->left), true);
        } else {
            return insert(value, current_node->left, current_node, assign);
        }
    } else if (value != current_node->key){
        if (current_node->right == leaf_tree) {
            current_node->right = new Node<K>(value, current_node, leaf_tree);
            insertBalanceTree(current_node->right);
            if (end_node->key < value) end_node = current_node->right;
            return std::make_pair(iterator(current_node->right), true);
        } else {
            return insert(value, current_node->right, current_node, assign);
        }
    } else {
        --size_multiset;
        return std::make_pair(iterator(current_node), false);
    }
}

template <typename K>
std::pair<iterator, bool> multiset<K>::insert(const value_type& value) override {
    ++size_multiset;
    return insert(value, Node_tree_, nullptr, 0);
}
}
