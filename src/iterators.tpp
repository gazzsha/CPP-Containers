namespace s21 {
    template<typename key_type, typename mapped_type>
    MapIterator<key_type, mapped_type>::MapIterator(Node<key_type, mapped_type>* node) : current_node(node){}

    template<typename key_type, typename mapped_type>
    MapConstIterator<key_type, mapped_type>::MapConstIterator(const Node<key_type, mapped_type>* node) : current_node(node){}
}