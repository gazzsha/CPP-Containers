namespace s21 {
    
template<typename key_type, typename mapped_type>
MapIterator<key_type, mapped_type>::MapIterator(Node<key_type, mapped_type>* node) : current_node(node){}

template<typename key_type, typename mapped_type>
MapConstIterator<key_type, mapped_type>::MapConstIterator(const Node<key_type, mapped_type>* node) : current_node(node){}

template<typename key_type, typename mapped_type>
const bool MapIterator<key_type, mapped_type>::operator<=(MapIterator<key_type, mapped_type> node) {
    if (current_node && node.current_node) return current_node->key <= node.current_node->key;
    return 0;
}

template<typename key_type, typename mapped_type>
MapIterator<key_type, mapped_type>& MapIterator<key_type, mapped_type>::operator++() {
if (current_node == nullptr) {
    return *this;
}

if (current_node->right->right != nullptr) {
    current_node = findMin(current_node->right);
} else {
    Node<key_type, mapped_type>* parent = current_node->parent;
    while (parent != nullptr && current_node == parent->right) {
        current_node = parent;
        parent = parent->parent;
    }
    current_node = parent;
}
    
return *this;
}

template<typename key_type, typename mapped_type>
MapIterator<key_type, mapped_type>& MapIterator<key_type, mapped_type>::operator--() {
    if (current_node == nullptr) {
        return *this;
    }
    
    if (current_node->left->left != nullptr) {
        current_node = findMax(current_node->left);
    } else {
        Node<key_type, mapped_type>* parent = current_node->parent;
        while (parent != nullptr && current_node == parent->left) {
            current_node = parent;
            parent = parent->parent;
        }
        current_node = parent;
    }
    
    return *this;
}

template<typename key_type, typename mapped_type>
MapConstIterator<key_type, mapped_type>& MapConstIterator<key_type, mapped_type>::operator++() {
if (current_node == nullptr) {
    return *this;
}

if (current_node->right->right != nullptr) {
    current_node = findMin(current_node->right);
} else {
    Node<key_type, mapped_type>* parent = current_node->parent;
    while (parent != nullptr && current_node == parent->right) {
        current_node = parent;
        parent = parent->parent;
    }
    current_node = parent;
}
return *this;
}

template<typename key_type, typename mapped_type>
MapConstIterator<key_type, mapped_type>& MapConstIterator<key_type, mapped_type>::operator--() {
if (current_node == nullptr) {
    return *this;
}

if (current_node->left->left != nullptr) {
    current_node = findMax(current_node->left);
} else {
    Node<key_type, mapped_type>* parent = current_node->parent;
    while (parent != nullptr && current_node == parent->left) {
        current_node = parent;
        parent = parent->parent;
    }
    current_node = parent;
}
return *this;
}

template<typename key_type, typename mapped_type>
Node<key_type, mapped_type>* MapIterator<key_type, mapped_type>::findMin(Node<key_type, mapped_type>* node) {
    while (node->left->left != nullptr) {
        node = node->left;
    }
    return node;
}

template<typename key_type, typename mapped_type>
Node<key_type, mapped_type>* MapIterator<key_type, mapped_type>::findMax(Node<key_type, mapped_type>* node) {
    while (node->right->right != nullptr) {
        node = node->right;
    }
    return node;
}


template<typename key_type, typename mapped_type>
Node<key_type, mapped_type>* MapConstIterator<key_type, mapped_type>::findMin(Node<key_type, mapped_type>* node) {
    while (node->left->left != nullptr) {
        node = node->left;
    }
    return node;
}

template<typename key_type, typename mapped_type>
Node<key_type, mapped_type>* MapConstIterator<key_type, mapped_type>::findMax(Node<key_type, mapped_type>* node) {
    while (node->right->right != nullptr) {
        node = node->right;
    }
    return node;
}
    
}