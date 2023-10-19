#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "RB_tree.h"
#include "iterators.h"

namespace s21 {
template <typename K, typename V>
class map {
public:
    using key_type = K;
    using mapped_type = V;
    using value_type = std::pair<const key_type, mapped_type>;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = MapIterator<K, V>;
    using const_iterator = MapConstIterator<K, V>;
    using size_type = size_t;

    map();   // default constructor

    map(std::initializer_list<value_type> const &items);
    map(const map &m);             
    map(map &&m);
    map<K, V>& operator=(map &&m);
    // Destructor
    ~map();
    
    // pub methods
    iterator begin() { return iterator(begin_node); }
    iterator end() { return iterator(end_node); }

    void clear();
    bool empty();
    size_type size();
    size_type max_size();
    std::pair<iterator, bool> insert(const value_type& value);
    std::pair<iterator, bool> insert(const K& key, const V& obj);
    std::pair<iterator, bool> insert_or_assign(const K& key, const V& obj);
    void erase(iterator pos);
    void printTree();
    void swap(map& other);
    void merge(map& other);
    V& at(const K& key);
    V& operator[](const K& key);
private:
    Node<K, V>* Node_tree_;
    static Node<K, V>* leaf_tree;  // nil leaf
    static Node<K, V> leaf;
    Node<K, V>* begin_node;
    Node<K, V>* end_node;

    std::pair<iterator, bool> insert(const value_type& value, Node<K, V>* current_node, Node<K, V>* parent, int assign);
    void insertBalanceTree(Node<K, V>* newNode);
    void smallPivot(Node<K, V>* node);
    void bigPivot(Node<K, V>* node);
    void printTree(Node<K, V>* node, int level);
    size_type size(Node<K, V>* node);
    bool nodeExist(Node<K, V>* node);
    void deleteBalanceTree(Node<K, V>* node);
    void copyNodes(Node<K, V>* sourceNode, Node<K, V>*& targetNode);
    void moveNodes(Node<K, V>*& sourceNode, Node<K, V>*& targetNode);
    void clear(Node<K, V>* delete_ptr);

};

} // namespace s21

#include "s21_map.tpp"