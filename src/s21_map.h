#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "RB_tree.h"
#include "iterators.h"
//#include "s21_vector.h"

namespace s21 {
template <typename K, typename V>
class map {
public:
    using key_type = K;
    using mapped_type = V;
    using value_type = std::pair<const key_type, mapped_type>;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = Iterator<K, V>;
    using const_iterator = ConstIterator<K, V>;
    using size_type = size_t;

    map();   // default constructor

    map(std::initializer_list<value_type> const &items);
    map(const map &m);             
    map(map &&m);
    map<K, V>& operator=(map &&m);
    // Destructor
    ~map();
    
    // pub methods
    iterator begin() { 
        if (!Node_tree_) throw std::out_of_range("nope");
        Node<K, V>* temp = Node_tree_;
        while (temp->left->left != nullptr) {
        temp = temp->left;
    }
        return iterator(temp); 
        }
    iterator end() { if (!Node_tree_) throw std::out_of_range("nope");
                  Node<K, V>* temp = Node_tree_;
        while (temp->right->right != nullptr) {
        temp = temp->right;
    }
        return iterator(temp);    
     }

    void clear() noexcept;
    bool empty() noexcept;
    size_type size() noexcept;
    size_type max_size() noexcept;
    std::pair<iterator, bool> insert(const value_type& value);
    std::pair<iterator, bool> insert(const K& key, const V& obj);
    std::pair<iterator, bool> insert_or_assign(const K& key, const V& obj);
    void erase(iterator pos) noexcept;
    void printTree() noexcept;
    void swap(map& other) noexcept;
    void merge(map& other) noexcept;
    V& at(const K& key);
    V& operator[](const K& key) noexcept;
    bool contains(const K& key);
    
    //template <class... Args>
    //std::vector<std::pair<iterator, bool>> insert_many(Args&&... args);
        Node<K, V>* Node_tree_;
    static Node<K, V>* leaf_tree;  // nil leaf
    static Node<K, V> leaf;
    Node<K, V>* begin_node;
    Node<K, V>* end_node;
    size_t size_map;
private:
    // Node<K, V>* Node_tree_;
    // static Node<K, V>* leaf_tree;  // nil leaf
    // static Node<K, V> leaf;
    // Node<K, V>* begin_node;
    // Node<K, V>* end_node;

    std::pair<iterator, bool> insert(const value_type& value, Node<K, V>* current_node, Node<K, V>* parent, int assign);
    void insertBalanceTree(Node<K, V>* newNode) noexcept;
    void smallPivot(Node<K, V>* node) noexcept;
    void bigPivot(Node<K, V>* node) noexcept;
    void printTree(Node<K, V>* node, int level) noexcept;
    bool nodeExist(Node<K, V>* node) noexcept;
    void deleteBalanceTree(Node<K, V>* node) noexcept;
    void copyNodes(Node<K, V>* sourceNode, Node<K, V>*& targetNode);
    void moveNodes(Node<K, V>*& sourceNode, Node<K, V>*& targetNode) noexcept;
    void clear(Node<K, V>* delete_ptr) noexcept;

};

} // namespace s21

#include "s21_map.tpp"