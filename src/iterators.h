#ifndef SRC_ITERATORS_H_
#define SRC_ITERATORS_H_

//#include "s21_map.h"
namespace s21 {   
template<typename key_type, typename mapped_type>
class MapIterator {
public:
    MapIterator(Node<key_type, mapped_type>* node);
    MapIterator(Node<key_type, mapped_type>* leaf_tree, int a);
    MapIterator<key_type, mapped_type>& operator++();
    MapIterator<key_type, mapped_type>& operator--();
    const bool operator<=(MapIterator<key_type, mapped_type> node);
    Node<key_type, mapped_type>* current_node;
    //Node<key_type, mapped_type>* parent = current_node->parent;
private:
    Node<key_type, mapped_type>* findMin(Node<key_type, mapped_type>* node);
    Node<key_type, mapped_type>* findMax(Node<key_type, mapped_type>* node);
};

template<typename key_type, typename mapped_type>
class MapConstIterator {
public:
    MapConstIterator(const Node<key_type, mapped_type>* node);
    MapConstIterator<key_type, mapped_type>& operator--();
    MapConstIterator<key_type, mapped_type>& operator++();
    const Node<key_type, mapped_type>* current_node;
private:
    Node<key_type, mapped_type>* findMin(Node<key_type, mapped_type>* node);
    Node<key_type, mapped_type>* findMax(Node<key_type, mapped_type>* node);

};
}

#include "iterators.tpp"
#endif //SRC_ITERATORS_H_