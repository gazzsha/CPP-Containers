//<PROJECT>_<PATH>_<FILE>_H_
#ifndef CPP2_S21_CONTAINERS_SRC_S21_ARRAY_H_  //
#define CPP2_S21_CONTAINERS_SRC_S21_ARRAY_H_

#include <iostream>
#include <stdexcept>
#include <type_traits>

namespace s21 {

template <typename T, std::size_t N>
class array {
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;
  using iterator = T *;
  using const_iterator = const T *;

 private:
  T arr[N] = {};
  size_type sz;

 public:
  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a) noexcept;
  ~array();
  array &operator=(array &&a) noexcept;
  constexpr reference at(size_type pos);
  constexpr const_reference at(size_type pos) const;
  constexpr reference operator[](size_type pos);
  constexpr const_reference front() const;
  constexpr const_reference back() const;
  constexpr iterator begin() noexcept;
  constexpr const_iterator cbegin() const noexcept;
  constexpr iterator end() noexcept;
  constexpr const_iterator cend() const noexcept;
  constexpr bool empty() const noexcept;
  constexpr size_type size() const noexcept;
  constexpr size_type max_size() const noexcept;
  void swap(array &other) noexcept(noexcept(std::is_nothrow_swappable_v<T>));
  void fill(const_reference value);
  array &operator=(const array &a);
  void print() {
    for (auto i = 0; i < N; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << "\n";
  }
};

template <typename T, size_t N>
array<T, N>::array() : sz(N) {}

template <typename T, size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items)
    : sz(items.size()) {
  size_t i = 0;
  for (auto it = items.begin(); it != items.end(); ++it, ++i) {
    arr[i] = *it;
  }
}

template <typename T, size_t N>
array<T, N>::array(const array &a) : sz(a.sz) {
  std::copy(std::begin(a.arr), std::end(a.arr), std::begin(arr));
}

template <typename T, size_t N>
array<T, N>::array(array &&a) noexcept : sz(a.sz) {
  std::move(std::begin(a.arr), std::end(a.arr), std::begin(arr));
}

template <typename T, size_t N>
array<T, N>::~array() {}

template <typename T, size_t N>
array<T, N> &array<T, N>::operator=(array &&a) noexcept {
  std::move(std::begin(a.arr), std::end(a.arr), std::begin(arr));
  return *this;
}

template <typename T, size_t N>
constexpr typename array<T, N>::reference array<T, N>::at(size_type pos) {
  if (pos >= N) throw std::out_of_range("pos > size of array");
  return arr[pos];
}

template <typename T, size_t N>
constexpr typename array<T, N>::const_reference array<T, N>::at(
    size_type pos) const {
  if (pos >= N) throw std::out_of_range("pos > size of array");
  return arr[pos];
}

template <typename T, size_t N>
constexpr typename array<T, N>::reference array<T, N>::operator[](
    size_type pos) {
  return arr[pos];
}

template <typename T, size_t N>
constexpr typename array<T, N>::const_reference array<T, N>::front() const {
  return arr[0];
}

template <typename T, size_t N>
constexpr typename array<T, N>::const_reference array<T, N>::back() const {
  return arr[N - 1];
}

template <typename T, size_t N>
constexpr typename array<T, N>::iterator array<T, N>::begin() noexcept {
  return arr;
}

template <typename T, size_t N>
constexpr typename array<T, N>::const_iterator array<T, N>::cbegin()
    const noexcept {
  return arr;
}

template <typename T, size_t N>
constexpr typename array<T, N>::iterator array<T, N>::end() noexcept {
  return arr + N;
}

template <typename T, size_t N>
constexpr typename array<T, N>::const_iterator array<T, N>::cend()
    const noexcept {
  return arr + N;
}

template <typename T, size_t N>
constexpr bool array<T, N>::empty() const noexcept {
  return !sz;
}

template <typename T, size_t N>
constexpr typename array<T, N>::size_type array<T, N>::size() const noexcept {
  return sz;
}

template <typename T, size_t N>
constexpr typename array<T, N>::size_type array<T, N>::max_size()
    const noexcept {
  return sz;
}

template <typename T, size_t N>
void array<T, N>::swap(array &other) noexcept(
    noexcept(std::is_nothrow_swappable_v<T>)) {
  if (std::is_nothrow_swappable_v<T>) {
    std::swap_ranges(std::begin(other.arr), std::end(other.arr),
                     std::begin(arr));
  }
}

template <typename T, size_t N>
void array<T, N>::fill(const_reference value) {
  for (size_type i = 0; i < sz; ++i) {
    arr[i] = value;
  }
}

template <typename T, size_t N>
array<T, N> &array<T, N>::operator=(const array &a) {
  std::copy(a.cbegin(), a.cend(), arr);
  return *this;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_S21_ARRAY_H_