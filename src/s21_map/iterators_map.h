#ifndef SRC_ITERATORS_H_
#define SRC_ITERATORS_H_

namespace s21 {   
template<typename key_type, typename mapped_type>
class Iterator {
public:
    key_type& get_key() { return current_node->key;}
    mapped_type& get_value() { return current_node->value; }
    Node<key_type, mapped_type>* get_current_node() { return current_node; }
    Iterator(Node<key_type, mapped_type>* node);
    Iterator<key_type, mapped_type>& operator++();
    Iterator<key_type, mapped_type>& operator--();
    std::pair<key_type,mapped_type> operator*();
    std::pair<key_type,mapped_type>* operator->();
    bool operator<=(Iterator<key_type, mapped_type> node) const;
    std::pair<key_type,mapped_type>  pairIter;
private:
    Node<key_type, mapped_type>* current_node;
    template <typename K, typename V>
    friend Node<key_type, mapped_type>* findMin(Node<key_type, mapped_type>* node) noexcept;

    template <typename K, typename V>
    friend Node<key_type, mapped_type>* findMax(Node<key_type, mapped_type>* node) noexcept;
};

template<typename key_type, typename mapped_type>
class ConstIterator {
public:
    const key_type& get_key_const() { return current_node->key;}
    const mapped_type& get_value_const() { return current_node->value; }
    ConstIterator(const Node<key_type, mapped_type>* node);
    ConstIterator<key_type, mapped_type>& operator++();
    ConstIterator<key_type, mapped_type>& operator--();
    ConstIterator<key_type, mapped_type>& operator*();
    bool operator<=(ConstIterator<key_type, mapped_type> node) const;
private:
    const Node<key_type, mapped_type>* current_node;
    
    
    template <typename K, typename V>
    friend Node<key_type, mapped_type>* findMin(Node<key_type, mapped_type>* node) noexcept;

    template <typename K, typename V>
    friend Node<key_type, mapped_type>* findMax(Node<key_type, mapped_type>* node) noexcept;
};
}

#include "iterators_map.tpp"
#endif //SRC_ITERATORS_H_