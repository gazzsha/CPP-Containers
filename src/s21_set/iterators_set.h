#ifndef SRC_ITERATORS_H_
#define SRC_ITERATORS_H_

namespace s21 {   
template<typename key_type>
class Iterator {
public:
    Iterator(Node<key_type>* node);
    Iterator<key_type>& operator++();
    Iterator<key_type>& operator--();
    key_type& operator*();
    const bool operator<=(Iterator<key_type> node);
    Node<key_type>* current_node;
private:
    
    template <typename K, typename V>
    friend Node<key_type>* findMin(Node<key_type>* node) noexcept;

    template <typename K, typename V>
    friend Node<key_type>* findMax(Node<key_type>* node) noexcept;
};

template<typename key_type>
class ConstIterator {
public:
    ConstIterator(const Node<key_type>* node);
    ConstIterator<key_type>& operator++();
    ConstIterator<key_type>& operator--();
    ConstIterator<key_type>& operator*();
    const bool operator<=(ConstIterator<key_type> node);
    const Node<key_type>* current_node;
private:
    
    template <typename K, typename V>
    friend Node<key_type>* findMin(Node<key_type>* node) noexcept;

    template <typename K, typename V>
    friend Node<key_type>* findMax(Node<key_type>* node) noexcept;
};
}

#include "iterators_set.tpp"
#endif //SRC_ITERATORS_H_