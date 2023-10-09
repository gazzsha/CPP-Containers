//<PROJECT>_<PATH>_<FILE>_H_
#ifndef CPP2_S21_CONTAINERS_SRC_S21_LIST_H_  //
#define CPP2_S21_CONTAINERS_SRC_S21_LIST_H_

#include <iostream>
#include <memory>
#include <utility>

namespace s21 {
template <typename T, typename Alloc = std::allocator<T>>
class list {
 private:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;
  struct Node {
    Node* next;
    Node* prev;
    value_type data;
    Node() : next(nullptr), prev(nullptr), data(T()) {}
    Node(Node* first, Node* second, const_reference data)
        : next(first), prev(second), data(data) {}
  };

 public:
  template <typename U, typename X>
  class ListIterator {
   public:
    ListIterator() : node(nullptr) {}
    ListIterator(Node* new_node) : node(new_node) {}
    ListIterator(const ListIterator<U, X>& li) noexcept : node(li.node) {}
    ListIterator& operator++() noexcept {
      node = node->next;
      return *this;
    }
    ListIterator operator++(int) noexcept {
      ListIterator copy = *this;
      copy.node = node->next;
      return copy;
    }
    ListIterator operator--(int) noexcept {
      ListIterator copy = *this;
      copy.node = node->prev;
      return copy;
    }
    ListIterator& operator--() noexcept {
      node = node->prev;
      return *this;
    }
    reference operator*() noexcept { return node->data; }
    Node* getNode() noexcept { return node; }
    bool operator!=(const ListIterator& l) const noexcept {
      return node != l.node;
    }
    ListIterator& operator=(const ListIterator& l) {
      node = l.node;
      return *this;
    }
    bool operator==(const ListIterator& l) const noexcept {
      return node == l.node;
    }

   private:
    Node* node;
    friend class list<T>;
  };

  template <typename Y, typename Z>
  class ListConstIterator {
   public:
    ListConstIterator() : node(nullptr) {}
    ListConstIterator(const ListIterator<Y, Z>& other) : node(other.node) {}
    ListConstIterator(Node* new_node) : node(new_node) {}
    ListConstIterator& operator++() noexcept {
      node = node->next;
      return *this;
    }
    ListConstIterator& operator--() noexcept {
      node = node->prev;
      return *this;
    }
    const_reference operator*() const noexcept { return node->data; }
    Node* getNode() noexcept { return node; }
    bool operator!=(const ListConstIterator& l) const noexcept {
      return node != l.node;
    }
    bool operator==(const ListConstIterator& l) const noexcept {
      return node == l.node;
    }

   private:
    Node* node;
    friend class list<T>;
  };
  using iterator = ListIterator<T, Alloc>;
  using const_iterator = ListConstIterator<T, Alloc>;
  explicit list(const Alloc& alloc = Alloc());
  explicit list(size_type n);
  explicit list(std::initializer_list<value_type> const& items);
  list(const list& l);
  list(list&& l) noexcept(noexcept(alloc = std::move(l.alloc)));
  list& operator=(list&& l) noexcept(noexcept(alloc = std::move(l.alloc)));
  ~list();
  iterator begin() noexcept;
  iterator end() noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;
  const_reference front() const;
  const_reference back() const;
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;
  void clear() noexcept;
  iterator insert(iterator pos, const_reference value);
  void push_back(const_reference value);
  void push_front(const_reference value);
  void pop_back();
  void pop_front();
  void reverse() noexcept;
  void splice(const_iterator pos, list& other);
  void swap(list& other) noexcept(
      noexcept(AllocTraits::is_always_equal::value));
  void unique();
  template <typename... Args>
  const_iterator insert_many(const_iterator pos, Args&&... args);
  template <typename... Args>
  void insert_many_back(Args&&... args);
  template <typename... Args>
  void insert_many_front(Args&&... args);
  void merge(list& other);
  void sort();
  void erase(iterator pos) noexcept;
  //   void print_data() {
  //     if (!sz) return;
  //     head = head->next;
  //     for (size_type i = 0; i < sz; i++) {
  //       std::cout << i << " " << head->data << "\n";
  //       head = head->next;
  //     }
 private:
  Node* head;
  typename Alloc::template rebind<Node>::other alloc;
  size_type sz;
  using AllocTraits = std::allocator_traits<
      typename std::allocator_traits<Alloc>::template rebind_alloc<Node>>;
};

template <typename T, typename Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::begin() noexcept {
  return iterator(head->next);
}
template <typename T, typename Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::end() noexcept {
  return iterator(head);
}
template <typename T, typename Alloc>
typename list<T, Alloc>::const_iterator list<T, Alloc>::cbegin()
    const noexcept {
  return const_iterator(head->next);
}
template <typename T, typename Alloc>
typename list<T, Alloc>::const_iterator list<T, Alloc>::cend() const noexcept {
  return const_iterator(head);
}
template <typename T, typename Alloc>
typename list<T, Alloc>::const_reference list<T, Alloc>::front() const {
  return head->next->data;
}
template <typename T, typename Alloc>
typename list<T, Alloc>::const_reference list<T, Alloc>::back() const {
  return head->prev->data;
}
template <typename T, typename Alloc>
bool list<T, Alloc>::empty() const noexcept {
  return sz == 0 ? true : false;
}
template <typename T, typename Alloc>
typename list<T, Alloc>::size_type list<T, Alloc>::size() const noexcept {
  return sz;
}
template <typename T, typename Alloc>
typename list<T, Alloc>::size_type list<T, Alloc>::max_size() const noexcept {
  return AllocTraits::max_size(alloc);
}
template <typename T, typename Alloc>
void list<T, Alloc>::clear() noexcept {
  while (sz) erase(begin());
}

template <typename T, typename Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::insert(
    iterator pos, const_reference value) {
  Node* node = AllocTraits::allocate(alloc, 1);
  try {
    AllocTraits::construct(alloc, node, node, node, value);
  } catch (...) {
    AllocTraits::deallocate(alloc, node, 1);
    throw;
  }
  Node* cur = pos.getNode();
  node->next = cur;
  cur->prev->next = node;
  node->prev = cur->prev;
  cur->prev = node;
  sz++;
  return iterator(node);
}
template <typename T, typename Alloc>
void list<T, Alloc>::push_back(const_reference value) {
  insert(end(), value);
}
template <typename T, typename Alloc>
void list<T, Alloc>::push_front(const_reference value) {
  insert(begin(), value);
}

template <typename T, typename Alloc>
void list<T, Alloc>::pop_back() {
  if (head->prev) erase(--end());
}
template <typename T, typename Alloc>
void list<T, Alloc>::pop_front() {
  erase(begin());
}

template <typename T, typename Alloc>
void list<T, Alloc>::reverse() noexcept {
  size_type step = 0;
  for (auto it = this->begin(); step <= this->size(); ++it) {
    step++;
    std::swap((it.getNode())->prev, (it.getNode())->next);
  }
}

template <typename T, typename Alloc>
void list<T, Alloc>::splice(const_iterator pos, list& other) {
  if (!other.sz) return;
  Node* cur_other_begin = other.cbegin().getNode();
  Node* cur_other_end = (--other.cend()).getNode();
  cur_other_end->next = pos.getNode();
  pos.getNode()->prev->next = cur_other_begin;
  cur_other_begin->prev = pos.getNode()->prev;
  pos.getNode()->prev = cur_other_end;
  (other.cend()).getNode()->next = other.head;
  (other.cend()).getNode()->prev = other.head;
  sz += other.sz;
  other.sz = 0;
}

template <typename T, typename Alloc>
void list<T, Alloc>::swap(list& other) noexcept(
    noexcept(AllocTraits::is_always_equal::value)) {
  std::swap(head, other.head);
  std::swap(sz, other.sz);
  if (AllocTraits::propagate_on_container_swap::value && alloc != other.alloc)
    std::swap(alloc, other.alloc);
}

template <typename T, typename Alloc>
void list<T, Alloc>::unique() {
  if (empty()) return;
  for (auto it = begin(); it.getNode()->next != head;) {
    if (it.getNode()->data == (it).getNode()->next->data) {
      auto it_del = it++;
      erase(it_del);
      it = ++begin();
    }
    ++it;
  }
}

template <typename T, typename Alloc>
void list<T, Alloc>::merge(list& other) {
  auto it_other = other.begin();
  for (auto it = begin(); it != end() && it_other != other.end();) {
    if (*it_other < *it) {
      Node* cur = it.getNode();
      Node* cur_adding = it_other.getNode();
      ++it_other;
      other.sz--;
      ++sz;
      cur->prev->next = cur_adding;
      cur_adding->prev = cur->prev;
      cur->prev = cur_adding;
      cur_adding->next = cur;
    } else
      ++it;
  }
  while (it_other != other.end()) {
    Node* cur = end().getNode();
    Node* cur_adding = it_other.getNode();
    ++it_other;
    other.sz--;
    ++sz;
    cur->prev->next = cur_adding;
    cur_adding->prev = cur->prev;
    cur->prev = cur_adding;
    cur_adding->next = cur;
  }
}
template <typename T, typename Alloc>
void list<T, Alloc>::sort() {
  auto it_end = end();
  while (--it_end != head) {
    bool swapped = false;
    for (auto it = begin(); it != it_end; ++it) {
      Node* cur = it.getNode();
      Node* cur_next = cur->next;
      if (cur->data > cur_next->data) {
        cur->prev->next = cur_next;
        cur_next->next->prev = cur;
        cur_next->prev = cur->prev;
        cur->next = cur_next->next;
        cur->prev = cur_next;
        cur_next->next = cur;
        swapped = true;
        it = ++begin();
      }
    }
    if (swapped == false) return;
  }
}
template <typename T, typename Alloc>
void list<T, Alloc>::erase(iterator pos) noexcept {
  if (pos == end()) return;
  Node* cur = pos.getNode();
  cur->prev->next = cur->next;
  cur->next->prev = cur->prev;
  AllocTraits::destroy(alloc, cur);
  AllocTraits::deallocate(alloc, cur, 1);
  --sz;
}
template <typename T, typename Alloc>
list<T, Alloc>::list(const Alloc& alloc) : head(nullptr), alloc(alloc), sz(0) {
  head = AllocTraits::allocate(this->alloc, 1);
  AllocTraits::construct(this->alloc, head);
  head->next = head;
  head->prev = head;
}
template <typename T, typename Alloc>
list<T, Alloc>::~list() {
  while (sz) erase(begin());
  AllocTraits::deallocate(alloc, head, 1);
}

template <typename T, typename Alloc>
list<T, Alloc>::list(size_type n) : list() {
  head->next = head;
  head->prev = head;
  Node* cur_node = head;
  for (size_type i = 0; i < n; ++i) {
    Node* node = AllocTraits::allocate(alloc, 1);
    AllocTraits::construct(alloc, node);
    cur_node->next = node;
    node->prev = cur_node;
    cur_node = node;
    ++sz;
  }
  cur_node->next = head;
  head->prev = cur_node;
  head->data = sz;
}

template <typename T, typename Alloc>
list<T, Alloc>::list(std::initializer_list<value_type> const& items) : list() {
  Node* cur_node = head;
  for (size_type i = 0; i < items.size(); ++i) {
    Node* node = AllocTraits::allocate(alloc, 1);
    AllocTraits::construct(alloc, node, node, node, *(items.begin() + i));
    cur_node->next = node;
    node->prev = cur_node;
    cur_node = node;
    ++sz;
  }
  cur_node->next = head;
  head->prev = cur_node;
}
template <typename T, typename Alloc>
list<T, Alloc>::list(const list& l)
    : list(std::allocator_traits<Alloc>::select_on_container_copy_construction(
          l.alloc)) {
  for (auto it = l.cbegin(); it != l.cend(); ++it) {
    push_back(*it);
  }
}

template <typename T, typename Alloc>
list<T, Alloc>::list(list&& l) noexcept(noexcept(alloc = std::move(l.alloc))) {
  if (AllocTraits::propagate_on_container_move_assignment::value) {
    alloc = (std::move(l.alloc));
  }
  head = l.head;
  sz = l.sz;
  l.head = nullptr;
  l.sz = 0;
}
template <typename T, typename Alloc>
list<T, Alloc>& list<T, Alloc>::operator=(list&& l) noexcept(
    noexcept(alloc = std::move(l.alloc))) {
  clear();
  if (AllocTraits::propagate_on_container_move_assignment::value) {
    alloc = std::move(l.alloc);
  }
  swap(l);
  return *this;
}

template <typename T, typename Alloc>
template <typename... Args>
typename list<T, Alloc>::const_iterator list<T, Alloc>::insert_many(
    const_iterator pos, Args&&... args) {
  list<value_type> temp{args...};
  splice(pos, temp);
  return const_iterator(cbegin().getNode());
}
template <typename T, typename Alloc>
template <typename... Args>
void list<T, Alloc>::insert_many_back(Args&&... args) {
  insert_many(cend(), std::forward<Args>(args)...);
}
template <typename T, typename Alloc>
template <typename... Args>
void list<T, Alloc>::insert_many_front(Args&&... args) {
  insert_many(cbegin(), std::forward<Args>(args)...);
}

}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_SRC_S21_LIST_H_
