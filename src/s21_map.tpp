
namespace s21 {

template <typename key, typename T>
map<key, T>::map() : Node_tree_(){}   // DEFAULT CONSTRUCTOR

template <typename key, typename T>
map<key, T>::~map() {} // DESTRUCTOR

template <typename key, typename T>
map<key, T>::map(std::initializer_list<value_type> const &items) {
    // создать мапу + загрузить initializer_list в rb_дерево
}

template <typename key, typename T>
map<key, T>::map(const map &m) { // : RB_tree(m.get_rb_tree){
    // создать в мапе rb_дерево такое же, как в m
}

template <typename key, typename T>
map<key, T>::map(map &&m) {
    // Реализация конструктора перемещения
} 

template <typename key, typename T>
map<key, T> map<key, T>::operator=(map &&m) {
    // Реализация оператора перемещения
}

template <typename key, typename T>
std::pair<typename map<key, T>::iterator, bool> map<key, T>::insert(const value_type& value) {
    Node<key, T>* temp = &Node_tree_;
     return insert(value, temp, nullptr);
 }

template <typename key, typename T>
std::pair<typename map<key, T>::iterator, bool> map<key, T>::insert(const value_type& value, Node<key, T>*& current_node, Node<key,T>* parent) {
    current_node->left = new Node<key, T>(value.first, value.second, parent);
    return std::make_pair(iterator(current_node->left), true);
}

}  // namespace s21




    // if (value.second < current_node.value){
    //     if (current_node.left == nullptr) {
    //         current_node.left = new Node<key, T>(value.first, value.second);
    //         return std::make_pair(iterator(current_node.left), true);
    //     }
    //     else insert(current_node.left);
    // }