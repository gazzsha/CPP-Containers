#ifndef SRC_ITERATORS_H_
#define SRC_ITERATORS_H_

namespace s21 {   
template<typename key_type, typename mapped_type>
class Iterator {
public:
    Iterator(Node<key_type, mapped_type>* node);
    Iterator<key_type, mapped_type>& operator++();
    Iterator<key_type, mapped_type>& operator--();
    mapped_type& operator*();
    const bool operator<=(Iterator<key_type, mapped_type> node);
    Node<key_type, mapped_type>* current_node;
private:
    
    template <typename K, typename V>
    friend Node<key_type, mapped_type>* findMin(Node<key_type, mapped_type>* node) noexcept;

    template <typename K, typename V>
    friend Node<key_type, mapped_type>* findMax(Node<key_type, mapped_type>* node) noexcept;
};

template<typename key_type, typename mapped_type>
class ConstIterator {
public:
    ConstIterator(const Node<key_type, mapped_type>* node);
    ConstIterator<key_type, mapped_type>& operator++();
    ConstIterator<key_type, mapped_type>& operator--();
    ConstIterator<key_type, mapped_type>& operator*();
    const bool operator<=(ConstIterator<key_type, mapped_type> node);
    const Node<key_type, mapped_type>* current_node;
private:
    
    template <typename K, typename V>
    friend Node<key_type, mapped_type>* findMin(Node<key_type, mapped_type>* node) noexcept;

    template <typename K, typename V>
    friend Node<key_type, mapped_type>* findMax(Node<key_type, mapped_type>* node) noexcept;
};
}

#include "iterators_map.tpp"
#endif //SRC_ITERATORS_H_