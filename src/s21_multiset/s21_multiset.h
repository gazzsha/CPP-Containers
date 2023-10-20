#include "../s21_set/s21_set.h"


namespace s21 {   
template <typename K>
class multiset : protected set<K> {
    using key_type = K;
    using value_type = K;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = Iterator<K>;
    using const_iterator = ConstIterator<K>;
    using size_type = size_t;
public:
    std::pair<iterator, bool> insert(const value_type& value) override;
private:
    size_t size_multiset;
    std::pair<iterator, bool> insert(const value_type& value, Node<K>* current_node, Node<K>* parent, int assign) override;
};
}