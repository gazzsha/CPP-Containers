#ifndef SRC_ITERATORS_H_
#define SRC_ITERATORS_H_

namespace s21 {   
template<typename key_type>
class Iterator {
public:
    key_type& get_key() { return current_node->key; }
    Node<key_type>* get_current_node() { return current_node; }
    Iterator(Node<key_type>* node);
    Iterator<key_type>& operator++();
    Iterator<key_type>& operator--();

    key_type& operator*();
    bool operator<=(Iterator<key_type> node) const;
    Iterator<key_type>& operator=(const Iterator<key_type> other){
        current_node = other.current_node;
        return *this;
        }
private:
    Node<key_type>* current_node;
    
    template <typename K, typename V>
    friend Node<key_type>* findMin(Node<key_type>* node) noexcept;

    template <typename K, typename V>
    friend Node<key_type>* findMax(Node<key_type>* node) noexcept;
};

template<typename key_type>
class ConstIterator {
public:
    ConstIterator(const Node<key_type>* node);
    ConstIterator(Iterator<key_type>& m) : current_node(m.get_current_node()) {}
    ConstIterator<key_type>& operator++();
    ConstIterator<key_type>& operator--();
    ConstIterator<key_type>& operator*();
    bool operator<=(ConstIterator<key_type> node) const;
private:
    const Node<key_type>* current_node;
    
    template <typename K, typename V>
    friend Node<key_type>* findMin(Node<key_type>* node) noexcept;

    template <typename K, typename V>
    friend Node<key_type>* findMax(Node<key_type>* node) noexcept;
};
}

#include "iterators_set.tpp"
#endif //SRC_ITERATORS_H_