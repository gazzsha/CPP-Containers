#ifndef CPP2_S21_CONTAINERS_SRC_S21_STACK_H_  //
#define CPP2_S21_CONTAINERS_SRC_S21_STACK_H_

#include "s21_list.h"

namespace s21 {

template <typename T, typename Container = list<T>>
class stack {
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 public:
  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);
  stack(stack &&s) noexcept;
  ~stack();
  stack &operator=(stack &&s) noexcept;
  const_reference top();
  bool empty() const noexcept;
  size_type size() const noexcept;
  void push(const_reference value);
  void pop();
  void swap(stack &other);
  template <typename... Args>
  void insert_many_front(Args &&...args);

 private:
  Container list;
};

template <typename T, typename Container>
stack<T, Container>::stack() : list() {}

template <typename T, typename Container>
stack<T, Container>::stack(std::initializer_list<value_type> const &items)
    : list(items) {}

template <typename T, typename Container>
stack<T, Container>::stack(const stack &s) : list(s.list) {}

template <typename T, typename Container>
stack<T, Container>::stack(stack &&s) noexcept : list(std::move(s.list)) {}

template <typename T, typename Container>
stack<T, Container>::~stack() {}

template <typename T, typename Container>
stack<T, Container> &stack<T, Container>::operator=(stack &&s) noexcept {
  if (this != &s) list = std::move(s.list);
  return *this;
}

template <typename T, typename Container>
typename stack<T, Container>::const_reference stack<T, Container>::top() {
  return list.back();
}

template <typename T, typename Container>
bool stack<T, Container>::empty() const noexcept {
  return list.empty();
}

template <typename T, typename Container>
typename stack<T, Container>::size_type stack<T, Container>::size()
    const noexcept {
  return list.size();
}

template <typename T, typename Container>
void stack<T, Container>::push(const_reference value) {
  list.push_back(value);
}

template <typename T, typename Container>
void stack<T, Container>::pop() {
  list.pop_back();
}

template <typename T, typename Container>
void stack<T, Container>::swap(stack &other) {
  list.swap(other.list);
}
template <typename T, typename Container>
template <typename... Args>
void stack<T, Container>::insert_many_front(Args &&...args) {
  list.insert_many_back(std::forward<Args>(args)...);
}

}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_SRC_S21_STACK_H_