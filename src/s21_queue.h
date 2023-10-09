//<PROJECT>_<PATH>_<FILE>_H_
#ifndef CPP2_S21_CONTAINERS_SRC_S21_QUEQU_H_  //
#define CPP2_S21_CONTAINERS_SRC_S21_QUEQU_H_

#include "s21_list.h"

namespace s21 {

template <typename T, typename Container = list<T>>
class queue {
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 public:
  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q) noexcept;
  ~queue();
  queue &operator=(queue &&q) noexcept;
  const_reference front() const;
  const_reference back() const;
  constexpr bool empty() const noexcept;
  constexpr size_type size() const noexcept;
  void push(const_reference value);
  void pop();
  void swap(queue &other) noexcept;
  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  Container list;
};

template <typename T, typename Container>
queue<T, Container>::queue() : list() {}

template <typename T, typename Container>
queue<T, Container>::queue(std::initializer_list<value_type> const &items)
    : list(items) {}

template <typename T, typename Container>
queue<T, Container>::queue(const queue &q) : list(q.list) {}

template <typename T, typename Container>
queue<T, Container>::queue(queue &&q) noexcept : list(std::move(q.list)) {}

template <typename T, typename Container>
queue<T, Container>::~queue() {}

template <typename T, typename Container>
queue<T, Container> &queue<T, Container>::operator=(queue &&q) noexcept {
  if (this != &q) list = std::move(q.list);
  return *this;
}

template <typename T, typename Container>
typename queue<T, Container>::const_reference queue<T, Container>::front()
    const {
  return list.front();
}

template <typename T, typename Container>
typename queue<T, Container>::const_reference queue<T, Container>::back()
    const {
  return list.back();
}

template <typename T, typename Container>
constexpr bool queue<T, Container>::empty() const noexcept {
  return list.empty();
}

template <typename T, typename Container>
constexpr typename queue<T, Container>::size_type queue<T, Container>::size()
    const noexcept {
  return list.size();
}

template <typename T, typename Container>
void queue<T, Container>::push(const_reference value) {
  list.push_back(value);
}

template <typename T, typename Container>
void queue<T, Container>::pop() {
  list.pop_front();
}

template <typename T, typename Container>
void queue<T, Container>::swap(queue &other) noexcept {
  list.swap(other.list);
}

template <typename T, typename Container>
template <typename... Args>
void queue<T, Container>::insert_many_back(Args &&...args) {
  list.insert_many_back(std::forward<Args>(args)...);
}
};  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_S21_QUEQU_H_