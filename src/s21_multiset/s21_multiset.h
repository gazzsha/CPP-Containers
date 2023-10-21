#include "../s21_set/s21_set.h"


namespace s21 {   
template <typename K>
class multiset : public set<K> {
    using key_type = K;
    using value_type = K;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = Iterator<K>;
    using const_iterator = ConstIterator<K>;
    using size_type = size_t;
public:
    multiset(): set<K>() {}
    multiset(std::initializer_list<value_type> const &items) {
    for (const value_type &item : items) {
        insert(item);
    }
    }

    multiset(const multiset &m): set<K>() {
    set<K>::size_set = m.size_set;
    try {
        set<K>::copyNodes(m.Node_tree_, set<K>::Node_tree_);
    } catch (...) {
        set<K>::clear(set<K>::Node_tree_);
        set<K>::size_set = 0;
    }
    }


    multiset(multiset &&m) noexcept :  set<K>(){
     set<K>::size_set = m.size_set;
        m.size_set = 0;
     set<K>::moveNodes(m.Node_tree_,  set<K>::Node_tree_);
} 

    multiset& operator=(multiset &&m) noexcept {
     set<K>::size_set = m.size_set;
    m.size_set = 0;
     set<K>::moveNodes(m.Node_tree_,  set<K>::Node_tree_);
    return *this;
}

    template <class... Args>
    std::vector<std::pair<typename set<K>::iterator, bool>> insert_many(Args&&... args);




    std::pair<iterator, bool> insert(const value_type& value) override {
            ++(set<K>::size_set);
    return insert(value, set<K>::Node_tree_, 0); }

    iterator lower_bound(const K& key);
    iterator upper_bound(const K& key);
        std::pair<iterator,iterator> equal_range(const K& key);
private:
    std::pair<iterator, bool> insert(const value_type& value, Node<K>* current_node, int assign) override {
            Node<K>* temp;
    if (!set<K>::Node_tree_) {
        set<K>::Node_tree_ = new Node<K>(value, set<K>::leaf_tree);
        set<K>::begin_node = set<K>::Node_tree_;
        set<K>::end_node = set<K>::Node_tree_;
        return std::make_pair(iterator(set<K>::Node_tree_), true);
    }
    if (value < current_node->key && value != current_node->key) {
        if (current_node->left == set<K>::leaf_tree) {
            current_node->left = new Node<K>(value, current_node, set<K>::leaf_tree);
            set<K>::insertBalanceTree(current_node->left);
            if (set<K>::begin_node->key > value) set<K>::begin_node = current_node->left;
            return std::make_pair(iterator(current_node->left), true);
        } else {
            return insert(value, current_node->left, assign);
        }
    } else {
        if (current_node->right == set<K>::leaf_tree) {
            current_node->right = new Node<K>(value, current_node, set<K>::leaf_tree);
            set<K>::insertBalanceTree(current_node->right);
            if (set<K>::end_node->key < value) set<K>::end_node = current_node->right;
            return std::make_pair(iterator(current_node->right), true);
        } else {
            return insert(value, current_node->right, assign);
        }
    }

    }
    

};
}


#include "s21_multiset.tpp"