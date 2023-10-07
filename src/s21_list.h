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

            ListIterator begin() noexcept { 
                return ListIterator(head->next); 
            } 
            ListIterator end() noexcept { 
                return ListIterator(head);
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
                if (sz) {
                Node * cur = pos.getNode();
                node -> next = cur; 
                cur -> prev -> next = node;
                cur -> prev = node;
                node -> prev = cur -> prev;
                } else { 
                head -> next = node;
                head -> prev = node;
                node -> next = head;
                node -> prev = head;
                }
                sz++;
                return ListIterator(node);
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
        }

        ~list() { 
            Node * cur = head -> next;
            for (size_type i = 0; i < sz; i++) { 
                Node * del = cur;
                AllocTraits::destroy(alloc,del);
                cur = cur -> next;
                AllocTraits::deallocate(alloc,del,1);
            }
            AllocTraits::deallocate(alloc,cur,1);
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
        Node * cur_node = head;
        Node * cur_node_copy = l.head -> next; 
        for (size_type i = 0; i < l.sz; i++) {
            Node * node =  AllocTraits::allocate(alloc,1);
            AllocTraits::construct(alloc,node,node,node,cur_node_copy->data);
            cur_node ->next = node;
            node->prev = cur_node;
            cur_node = node;
            cur_node_copy = cur_node_copy-> next;
        } 
        sz = l.sz;
        cur_node -> next = head; 
        head -> prev = cur_node;
    }

    list(list &&l) noexcept(noexcept(alloc(std::move(l.alloc)))) {
        if (AllocTraits::propagate_on_container_move_assignment(l.alloc)) {
            alloc = std::move(l.alloc);
        } 

        // TODO:: insert elem
        l.head = nullptr;
        l.sz = 0;
    }

    list operator=(list &&l) noexcept(noexcept(alloc = std::move(l.alloc))) { 
        if (AllocTraits::propagate_on_container_move_assignment(l.alloc)) {
            alloc = std::move(l.alloc);
        } 
        // TODO:: insert elem
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
