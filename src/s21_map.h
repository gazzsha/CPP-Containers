#include"RB_tree.h"

namespace s21 {
template <typename key, typename T>
class map {
public:
    using key_type = key;
    using mapped_type = T;
    using value_type = std::pair<const key_type, mapped_type>;
    using reference = value_type&;
    using const_reference = const value_type&;
    //using iterator = MapIterator<K, T> когда будет класс итератор
    //using const_iterator = MapConstIterator<K, T> когда будет клас итератор
    using size_type = size_t;

    map();   // default constructor
    map(std::initializer_list<value_type> const &items);
    map(key key, mapped_type type) : key_(key), type_(type) {}
    map(const map &m);             
    map(map &&m);
    s21::map<key, T> operator=(map &&m);

    // Destructor
    ~map();
private:
    RB_tree<value_type, mapped_type> RB_tree_;
};
} // namespace s21
