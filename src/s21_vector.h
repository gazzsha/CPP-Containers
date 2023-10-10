//<PROJECT>_<PATH>_<FILE>_H_
#ifndef CPP2_S21_CONTAINERS_SRC_S21_VECTOR_H_  //
#define CPP2_S21_CONTAINERS_SRC_S21_VECTOR_H_
#include <cmath>
#include <memory>
#include <stdexcept>
#include <utility>

namespace s21 {
template <typename T, typename Alloc = std::allocator<T>>
class vector {
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;
  using AllocTraits = std::allocator_traits<Alloc>;

 public:
  template <typename U, typename X>
  class VectorIterator {
   public:
    VectorIterator() noexcept;
    VectorIterator(value_type* new_ptr) noexcept;
    reference operator*();
    value_type* getter() noexcept;
    VectorIterator& operator++();
    VectorIterator& operator--();
    VectorIterator operator-(const size_type& ind);
    VectorIterator operator+(const size_type& ind);
    bool operator!=(const VectorIterator& other) const noexcept;
    bool operator==(const VectorIterator& other) const noexcept;

   private:
    value_type* ptr;
    friend class vector<T, Alloc>;
  };

  template <typename Y, typename Z>
  class VectorConstIterator {
   public:
    VectorConstIterator(value_type* new_ptr) noexcept;
    VectorConstIterator(const VectorIterator<Y, Z>& other);
    VectorConstIterator operator+(const size_type& pos);
    const_reference operator*() const noexcept;
    bool operator==(const VectorConstIterator& other) const noexcept;
    value_type* getter() noexcept;

   private:
    value_type* ptr;
    friend class vector<T, Alloc>;
  };

  using iterator = VectorIterator<T, Alloc>;
  using const_iterator = VectorConstIterator<T, Alloc>;

  vector() noexcept;
  vector(size_type n);
  vector(const vector& v);
  vector(std::initializer_list<value_type> const& items);
  vector(vector&& v) noexcept(noexcept(alloc = std::move(v.alloc)));
  ~vector();
  vector& operator=(vector&& v) noexcept(noexcept(alloc = std::move(v.alloc)));

  iterator begin() noexcept;
  iterator end() noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;
  constexpr reference operator[](size_type pos);
  constexpr const_reference operator[](size_type pos) const;
  reference at(size_type pos);
  const_reference front() const;
  const_reference back() const;
  value_type* data() noexcept;
  bool empty() const noexcept;
  size_type max_size() const noexcept;
  void reserve(size_type size);
  void shrink_to_fit();
  void clear() noexcept;
  void pop_back();
  void push_back(const_reference value);
  void push_back(value_type&& value);
  template <typename... Args>
  void emplace_back(Args&&... args);
  size_type size() const noexcept;
  size_type capacity() const noexcept;
  void erase(iterator pos);
  iterator insert(iterator pos, const_reference value);
  void swap(vector& other) noexcept(
      noexcept(AllocTraits::propagate_on_container_swap::value ||
               AllocTraits::is_always_equal::value));
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args&&... args);
  template <typename... Args>
  void insert_many_back(Args&&... args);

 private:
  Alloc alloc;
  T* arr;
  size_t sz;
  size_t cap;
};

template <typename value_type, typename Alloc>
template <typename U, typename X>
vector<value_type, Alloc>::VectorIterator<U, X>::VectorIterator() noexcept
    : ptr(nullptr) {}

template <typename value_type, typename Alloc>
template <typename U, typename X>
vector<value_type, Alloc>::VectorIterator<U, X>::VectorIterator(
    value_type* new_ptr) noexcept
    : ptr(new_ptr) {}

template <typename value_type, typename Alloc>
template <typename U, typename X>
typename vector<value_type, Alloc>::reference
vector<value_type, Alloc>::VectorIterator<U, X>::operator*() {
  return *ptr;
}

template <typename value_type, typename Alloc>
template <typename U, typename X>
value_type* vector<value_type, Alloc>::VectorIterator<U, X>::getter() noexcept {
  return ptr;
}

template <typename value_type, typename Alloc>
template <typename U, typename X>
typename vector<value_type, Alloc>::VectorIterator<U, X>&
vector<value_type, Alloc>::VectorIterator<U, X>::operator++() {
  ++ptr;
  return *this;
}

template <typename value_type, typename Alloc>
template <typename U, typename X>
typename vector<value_type, Alloc>::VectorIterator<U, X>&
vector<value_type, Alloc>::VectorIterator<U, X>::operator--() {
  --ptr;
  return *this;
}

template <typename value_type, typename Alloc>
template <typename U, typename X>
typename vector<value_type, Alloc>::VectorIterator<U, X>
vector<value_type, Alloc>::VectorIterator<U, X>::operator-(
    const size_type& ind) {
  iterator tmp(ptr - ind);
  return tmp;
}

template <typename value_type, typename Alloc>
template <typename U, typename X>
typename vector<value_type, Alloc>::VectorIterator<U, X>
vector<value_type, Alloc>::VectorIterator<U, X>::operator+(
    const size_type& ind) {
  iterator tmp(ptr + ind);
  return tmp;
}

template <typename value_type, typename Alloc>
template <typename U, typename X>
bool vector<value_type, Alloc>::VectorIterator<U, X>::operator!=(
    const VectorIterator& other) const noexcept {
  return ptr != other.ptr;
}

template <typename value_type, typename Alloc>
template <typename Y, typename Z>
bool vector<value_type, Alloc>::VectorIterator<Y, Z>::operator==(
    const VectorIterator& other) const noexcept {
  return ptr == other.ptr;
}

template <typename value_type, typename Alloc>
template <typename Y, typename Z>
vector<value_type, Alloc>::VectorConstIterator<Y, Z>::VectorConstIterator(
    value_type* new_ptr) noexcept
    : ptr(new_ptr) {}

template <typename value_type, typename Alloc>
template <typename Y, typename Z>
vector<value_type, Alloc>::VectorConstIterator<Y, Z>::VectorConstIterator(
    const VectorIterator<Y, Z>& other)
    : ptr(other.ptr) {}

template <typename value_type, typename Alloc>
template <typename Y, typename Z>
typename vector<value_type, Alloc>::const_reference vector<
    value_type, Alloc>::VectorConstIterator<Y, Z>::operator*() const noexcept {
  return *ptr;
}

template <typename value_type, typename Alloc>
template <typename Y, typename Z>
bool vector<value_type, Alloc>::VectorConstIterator<Y, Z>::operator==(
    const VectorConstIterator& other) const noexcept {
  return ptr == other.ptr;
}

template <typename value_type, typename Alloc>
template <typename Y, typename Z>
vector<value_type, Alloc>::VectorConstIterator<Y, Z>
vector<value_type, Alloc>::VectorConstIterator<Y, Z>::operator+(
    const size_type& pos) {
  const_iterator temp = (ptr + pos);
  return temp;
}

template <typename value_type, typename Alloc>
template <typename Y, typename Z>
value_type*
vector<value_type, Alloc>::VectorConstIterator<Y, Z>::getter() noexcept {
  return ptr;
}

template <typename value_type, typename Alloc>
vector<value_type, Alloc>::vector() noexcept
    : alloc(Alloc()), arr(nullptr), sz(0), cap(0) {}

template <typename value_type, typename Alloc>
vector<value_type, Alloc>::vector(size_type n)
    : alloc(Alloc()), arr(AllocTraits::allocate(alloc, n)), sz(n), cap(n) {
  for (size_t i = 0; i < sz; ++i) try {
      AllocTraits::construct(alloc, arr + i, value_type());
    } catch (...) {
      for (size_type j = 0; j < i; ++j) {
        AllocTraits::destroy(alloc, arr + j);
      }
      AllocTraits::deallocate(alloc, arr, cap);
      throw;
    }
}

template <typename value_type, typename Alloc>
vector<value_type, Alloc>::vector(const vector& v)
    : alloc(AllocTraits::select_on_container_copy_construction(v.alloc)),
      arr(AllocTraits::allocate(alloc, v.cap)),
      sz(v.sz),
      cap(v.cap) {
  for (size_type i = 0; i < sz; ++i) {
    try {
      AllocTraits::construct(alloc, arr + i, v.arr[i]);
    } catch (...) {
      for (size_type j = 0; j < i; ++i) {
        AllocTraits::destroy(alloc, arr + j);
      }
      AllocTraits::deallocate(alloc, arr, cap);
      throw;
    }
  }
}

template <typename value_type, typename Alloc>
vector<value_type, Alloc>::vector(
    std::initializer_list<value_type> const& items)
    : vector(items.size()) {
  for (size_type i = 0; i < sz; ++i) {
    arr[i] = *(items.begin() + i);
  }
}

template <typename value_type, typename Alloc>
vector<value_type, Alloc>::vector(vector&& v) noexcept(
    noexcept(alloc = std::move(v.alloc)))
    : arr(v.arr), sz(v.sz), cap(v.cap) {
  if (AllocTraits::propagate_on_container_move_assignment::value) {
    alloc = (std::move(v.alloc));
  }
  v.sz = 0;
  v.cap = 0;
  v.arr = nullptr;
}

template <typename value_type, typename Alloc>
vector<value_type, Alloc>::~vector() {
  for (size_type i = 0; i < sz; i++) {
    AllocTraits::destroy(alloc, arr + i);
  }
  AllocTraits::deallocate(alloc, arr, cap);
  sz = 0;
  cap = 0;
  arr = nullptr;
}

template <typename value_type, typename Alloc>
vector<value_type, Alloc>& vector<value_type, Alloc>::operator=(
    vector&& v) noexcept(noexcept(alloc = std::move(v.alloc))) {
  for (size_type i = 0; i < sz; ++i) {
    AllocTraits::destroy(alloc, arr + i);
  }
  AllocTraits::deallocate(alloc, arr, cap);
  arr = v.arr;
  sz = v.sz;
  cap = v.cap;
  if (AllocTraits::propagate_on_container_move_assignment::value) {
    alloc = (std::move(v.alloc));
  }
  v.arr = nullptr;
  v.sz = 0;
  v.cap = 0;
  return *this;
}

template <typename value_type, typename Alloc>
typename vector<value_type, Alloc>::iterator
vector<value_type, Alloc>::begin() noexcept {
  iterator it(arr);
  return it;
}

template <typename value_type, typename Alloc>
typename vector<value_type, Alloc>::iterator
vector<value_type, Alloc>::end() noexcept {
  iterator it(arr + sz);
  return it;
}

template <typename value_type, typename Alloc>
typename vector<value_type, Alloc>::const_iterator
vector<value_type, Alloc>::cbegin() const noexcept {
  const_iterator it(arr);
  return it;
}

template <typename value_type, typename Alloc>
typename vector<value_type, Alloc>::const_iterator
vector<value_type, Alloc>::cend() const noexcept {
  const_iterator it(arr + sz);
  return it;
}

template <typename value_type, typename Alloc>
constexpr typename vector<value_type, Alloc>::reference
vector<value_type, Alloc>::operator[](size_type pos) {
  return arr[pos];
}

template <typename value_type, typename Alloc>
constexpr typename vector<value_type, Alloc>::const_reference
vector<value_type, Alloc>::operator[](size_type pos) const {
  return arr[pos];
}

template <typename value_type, typename Alloc>
typename vector<value_type, Alloc>::reference vector<value_type, Alloc>::at(
    size_type pos) {
  if (pos >= sz) throw std::out_of_range("Out of range");
  return arr[pos];
}

template <typename value_type, typename Alloc>
typename vector<value_type, Alloc>::const_reference
vector<value_type, Alloc>::front() const {
  return arr[0b0];
}

template <typename value_type, typename Alloc>
typename vector<value_type, Alloc>::const_reference
vector<value_type, Alloc>::back() const {
  return arr[sz - 1];
}

template <typename value_type, typename Alloc>
value_type* vector<value_type, Alloc>::data() noexcept {
  return arr;
}
template <typename value_type, typename Alloc>
bool vector<value_type, Alloc>::empty() const noexcept {
  return sz ? false : true;
}

template <typename value_type, typename Alloc>
typename vector<value_type, Alloc>::size_type
vector<value_type, Alloc>::max_size() const noexcept {
  return AllocTraits::max_size(alloc);
}

template <typename value_type, typename Alloc>
void vector<value_type, Alloc>::reserve(size_type size) {
  if (size <= cap) return;

  value_type* newarr = AllocTraits::allocate(alloc, size);

  for (size_type i = 0; i < sz; ++i) {
    try {
      AllocTraits::construct(alloc, newarr + i, std::move_if_noexcept(arr[i]));
    } catch (...) {
      for (size_type j = 0; j < i; ++j) {
        AllocTraits::destroy(alloc, newarr + j);
      }
      AllocTraits::deallocate(alloc, newarr, size);
      throw;
    }
  }

  for (size_type i = 0; i < sz; ++i) {
    AllocTraits::destroy(alloc, arr + i);
  }
  AllocTraits::deallocate(alloc, arr, cap);
  cap = size;
  arr = newarr;
}
template <typename value_type, typename Alloc>
void vector<value_type, Alloc>::shrink_to_fit() {
  if (size() < capacity()) {
    value_type* newarr = AllocTraits::allocate(alloc, sz);

    for (size_type i = 0; i < sz; ++i) {
      try {
        AllocTraits::construct(alloc, newarr + i,
                               std::move_if_noexcept(arr[i]));
      } catch (...) {
        for (size_type j = 0; j < i; ++j) {
          AllocTraits::destroy(alloc, newarr + j);
        }
        AllocTraits::deallocate(alloc, newarr, sz);
        throw;
      }
    }
    for (size_type i = 0; i < sz; i++) {
      AllocTraits::destroy(alloc, arr + i);
    }
    AllocTraits::deallocate(alloc, arr, cap);
    cap = sz;
    arr = newarr;
  }
}

template <typename value_type, typename Alloc>
void vector<value_type, Alloc>::clear() noexcept {
  for (size_type i = 0; i < sz; i++) {
    AllocTraits::destroy(alloc, arr + i);
  }
  sz = 0;
}
template <typename value_type, typename Alloc>
void vector<value_type, Alloc>::pop_back() {
  if (sz > 0) {
    --sz;
    AllocTraits::destroy(alloc, arr + sz);
  }
}

template <typename value_type, typename Alloc>
void vector<value_type, Alloc>::push_back(const_reference value) {
  if (cap == 0) {
    reserve(1);
  }
  if (sz >= cap) {
    reserve(cap * 2);
  }
  try {
    AllocTraits::construct(alloc, arr + sz, value);
  } catch (...) {
    AllocTraits::destroy(alloc, arr + sz);
    throw;
  }
  ++sz;
}
template <typename value_type, typename Alloc>
void vector<value_type, Alloc>::push_back(value_type&& value) {
  if (cap == 0) {
    reserve(1);
  }
  if (sz >= cap) {
    reserve(cap * 2);
  }
  try {
    AllocTraits::construct(alloc, arr + sz, std::move_if_noexcept(value));
  } catch (...) {
    AllocTraits::destroy(alloc, arr + sz);
    throw;
  }
  ++sz;
}

template <typename value_type, typename Alloc>
template <typename... Args>
void vector<value_type, Alloc>::emplace_back(Args&&... args) {
  if (cap == 0) {
    reserve(1);
  }
  if (sz >= cap) {
    reserve(cap * 2);
  }
  AllocTraits::construct(alloc, arr + sz, std::forward<Args>(args)...);
  sz++;
}
template <typename value_type, typename Alloc>
typename vector<value_type, Alloc>::size_type vector<value_type, Alloc>::size()
    const noexcept {
  return sz;
}

template <typename value_type, typename Alloc>
typename vector<value_type, Alloc>::size_type
vector<value_type, Alloc>::capacity() const noexcept {
  return cap;
}
template <typename value_type, typename Alloc>
void vector<value_type, Alloc>::erase(iterator pos) {
  AllocTraits::destroy(alloc, pos.getter());
  for (iterator it = pos; it != end() - 1; ++it) {
    *it = *(it + 1);
  }
  --sz;
}

template <typename value_type, typename Alloc>
typename vector<value_type, Alloc>::iterator vector<value_type, Alloc>::insert(
    iterator pos, const_reference value) {
  if (!(pos != end())) {
    push_back(value);
    iterator tmp(arr + sz - 1);
    return tmp;
  }
  size_type pos_in_arr = pos.getter() - arr;
  if (sz == cap) reserve(2 * cap);
  push_back(value);
  for (size_type i = (end() - 1).getter() - arr; i != (pos_in_arr); i--)
    std::swap(arr[i], arr[i - 1]);
  iterator tmp(arr + pos_in_arr);
  return tmp;
}

template <typename value_type, typename Alloc>
void vector<value_type, Alloc>::swap(vector& other) noexcept(
    noexcept(AllocTraits::propagate_on_container_swap::value ||
             AllocTraits::is_always_equal::value)) {
  std::swap(arr, other.arr);
  std::swap(sz, other.sz);
  std::swap(cap, other.cap);
  if (AllocTraits::propagate_on_container_swap::value && alloc != other.alloc) {
    std::swap(alloc, other.alloc);
  }
}

template <typename value_type, typename Alloc>
template <typename... Args>
typename vector<value_type, Alloc>::iterator
vector<value_type, Alloc>::insert_many(const_iterator pos, Args&&... args) {
  vector<value_type> temp{args...};
  iterator cur_pos = begin() + (pos.getter() - begin().getter());
  for (auto i = static_cast<int>(temp.size() - 1); i >= 0; i--) {
    cur_pos = insert(cur_pos, temp.arr[i]);
  }
  return cur_pos;
}
template <typename value_type, typename Alloc>
template <typename... Args>
void vector<value_type, Alloc>::insert_many_back(Args&&... args) {
  insert_many(end(), std::forward<Args>(args)...);
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_S21_VECTOR_H_