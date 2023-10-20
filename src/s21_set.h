#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "RB_tree.h"
#include "iterators.h"
//#include "s21_vector.h"

namespace s21 {
template <typename K, typename V>
class set {
public:
    using key_type = K;
    using setped_type = V;
    using value_type = std::pair<const key_type, setped_type>;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = Iterator<K, V>;
    using const_iterator = ConstIterator<K, V>;
    using size_type = size_t;

    set();   // default constructor

    set(std::initializer_list<value_type> const &items);
    set(const set &m);             
    set(set &&m);
    set<K, V>& operator=(set &&m);
    // Destructor
    ~set();
    
    // pub methods
    iterator begin() { return iterator(begin_node); }
    iterator end() { return iterator(end_node); }

    void clear() noexcept;
    bool empty() noexcept;
    size_type size() noexcept;
    size_type max_size() noexcept;
    std::pair<iterator, bool> insert(const value_type& value);
    std::pair<iterator, bool> insert(const K& key, const V& obj);
    std::pair<iterator, bool> insert_or_assign(const K& key, const V& obj);
    void erase(iterator pos) noexcept;
    void printTree() noexcept;
    void swap(set& other) noexcept;
    void merge(set& other) noexcept;
    V& at(const K& key);
    V& operator[](const K& key) noexcept;
    bool contains(const K& key) noexcept;
    
    template <class... Args>
    std::vector<std::pair<iterator, bool>> insert_many(Args&&... args);
private:
    Node<K, V>* Node_tree_;
    static Node<K, V>* leaf_tree;  // nil leaf
    static Node<K, V> leaf;
    Node<K, V>* begin_node;
    Node<K, V>* end_node;

    std::pair<iterator, bool> insert(const value_type& value, Node<K, V>* current_node, Node<K, V>* parent, int assign);
    void insertBalanceTree(Node<K, V>* newNode) noexcept;
    void smallPivot(Node<K, V>* node) noexcept;
    void bigPivot(Node<K, V>* node) noexcept;
    void printTree(Node<K, V>* node, int level) noexcept;
    size_type size(Node<K, V>* node) noexcept;
    bool nodeExist(Node<K, V>* node) noexcept;
    void deleteBalanceTree(Node<K, V>* node) noexcept;
    void copyNodes(Node<K, V>* sourceNode, Node<K, V>*& targetNode);
    void moveNodes(Node<K, V>*& sourceNode, Node<K, V>*& targetNode) noexcept;
    void clear(Node<K, V>* delete_ptr) noexcept;

};

} // namespace s21

#include "s21_set.tpp"