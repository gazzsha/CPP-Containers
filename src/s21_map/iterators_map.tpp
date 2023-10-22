namespace s21 {

template <typename key_type, typename mapped_type, typename Comp>
IteratorMap<key_type, mapped_type, Comp>::IteratorMap(
    NodeMap<key_type, mapped_type>* node)
    : current_node(node) {
  key_type temp_k = current_node->key;
  mapped_type temp_v = current_node->value;
  pairIter = std::make_pair<key_type, mapped_type>(std::move(temp_k),
                                                   std::move(temp_v));
}

template <typename key_type, typename mapped_type, typename Comp>
IteratorMap<key_type, mapped_type, Comp>&
IteratorMap<key_type, mapped_type, Comp>::operator++() {
  if (current_node == nullptr) {
    return *this;
  }

  if (current_node->right->right != nullptr) {
    current_node = findMin(current_node->right);
  } else {
    NodeMap<key_type, mapped_type>* parent = current_node->parent;
    while (parent != nullptr && current_node == parent->right) {
      current_node = parent;
      parent = parent->parent;
    }
    current_node = parent;
  }

  if (current_node) pairIter = std::make_pair(get_key(), get_value());

  return *this;
}

template <typename key_type, typename mapped_type, typename Comp>
IteratorMap<key_type, mapped_type, Comp>&
IteratorMap<key_type, mapped_type, Comp>::operator--() {
  if (current_node == nullptr) {
    return *this;
  }

  if (current_node->left->left != nullptr) {
    current_node = findMax(current_node->left);
  } else {
    NodeMap<key_type, mapped_type>* parent = current_node->parent;
    while (parent != nullptr && current_node == parent->left) {
      current_node = parent;
      parent = parent->parent;
    }
    current_node = parent;
  }
  if (current_node) pairIter = std::make_pair(get_key(), get_value());
  return *this;
}

template <typename key_type, typename mapped_type, typename Comp>
std::pair<key_type, mapped_type>
IteratorMap<key_type, mapped_type, Comp>::operator*() {
  return std::make_pair(get_key(), get_value());
}

template <typename key_type, typename mapped_type, typename Comp>
std::pair<key_type, mapped_type>*
IteratorMap<key_type, mapped_type, Comp>::operator->() {
  return &(pairIter);
}

template <typename key_type, typename mapped_type, typename Comp>
bool IteratorMap<key_type, mapped_type, Comp>::operator<=(
    IteratorMap<key_type, mapped_type, Comp> node) const {
  if (current_node && node.current_node)
    return ((Comp{}(current_node->key, node.current_node->key)) ||
            (current_node->key == node.current_node->key));
  return 0;
}

template <typename key_type, typename mapped_type, typename Comp>
ConstIteratorMap<key_type, mapped_type, Comp>::ConstIteratorMap(
    const NodeMap<key_type, mapped_type>* node)
    : current_node(node) {}

template <typename key_type, typename mapped_type, typename Comp>
ConstIteratorMap<key_type, mapped_type, Comp>&
ConstIteratorMap<key_type, mapped_type, Comp>::operator++() {
  if (current_node == nullptr) {
    return *this;
  }

  if (current_node->right->right != nullptr) {
    current_node = findMin(current_node->right);
  } else {
    NodeMap<key_type, mapped_type>* parent = current_node->parent;
    while (parent != nullptr && current_node == parent->right) {
      current_node = parent;
      parent = parent->parent;
    }
    current_node = parent;
  }
  return *this;
}

template <typename key_type, typename mapped_type, typename Comp>
ConstIteratorMap<key_type, mapped_type, Comp>&
ConstIteratorMap<key_type, mapped_type, Comp>::operator--() {
  if (current_node == nullptr) {
    return *this;
  }

  if (current_node->left->left != nullptr) {
    current_node = findMax(current_node->left);
  } else {
    NodeMap<key_type, mapped_type>* parent = current_node->parent;
    while (parent != nullptr && current_node == parent->left) {
      current_node = parent;
      parent = parent->parent;
    }
    current_node = parent;
  }
  return *this;
}

template <typename key_type, typename mapped_type, typename Comp>
bool ConstIteratorMap<key_type, mapped_type, Comp>::operator<=(
    ConstIteratorMap<key_type, mapped_type, Comp> node) const {
  if (current_node && node.current_node)
    return ((Comp{}(current_node->key, node.current_node->key)) ||
            (current_node->key == node.current_node->key));
  return 0;
}

template <typename key_type, typename mapped_type>
NodeMap<key_type, mapped_type>* findMin(
    NodeMap<key_type, mapped_type>* node) noexcept {
  while (node->left->left != nullptr) {
    node = node->left;
  }
  return node;
}

template <typename key_type, typename mapped_type>
NodeMap<key_type, mapped_type>* findMax(
    NodeMap<key_type, mapped_type>* node) noexcept {
  while (node->right->right != nullptr) {
    node = node->right;
  }
  return node;
}

}  // namespace s21