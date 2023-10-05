#include <iostream>
#include "s21_map.h"

int main() {

}

template <typename key, typename T>
s21::map<key, T>::map() : RB_tree_ {}  // DEFAULT CONSTRUCTOR

template <typename key, typename T>
s21::map<key, T>::map(std::initializer_list<value_type> const &items) {
// создать мапу + загрузить initializer_list в rb_дерево
}

template <typename key, typename T>
s21::map<key, T>::map(const map &m) : { // : RB_tree(m.get_rb_tree){
    // создать в мапе rb_дерево такое же что и в m   (получить из m дерево примерно( создать обычную мапу с полем : m.get_rb_tree))
}

template <typename key, typename T>
s21::map<key, T>::map(map &&m) {

} 

template <typename key, typename T>
s21::map<key, T> s21::map<key, T>::operator=(map &&m) {

}





