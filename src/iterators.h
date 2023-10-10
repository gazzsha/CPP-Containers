#ifndef SRC_ITERATORS_H_
#define SRC_ITERATORS_H_

// #include "RB_tree.h"
namespace s21 {   
template<typename key_type, typename mapped_type>
class MapIterator {
public:
    MapIterator(BaseNode* node);
private:
    BaseNode* current_node;

};

template<typename key_type, typename mapped_type>
class MapConstIterator {
public:
    MapConstIterator(const BaseNode* node);

private:
    const BaseNode* current_node;

};
}

#include "iterators.tpp"
#endif //SRC_ITERATORS_H_