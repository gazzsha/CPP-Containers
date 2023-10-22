#ifndef CPP2_S21_CONTAINERS_SRC_S21_MULTISET_S21_MULTISET_H_
#define CPP2_S21_CONTAINERS_SRC_S21_MULTISET_S21_MULTISET_H_
#include "../s21_set/s21_set.h"

namespace s21 {
template <typename K, typename Comp = std::less<K>>
class multiset : public set<K, Comp> {
 public:
  using key_type = K;
  using value_type = K;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = Iterator<K, Comp>;
  using const_iterator = ConstIterator<K, Comp>;
  using size_type = size_t;

 public:
  multiset();
  multiset(std::initializer_list<value_type> const& items);
  multiset(const multiset& m);
  multiset(multiset&& m) noexcept;
  multiset& operator=(multiset&& m) noexcept;
  template <class... Args>
  vector<std::pair<typename set<K, Comp>::iterator, bool>> insert_many(
      Args&&... args);
  std::pair<typename set<K, Comp>::iterator, bool> insert(
      const value_type& value) override;
  iterator lower_bound(const K& key);
  iterator upper_bound(const K& key);
  std::pair<iterator, iterator> equal_range(const K& key);

 private:
  std::pair<iterator, bool> insert(const value_type& value,
                                   Node<K>* current_node, int assign) override;
};
}  // namespace s21
#include "s21_multiset.tpp"
#endif  // #CPP2_S21_CONTAINERS_SRC_S21_MULTISET_S21_MULTISET_H_
