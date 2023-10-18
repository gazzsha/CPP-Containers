#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "RB_tree.h"
//#include "iterators.h"

namespace s21 {
template <typename K, typename V>
class map {
public:
    class MapIterator {
    public:
        MapIterator(Node<K, V>* node);
        MapIterator& operator++();
        MapIterator& operator--();
        Node<K, V>* current_node;
    private:
        Node<K, V>* findMin(Node<K, V>* node);
        Node<K, V>* findMax(Node<K, V>* node);
    };

    class MapConstIterator {
    public:
        MapConstIterator(const Node<K, V>* node);
        MapConstIterator& operator--();
        MapConstIterator& operator++();
        const Node<K, V>* current_node;
    private:
        // Node<key_type, mapped_type>* findMin(Node<key_type, mapped_type>* node);
        // Node<key_type, mapped_type>* findMax(Node<key_type, mapped_type>* node);
    };


    using key_type = K;
    using mapped_type = V;
    using value_type = std::pair<const key_type, mapped_type>;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = MapIterator;
    using const_iterator = MapConstIterator;
    using size_type = size_t;

    map();   // default constructor

    map(std::initializer_list<value_type> const &items);
    map(const map &m);             
    map(map &&m);
    map<K, V>& operator=(map &&m);
    // Destructor
    ~map();
    
    // pub methods
    iterator begin() { return iterator(begin_node); }
    iterator end() { return iterator(end_node); }

    void clear();
    bool empty();
    size_type size();
    size_type max_size();
    std::pair<iterator, bool> insert(const value_type& value);
    std::pair<iterator, bool> insert(const K& key, const V& obj);
    std::pair<iterator, bool> insert_or_assign(const K& key, const V& obj);
    void erase(iterator pos);
    void printTree();
    void swap(map& other);
    void merge(map& other);
private:
    Node<K, V>* Node_tree_;
    static Node<K, V>* leaf_tree;  // nil leaf
    static Node<K, V> leaf;
     Node<K, V>* begin_node;
    Node<K, V>* end_node;

    std::pair<iterator, bool> insert(const value_type& value, Node<K, V>* current_node, Node<K, V>* parent, int assign);
    void insertBalanceTree(Node<K, V>* newNode);
    void smallPivot(Node<K, V>* node);
    void bigPivot(Node<K, V>* node);
    void printTree(Node<K, V>* node, int level);
    size_type size(Node<K, V>* node);
    bool nodeExist(Node<K, V>* node);
    void deleteBalanceTree(Node<K, V>* node);
    void copyNodes(Node<K, V>* sourceNode, Node<K, V>*& targetNode);
    void moveNodes(Node<K, V>*& sourceNode, Node<K, V>*& targetNode);
    void clear(Node<K, V>* delete_ptr);

};

} // namespace s21

#include "s21_map.tpp"