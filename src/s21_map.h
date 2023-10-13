#include <iostream>
#include <string>
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
    s21::map<K, V> operator=(map &&m);

    // Destructor
    ~map();
    
    // pub methods
    //void clear();

    std::pair<iterator, bool> insert(const value_type& value);
    Node<K, V>* leaf_tree;  // nil leaf
    Node<K, V>* Node_tree_;
private:
    std::pair<iterator, bool> insert(const value_type& value, Node<K, V>*& current_node, Node<K, V>* parent);
    bool nodeExist(Node<K, V>*& node);
    void balanceTree(Node<K, V>*& newNode);
    void leftRotate(Node<K, V>*& newNode);
    void rightRotate(Node<K, V>*& newNode);
};

} // namespace s21

#include "s21_map.tpp"