//<PROJECT>_<PATH>_<FILE>_H_
#ifndef CPP2_S21_CONTAINERS_SRC_S21_LIST_H_  //
#define CPP2_S21_CONTAINERS_SRC_S21_LIST_H_ 

#include <utility>
#include <memory>
#include <iostream>

namespace s21 { 
template <typename T, typename Alloc = std::allocator<T>>
class list { 

    private:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using size_type =  size_t; 
       struct Node
        {
            Node* next; 
            Node* prev; 
            value_type data;

            Node(): next(nullptr),prev(nullptr) {}
            Node(Node * first, Node * second,const_reference data): next(first),prev(second),data(data) {
            }
        };
   
    //using AllocTraits = std::allocator_traits<rebind_alloc<Node>>;
    public:


        class ListIterator { 
            private: 
                Node * node;
            public:
            ListIterator() =  delete; 
            ListIterator(Node * new_node): node(new_node) {}
            ListIterator(const ListIterator& li) noexcept: node(li.node) {}
            constexpr ListIterator& operator++() noexcept { 
                node = node->next;
                return *this;
            }
            constexpr ListIterator operator++(int) noexcept { 
                ListIterator copy = *this;
                copy.node = node -> next;
                return copy;
            }
             constexpr ListIterator operator--(int) noexcept { 
                ListIterator copy = *this;
                copy.node = node -> prev;
                return copy;
            }
            constexpr ListIterator& operator--() noexcept{ 
                node = node -> prev; 
                return *this;
            }
            reference operator*() noexcept { 
                return node->data;
            }

            Node * getNode() noexcept { 
                return node;
            }

            constexpr bool operator!=(const ListIterator& l) const noexcept {
                return node != l.node;
             }


            constexpr bool operator==(const ListIterator& l) const noexcept {
                return node == l.node;
             }
        };


         class ListConstIterator { 
            private: 
                Node * node;
            public:
            ListConstIterator() =  delete; 
            ListConstIterator(Node * new_node): node(new_node) {}
            ListConstIterator(const ListIterator& li) noexcept: node(li.node) {}
            constexpr ListConstIterator& operator++() noexcept { 
                node = node->next;
                return *this;
            }
            constexpr ListConstIterator& operator--()  noexcept{ 
                node = node -> prev; 
                return *this;
            }
            const_reference operator*() const noexcept { 
                return node->data;
            }

            Node * getNode() noexcept { 
                return node;
            }

            constexpr bool operator!=(const ListConstIterator& l) const noexcept {
                return node != l.node;
             }


            constexpr bool operator==(const ListConstIterator& l) const noexcept {
                return node == l.node;
             }
        };

            ListIterator begin() noexcept { 
                return ListIterator(head->next); 
            } 
            ListIterator end() noexcept { 
                return ListIterator(head);
            }

            ListConstIterator cbegin() const noexcept { 
                return ListConstIterator(head->next) ;
            } 
            ListConstIterator cend() const noexcept { 
                return ListConstIterator(head);
            }

            constexpr const_reference front() const {
                 return head->next->data; 
            }
            constexpr const_reference back() const { 
                return head->prev->data;
            }

            constexpr bool empty() const noexcept { 
                return sz == 0 ? true : false;
            }

            constexpr size_type size() const noexcept {
                return sz;
            }
            constexpr size_type max_size() const noexcept { 
                return AllocTraits::max_size(alloc);
            }

            void clear() noexcept { 
                while (sz) erase(begin());
            }

            ListIterator insert(ListIterator pos, const_reference value) { 
                Node * node = AllocTraits::allocate(alloc,1);
                try {
                    AllocTraits::construct(alloc,node,node,node,value);
                } catch (...) { 
                    AllocTraits::deallocate(alloc,node,1);
                    throw;
                }
                Node * cur = pos.getNode();
                node -> next = cur; 
                cur -> prev -> next = node;
                node -> prev = cur -> prev;
                cur -> prev = node;
                sz++;
                return ListIterator(node);
            }
        void push_back(const_reference value) { 
                insert(end(),value);
        }

        void push_front(const_reference value) { 
            insert(begin(),value);
        }
        void pop_back() {
            if (head -> prev) 
                erase(--end());
        }
        void pop_front() { 
            erase(begin());
        }

        void reverse() noexcept { 
            size_type step = 0;
        for (auto it = this->begin(); step <= this->size(); ++it) {
              step++;
             std::swap((it.getNode())->prev, (it.getNode())->next);
        }
        }


        void splice(ListConstIterator pos, list& other) { 
            Node * cur_other_begin = other.cbegin().getNode();
            Node * cur_other_end = (--other.cend()).getNode();
            cur_other_end -> next = pos.getNode(); 
            pos.getNode() -> prev -> next = cur_other_begin;
            cur_other_begin->prev = pos.getNode()->prev; 
            pos.getNode()->prev = cur_other_end; 
            (other.cend()).getNode() -> next = other.head;
            (other.cend()).getNode() -> prev = other.head;
            sz += other.sz;
            other.sz = 0; 
        }

        void swap(list& other) noexcept(noexcept(AllocTraits::is_always_equal::value)) { 
            std::swap(head,other.head);
            std::swap(sz,other.sz);
            if (AllocTraits::propagate_on_container_swap::value && alloc != other.alloc) 
                std::swap(alloc,other.alloc);
        }
        
        void unique() {
            if (empty()) return;
            for (auto it = begin(); it != end() && it.getNode() -> next != head; ++it) { 
                if (it.getNode()->data == (it).getNode()->next->data) {
                    auto it_del = it++;
                    erase(it_del);
                }
            }
        }

        template <typename... Args>
        ListConstIterator insert_many(ListConstIterator pos, Args&&... args) { 
            list<value_type> temp {args...};
             splice(pos,temp);
            return ListConstIterator(cbegin().getNode());
        }

        template <typename... Args>
        void insert_many_back(Args&&... args) { 
            insert_many(cend(),std::forward<Args>(args)...);
        }
        template <typename... Args>
        void insert_many_front(Args&&... args) { 
            insert_many(cbegin(),std::forward<Args>(args)...);
        }

        void merge(list& other) {
            auto it_other = other.begin();
             for (auto it = begin(); it != end() && it_other != other.end();) { 
                if (*it_other < *it) {
                    Node * cur = it.getNode();
                    Node * cur_adding = it_other.getNode();
                    ++it_other;
                    other.sz--;
                    ++sz;
                    cur -> prev -> next = cur_adding;
                    cur_adding -> prev = cur -> prev;
                    cur -> prev = cur_adding; 
                    cur_adding -> next = cur;
                } else ++it;
             }
                while(it_other != other.end()) {
                    Node * cur = end().getNode(); 
                    Node * cur_adding = it_other.getNode();
                                        ++it_other;
                                        other.sz--;
                    ++sz;
                    cur -> prev -> next = cur_adding;
                    cur_adding -> prev = cur -> prev;
                    cur -> prev = cur_adding; 
                    cur_adding -> next = cur;
                }
        }


        void sort() { 
            auto it_end = end();
            while (--it_end != head ) { 
                bool swapped = false;
                    for (auto it = begin(); it != it_end; ++it) { 
                            Node * cur = it.getNode();
                            Node * cur_next = cur->next;
                            if (cur->data > cur_next -> data)  {
                            cur -> prev -> next = cur_next; 
                            cur_next -> next -> prev = cur;
                            cur_next -> prev = cur -> prev; 
                            cur -> next = cur_next -> next; 
                            cur -> prev = cur_next;
                            cur_next -> next = cur; 
                            swapped = true;
                            it = ++begin();
                        }
                    }
                    if (swapped == false) 
                        return;
            }
        }



        void erase(ListIterator pos) noexcept { 
            if (pos == end()) return;
            Node * cur = pos.getNode();
            cur -> prev -> next = cur -> next;
            cur -> next -> prev = cur -> prev;
            AllocTraits::destroy(alloc,cur);
            AllocTraits::deallocate(alloc,cur,1);
            --sz;
        }
        explicit list(const Alloc& alloc = Alloc()): head(nullptr),alloc(alloc),sz(0) {
        head = AllocTraits::allocate(this->alloc,1);
        AllocTraits::construct(this->alloc,head);
        head -> next = head;
        head -> prev = head;
        }

        ~list() { 
            while (sz) erase(begin());
            AllocTraits::deallocate(alloc,head,1);
        }

    // explicit list(): head(nullptr),alloc(Alloc()),sz(0) {
    //     head = AllocTraits::allocate(alloc,1);
    //     AllocTraits::construct(alloc,head);
    // }
    explicit list(size_type n): list() { 
        Node * cur_node = head;
        for (size_type i = 0; i < n; ++i) { 
            Node * node = AllocTraits::allocate(alloc,1);
            AllocTraits::construct(alloc,node,node,node);
            cur_node -> next = node;
            node -> prev = cur_node;
            cur_node = node;
            ++sz;
        }
        cur_node -> next = head; 
        head -> prev = cur_node;
    }

    explicit list(std::initializer_list<value_type> const &items): list() { 
        Node * cur_node = head; 
        for (size_type i = 0; i < items.size(); ++i) { 
            Node * node = AllocTraits::allocate(alloc,1);
                AllocTraits::construct(alloc,node,node,node,*(items.begin() + i));
            cur_node -> next = node;
            node -> prev = cur_node;
            cur_node = node;
            ++sz;
        }
        cur_node -> next = head; 
        head->prev = cur_node;
    }

    list(const list &l) : list(std::allocator_traits<Alloc>::select_on_container_copy_construction(l.alloc)) {
        for (auto it = l.cbegin(); it != l.cend(); ++it) { 
            push_back(*it);
        }
    }

    list(list &&l) noexcept(noexcept(alloc(std::move(l.alloc)))) {
        if (AllocTraits::propagate_on_container_move_assignment(l.alloc)) {
            alloc = std::move(l.alloc);
        } 
        head = l.head;
        l.head = nullptr;
        l.sz = 0;
    }

    list operator=(list &&l) noexcept(noexcept(alloc = std::move(l.alloc))) { 
        if (AllocTraits::propagate_on_container_move_assignment(l.alloc)) {
            alloc = std::move(l.alloc);
        } 
        head = l.head;
        l.head = nullptr;
        l.sz = 0;
        return *this;
    }



    void print_data() { 
        if (!sz) return;
        head = head -> next; 
        for ( size_type i =0 ; i < sz ; i++)
         {
            std::cout << i << " " << head->data << "\n";
            head = head -> next; 
         }
    };



    private: 

    // ---поля листe

        Node * head;
        typename Alloc::template rebind<Node>::other alloc; 
        size_type sz;

        // ----- поля листа

     using AllocTraits = std::allocator_traits< typename std::allocator_traits<Alloc>::template rebind_alloc<Node>>;

};



} // namespace s21
#endif //CPP2_S21_CONTAINERS_SRC_S21_LIST_H_ 
