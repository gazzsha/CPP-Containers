namespace s21 {
    template<typename key_type, typename mapped_type>
    MapIterator<key_type, mapped_type>::MapIterator(BaseNode* node) : current_node(node){}

    template<typename key_type, typename mapped_type>
    MapConstIterator<key_type, mapped_type>::MapConstIterator(const BaseNode* node) : current_node(node){}
}