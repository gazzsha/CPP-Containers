#ifndef SRC_ITERATORS_H_
#define SRC_ITERATORS_H_

#include <functional>

namespace s21 {   
template<typename key_type,typename Comp = std::less<key_type>>
class Iterator {
public:
    key_type& get_key() { return current_node->key; }
    Node<key_type>* get_current_node() { return current_node; }
    Iterator(Node<key_type>* node);
    Iterator& operator++();
    Iterator& operator--();

    key_type& operator*();
    bool operator<=(Iterator<key_type,Comp> node) const;
    Iterator& operator=(const Iterator<key_type,Comp> other){
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

template<typename key_type,typename Comp = std::less<key_type>>
class ConstIterator {
public:
    ConstIterator(const Node<key_type>* node);
    ConstIterator(Iterator<key_type,Comp>& m) : current_node(m.get_current_node()) {}
    ConstIterator& operator++();
    ConstIterator& operator--();
    ConstIterator& operator*();
    bool operator<=(ConstIterator<key_type,Comp> node) const;
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