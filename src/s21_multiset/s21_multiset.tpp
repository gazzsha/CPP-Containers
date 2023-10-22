
namespace s21 {

template <typename K, typename Comp>
multiset<K, Comp>::multiset() : set<K, Comp>() {}

template <typename K, typename Comp>
multiset<K, Comp>& multiset<K, Comp>::operator=(
    multiset<K, Comp>&& m) noexcept {
  set<K, Comp>::size_set = m.size_set;
  m.size_set = 0;
  set<K, Comp>::moveNodes(m.Node_tree_, set<K, Comp>::Node_tree_);
  return *this;
}

template <typename K, typename Comp>
multiset<K, Comp>::multiset(const multiset& m) : set<K, Comp>() {
  set<K, Comp>::size_set = m.size_set;
  try {
    set<K, Comp>::copyNodes(m.Node_tree_, set<K, Comp>::Node_tree_);
  } catch (...) {
    set<K, Comp>::clear(set<K, Comp>::Node_tree_);
    set<K, Comp>::size_set = 0;
  }
}

template <typename K, typename Comp>
multiset<K, Comp>::multiset(multiset&& m) noexcept : set<K, Comp>() {
  set<K, Comp>::size_set = m.size_set;
  m.size_set = 0;
  set<K, Comp>::moveNodes(m.Node_tree_, set<K, Comp>::Node_tree_);
}

template <typename K, typename Comp>
std::pair<typename multiset<K, Comp>::iterator, bool> multiset<K, Comp>::insert(
    const value_type& value, Node<K>* current_node, int assign) {
  if (!set<K, Comp>::Node_tree_) {
    set<K, Comp>::Node_tree_ = new Node<K>(value, set<K, Comp>::leaf_tree);
    set<K, Comp>::begin_node = set<K, Comp>::Node_tree_;
    set<K, Comp>::end_node = set<K, Comp>::Node_tree_;
    return std::make_pair(iterator(set<K, Comp>::Node_tree_), true);
  }

  if ((Comp{}(value, current_node->key)) && value != current_node->key) {
    if (current_node->left == set<K, Comp>::leaf_tree) {
      current_node->left =
          new Node<K>(value, current_node, set<K, Comp>::leaf_tree);
      set<K, Comp>::insertBalanceTree(current_node->left);
      if (set<K, Comp>::begin_node->key > value)
        set<K, Comp>::begin_node = current_node->left;
      return std::make_pair(iterator(current_node->left), true);
    } else {
      return insert(value, current_node->left, assign);
    }
  } else {
    if (current_node->right == set<K, Comp>::leaf_tree) {
      current_node->right =
          new Node<K>(value, current_node, set<K, Comp>::leaf_tree);
      set<K, Comp>::insertBalanceTree(current_node->right);
      if (set<K, Comp>::end_node->key < value)
        set<K, Comp>::end_node = current_node->right;
      return std::make_pair(iterator(current_node->right), true);
    } else {
      return insert(value, current_node->right, assign);
    }
  }
}
template <typename K, typename Comp>

multiset<K, Comp>::multiset(std::initializer_list<value_type> const& items) {
  for (const value_type& item : items) {
    insert(item);
  }
}

template <typename K, typename Comp>
std::pair<typename set<K, Comp>::iterator, bool> multiset<K, Comp>::insert(
    const value_type& value) {
  ++(set<K, Comp>::size_set);
  return insert(value, set<K, Comp>::Node_tree_, 0);
}

template <typename K, typename Comp>
template <class... Args>
vector<std::pair<typename set<K, Comp>::iterator, bool>>
multiset<K, Comp>::insert_many(Args&&... args) {
  vector<std::pair<typename set<K, Comp>::iterator, bool>> results;
  multiset<K, Comp> temp = {args...};
  for (auto it = temp.set<K, Comp>::begin(); it <= temp.set<K, Comp>::end();
       ++it) {
    auto itInsert = insert(it.get_key());
    results.push_back(itInsert);
  }
  return results;
}

template <typename K, typename Comp>
typename multiset<K, Comp>::iterator multiset<K, Comp>::lower_bound(
    const K& key) {
  for (auto it = set<K, Comp>::begin(); it <= set<K, Comp>::end(); ++it) {
    if (*it == key) return iterator(it);
  }
  return set<K, Comp>::end();
}

template <typename K, typename Comp>
typename multiset<K, Comp>::iterator multiset<K, Comp>::upper_bound(
    const K& key) {
  iterator temp = set<K, Comp>::end();
  for (auto it = set<K, Comp>::begin(); it <= set<K, Comp>::end(); ++it) {
    if (*it == key) {
      temp = it;
    }
  }
  return (++temp);
}

template <typename K, typename Comp>
std::pair<typename multiset<K, Comp>::iterator,
          typename multiset<K, Comp>::iterator>
multiset<K, Comp>::equal_range(const K& key) {
  iterator l = lower_bound(key);
  iterator r = upper_bound(key);
  return std::make_pair(l, r);
}

}  // namespace s21
