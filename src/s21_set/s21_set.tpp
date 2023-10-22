
namespace s21 {

template <typename K, typename Comp>
Node<K> set<K, Comp>::leaf = Node<K>();

template <typename K, typename Comp>
Node<K>* set<K, Comp>::leaf_tree = &leaf;

template <typename K, typename Comp>
set<K, Comp>::set() : Node_tree_(nullptr), size_set(0) {}

template <typename K, typename Comp>
set<K, Comp>::set(std::initializer_list<value_type> const& items)
    : Node_tree_(nullptr), size_set(0) {
  for (const value_type& item : items) {
    insert(item);
  }
}

template <typename K, typename Comp>
set<K, Comp>::set(const set& m) : set() {
  size_set = m.size_set;
  try {
    copyNodes(m.Node_tree_, Node_tree_);
  } catch (...) {
    clear(Node_tree_);
    size_set = 0;
  }
}

template <typename K, typename Comp>
set<K, Comp>::set(set&& m) : Node_tree_(nullptr), size_set(0) {
  size_set = m.size_set;
  m.size_set = 0;
  moveNodes(m.Node_tree_, this->Node_tree_);
}

template <typename K, typename Comp>
set<K, Comp>& set<K, Comp>::operator=(set&& m) {
  size_set = m.size_set;
  m.size_set = 0;
  moveNodes(m.Node_tree_, Node_tree_);
  return *this;
}

template <typename K, typename Comp>
set<K, Comp>::~set() {
  clear();
}

template <typename K, typename Comp>
void set<K, Comp>::clear() noexcept {
  clear(Node_tree_);
  size_set = 0;
  Node_tree_ = nullptr;
}

template <typename K, typename Comp>
bool set<K, Comp>::empty() const noexcept {
  return !Node_tree_;
}

template <typename K, typename Comp>
typename set<K, Comp>::size_type set<K, Comp>::size() const noexcept {
  return size_set;
}

template <typename K, typename Comp>
typename set<K, Comp>::size_type set<K, Comp>::max_size() const noexcept {
  return std::numeric_limits<size_type>::max() / sizeof(Node<K>) / 2;
}

template <typename K, typename Comp>
std::pair<typename set<K, Comp>::iterator, bool> set<K, Comp>::insert(
    const value_type& value) {
  ++size_set;
  return insert(value, Node_tree_, 0);
}

template <typename K, typename Comp>
void set<K, Comp>::erase(iterator pos) noexcept {
  Node<K>*x_node, *y_node;
  --size_set;
  if (pos.get_current_node() == end_node)
    end_node = pos.get_current_node()->parent;
  if (pos.get_current_node() == begin_node)
    begin_node = pos.get_current_node()->parent;
  if (!pos.get_current_node() || pos.get_current_node() == leaf_tree) return;

  if (pos.get_current_node()->left == leaf_tree ||
      pos.get_current_node()->right == leaf_tree) {
    y_node = pos.get_current_node();
  } else {
    y_node = pos.get_current_node()->left;
    while (y_node->right != leaf_tree) y_node = y_node->right;
  }

  if (y_node->left != leaf_tree)
    x_node = y_node->left;
  else
    x_node = y_node->right;

  x_node->parent = y_node->parent;
  if (y_node->parent) {
    if (y_node == y_node->parent->left)
      y_node->parent->left = x_node;
    else
      y_node->parent->right = x_node;
  } else
    Node_tree_ = x_node;

  if (y_node != pos.get_current_node()) {
    pos.get_key() = y_node->key;
  }
  if (!y_node->red) deleteBalanceTree(x_node);

  delete y_node;
}

template <typename K, typename Comp>
void set<K, Comp>::printTree() noexcept {
  printTree(Node_tree_, 0);
}

template <typename K, typename Comp>
void set<K, Comp>::swap(set& other) noexcept {
  size_t temp_s = size_set;
  Node<K>* temp = Node_tree_;
  Node_tree_ = other.Node_tree_;
  other.Node_tree_ = temp;
  size_set = other.size_set;
  other.size_set = temp_s;
}

template <typename K, typename Comp>
void set<K, Comp>::merge(set& other) noexcept {
  for (auto it = other.begin(); it <= other.end(); ++it) {
    insert(it.get_key());
  }
}

template <typename K, typename Comp>
bool set<K, Comp>::contains(const K& key) {
  try {
    for (auto it = begin(); it <= end(); ++it) {
      if (it.get_key() == key) return 1;
    }
  } catch (...) {
  }
  return 0;
}

template <typename K, typename Comp>
std::pair<typename set<K, Comp>::iterator, bool> set<K, Comp>::insert(
    const value_type& value, Node<K>* current_node, int assign) {
  if (!Node_tree_) {
    Node_tree_ = new Node<K>(value, leaf_tree);
    begin_node = Node_tree_;
    end_node = Node_tree_;
    return std::make_pair(iterator(Node_tree_), true);
  }
  if ((Comp{}(value, current_node->key)) && value != current_node->key) {
    if (current_node->left == leaf_tree) {
      current_node->left = new Node<K>(value, current_node, leaf_tree);
      insertBalanceTree(current_node->left);
      return std::make_pair(iterator(current_node->left), true);
    } else {
      return insert(value, current_node->left, assign);
    }
  } else if (value != current_node->key) {
    if (current_node->right == leaf_tree) {
      current_node->right = new Node<K>(value, current_node, leaf_tree);
      insertBalanceTree(current_node->right);
      return std::make_pair(iterator(current_node->right), true);
    } else {
      return insert(value, current_node->right, assign);
    }
  } else {
    --size_set;
    return std::make_pair(iterator(current_node), false);
  }
}

template <typename K, typename Comp>
void set<K, Comp>::insertBalanceTree(Node<K>* newNode) noexcept {
  while (newNode != Node_tree_ && newNode->parent->red &&
         newNode->parent->parent != nullptr) {
    if (newNode->parent == newNode->parent->parent->left) {
      Node<K>* uncle = newNode->parent->parent->right;
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
    } else {
      Node<K>* uncle = newNode->parent->parent->left;
      if (uncle->red) {
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
}

template <typename K, typename Comp>
void set<K, Comp>::smallPivot(Node<K>* node) noexcept {
  Node<K>* parent_ = node->parent;

  if (node == node->parent->right) {
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

template <typename K, typename Comp>
void set<K, Comp>::bigPivot(Node<K>* node) noexcept {
  Node<K>* grand_ = node->parent->parent;
  Node<K>* parent_ = node->parent;

  if (parent_ == grand_->left) {
    grand_->left = parent_->right;
    parent_->parent = grand_->parent;
    if (grand_->parent) {
      if (grand_ == grand_->parent->right)
        grand_->parent->right = parent_;
      else
        grand_->parent->left = parent_;
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
      if (grand_ == grand_->parent->right)
        grand_->parent->right = parent_;
      else
        grand_->parent->left = parent_;
    } else {
      Node_tree_ = parent_;
    }
    parent_->left = grand_;
    grand_->right->parent = grand_;
    grand_->parent = parent_;
  }
}

template <typename K, typename Comp>
void set<K, Comp>::printTree(Node<K>* node, int level) noexcept {
  if (node != leaf_tree && node) {
    if (node->right) {
      printTree(node->right, level + 4);
    }
    if (level > 0) {
      std::cout << std::setw(level) << " ";
    }
    if (node->right) std::cout << " /\n" << std::setw(level) << " ";
    std::cout << node->key << (node->red ? " (R)" : " (B)") << "\n ";
    if (node->left) {
      std::cout << std::setw(level) << " "
                << " \\\n";
      printTree(node->left, level + 4);
    }
  } else {
    std::cout << std::setw(level) << " ";
    std::cout << leaf_tree->key << (leaf_tree->red ? " (R)" : " (B)") << "\n ";
  }
}

template <typename K, typename Comp>
bool set<K, Comp>::nodeExist(Node<K>* node) noexcept {
  return node != leaf_tree;
}

template <typename K, typename Comp>
void set<K, Comp>::deleteBalanceTree(Node<K>* node) noexcept {
  while (node != Node_tree_ && node->red == false) {
    if (node == node->parent->left) {
      Node<K>* brother = node->parent->right;
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
        bigPivot(brother->right);
        node = Node_tree_;
      }
    } else {
      Node<K>* brother = node->parent->left;
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

template <typename K, typename Comp>
void set<K, Comp>::copyNodes(Node<K>* sourceNode, Node<K>*& targetNode) {
  if (sourceNode) {
    targetNode =
        new Node<K>(sourceNode->key, sourceNode->parent, sourceNode->red);
  }

  if (sourceNode->right) {
    copyNodes(sourceNode->right, targetNode->right);
  }
  if (sourceNode->left) {
    copyNodes(sourceNode->left, targetNode->left);
  }
}

template <typename K, typename Comp>
void set<K, Comp>::moveNodes(Node<K>*& sourceNode,
                             Node<K>*& targetNode) noexcept {
  targetNode = sourceNode;
  sourceNode = nullptr;
}

template <typename K, typename Comp>
void set<K, Comp>::clear(Node<K>* delete_ptr) noexcept {
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

template <typename K, typename Comp>
typename set<K, Comp>::iterator set<K, Comp>::find(const K& key) {
  return find(Node_tree_, key);
}

template <typename K, typename Comp>
typename set<K, Comp>::iterator set<K, Comp>::find(Node<K>* Node,
                                                   const K& key) {
  if (!Node) return end();

  if (Node->key == key) return iterator(Node);

  if (key == Node->key) {
    return iterator(Node);
  } else if (Comp{}(key, Node->key)) {
    return find(Node->left, key);
  } else {
    return find(Node->right, key);
  }
}

template <typename K, typename Comp>
template <class... Args>
vector<std::pair<typename set<K, Comp>::iterator, bool>>
set<K, Comp>::insert_many(Args&&... args) {
  vector<std::pair<iterator, bool>> results;
  set<K, Comp> temp = {args...};
  for (auto it = temp.begin(); it <= temp.end(); ++it) {
    auto itInsert = insert(it.get_key());
    results.push_back(itInsert);
  }
  return results;
}

}  // namespace s21
