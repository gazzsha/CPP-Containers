
namespace s21 { 

// template <typename K>
// std::pair<typename set<K>::iterator, bool> multiset<K>::insert(const value_type& value, Node<K>* current_node, int assign) {
//     Node<K>* temp;
//     if (!Node_tree_) {
//         Node_tree_ = new Node<K>(value, leaf_tree);
//         begin_node = Node_tree_;
//         end_node = Node_tree_;
//         return std::make_pair(iterator(Node_tree_), true);
//     }
//     if (value < current_node->key && value != current_node->key) {
//         if (current_node->left == leaf_tree) {
//             current_node->left = new Node<K>(value, current_node, leaf_tree);
//             insertBalanceTree(current_node->left);
//             if (begin_node->key > value) begin_node = current_node->left;
//             return std::make_pair(iterator(current_node->left), true);
//         } else {
//             return insert(value, current_node->left, assign);
//         }
//     } else if (value != current_node->key){
//         if (current_node->right == leaf_tree) {
//             current_node->right = new Node<K>(value, current_node, leaf_tree);
//             insertBalanceTree(current_node->right);
//             if (end_node->key < value) end_node = current_node->right;
//             return std::make_pair(iterator(current_node->right), true);
//         } else {
//             return insert(value, current_node->right, assign);
//         }
//     } else {
//         --size_multiset;
//         return std::make_pair(iterator(current_node), false);
//     }
// }

// template <typename K>
// std::pair<typename set<K>::iterator, bool> multiset<K>::insert(const value_type& value)  {
//     ++size_multiset;
//     return insert(value, Node_tree_, 0);
// }

template <typename K>
template <class... Args>
std::vector<std::pair<typename set<K>::iterator, bool>> multiset<K>::insert_many(Args&&... args)  { 
    std::vector<std::pair<typename set<K>::iterator, bool>> results;
    multiset<K> temp = {args...};
    for (auto it = temp.set<K>::begin(); it <= temp.set<K>::end(); ++it) { 
        auto itInsert = insert(it.get_key());
        results.push_back(itInsert);
    }
    return results;
    }



template <typename K>
typename multiset<K>::iterator multiset<K>::lower_bound(const K& key) { 
    for (auto it = set<K>::begin(); it <= set<K>::end(); ++it) {
        if (*it == key) return iterator(it);
    }
    return set<K>::end(); 
}

template <typename K>
typename multiset<K>::iterator multiset<K>::upper_bound(const K& key) { 
    iterator temp = set<K>::end();
    for (auto it = set<K>::begin(); it <= set<K>::end(); ++it) {
        if (*it == key)  {
            temp = it;
        }
    }
    return (++temp); 

}

template <typename K>
std::pair<typename multiset<K>::iterator,typename multiset<K>::iterator> multiset<K>::equal_range(const K& key) {
    iterator l = lower_bound(key);
    iterator r = upper_bound(key);
    return std::make_pair(l,r);

}

}
