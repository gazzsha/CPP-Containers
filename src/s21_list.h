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

        explicit list(const Alloc& alloc = Alloc()): head(nullptr),alloc(alloc),sz(0) {
        head = AllocTraits::allocate(this->alloc,1);
        AllocTraits::construct(this->alloc,head);
        }

        ~list() { 
            Node * cur = head -> next;
            for (size_type i = 0; i < sz; i++) { 
                Node * del = cur;
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

    void print_data() { 
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
