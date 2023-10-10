#include <iostream>
#include <string>
#include "RB_tree.h"
#include "iterators.h"

namespace s21 {
template <typename key, typename T>
class map {
public:
    using key_type = key;
    using mapped_type = T;
    using value_type = std::pair<const key_type, mapped_type>;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = MapIterator<key_type, T>;
    using const_iterator = MapConstIterator<key_type, T>;
    using size_type = size_t;

    map();   // default constructor

    map(std::initializer_list<value_type> const &items);
    map(const map &m);             
    map(map &&m);
    s21::map<key, T> operator=(map &&m);

    // Destructor
    ~map();
    

    // pub methods
    void clear();

    std::pair<iterator, bool> insert(const value_type& value);
    //std::pair<iterator, bool> insert(const value_type& value, Node<key, T>*& current_node, BaseNode* parent);
    Node<key, T> Node_tree_;
private:
    //BaseNode BaseRoot_tree_;
    //Node<key, T> Node_tree_;
};



} // namespace s21

#include "s21_map.tpp"