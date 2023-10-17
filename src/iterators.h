#ifndef SRC_ITERATORS_H_
#define SRC_ITERATORS_H_

// #include "RB_tree.h"
namespace s21 {   
template<typename key_type, typename mapped_type>
class MapIterator {
public:
    MapIterator(Node<key_type, mapped_type>* node);
        Node<key_type, mapped_type>* current_node;
        //~MapIterator() {if (current_node) delete current_node;}
private:
   // Node<key_type, mapped_type>* current_node;
    //~MapIterator() {if (current_node) delete current_node;}
};

template<typename key_type, typename mapped_type>
class MapConstIterator {
public:
    MapConstIterator(const Node<key_type, mapped_type>* node);

private:
    const Node<key_type, mapped_type>* current_node;

};
}

#include "iterators.tpp"
#endif //SRC_ITERATORS_H_