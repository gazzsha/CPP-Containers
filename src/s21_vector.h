#include <iostream> 
#include <vector>
#include <memory>
#include <utility>
#include <string>
#include <cmath>


template <typename T, typename Alloc = std::allocator<T>>
class s21_vector { 
    private:
    Alloc alloc;
    T* arr;
    size_t sz;
    size_t cap;
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using size_type = size_t; 
    using AllocTraits = std::allocator_traits<Alloc>;
public:

    class iterator { 
    private:
        T* ptr;
    public: 
        // constuction 
        constexpr iterator() noexcept;
        explicit iterator (T* new_ptr) noexcept; 
        T& operator*() const noexcept;
        T* getter() const noexcept;
        // operators
        iterator operator++() noexcept;
        iterator operator--() noexcept;    
        iterator operator-(const size_type& ind) noexcept;  
        iterator operator+(const size_type& ind) noexcept;
        constexpr bool operator !=(const iterator& other) noexcept;
    };
    constexpr iterator begin() noexcept;
    constexpr iterator end() noexcept;
    s21_vector() noexcept; 
    s21_vector(size_type n);
    s21_vector(const s21_vector &v);
    s21_vector(std::initializer_list<value_type> const &items);
    s21_vector(s21_vector &&v) noexcept(noexcept(alloc(std::move(v.alloc))));
    ~s21_vector();
    reference operator=(s21_vector &&v) noexcept(noexcept(alloc(std::move(v.alloc))));
    constexpr reference operator[](size_type pos);
    constexpr reference at(size_type pos);
    constexpr const_reference front();
    constexpr const_reference back();
    T* data();
    constexpr bool empty() noexcept;
    constexpr size_type max_size() const noexcept;
    void reserve(size_type size);
    void shrink_to_fit();
    void clear() noexcept;
    void pop_back();
    void push_back(const_reference value);
    void push_back(T&& value);
    template <typename... Args>
    void emplace_back(Args&&... args);
    size_type size() const noexcept;
    size_type capacity() const noexcept;
    void erase(iterator pos);
    iterator insert(iterator pos, const_reference value);
    void swap(s21_vector& other) noexcept(noexcept(AllocTraits::propagate_on_container_swap::value
    || AllocTraits::is_always_equal::value));
    template <typename... Args>
    iterator insert_many(iterator pos, Args&&... args);
    template <typename... Args>
    void insert_many_back(Args&&... args);
};

template <typename T, typename Alloc = std::allocator<T>>
constexpr s21_vector<T,Alloc>::iterator::iterator() noexcept: ptr(nullptr) {};


template <typename T, typename Alloc = std::allocator<T>>
s21_vector<T,Alloc>::iterator::iterator(T* new_ptr) noexcept: ptr(new_ptr) {};


template <typename T, typename Alloc = std::allocator<T>>
T& s21_vector<T,Alloc>::iterator::operator*() const noexcept { 
    return *ptr;
}

template <typename T, typename Alloc = std::allocator<T>>
T* s21_vector<T,Alloc>::iterator::getter() const noexcept { 
            return ptr;
        } 
template <typename T, typename Alloc = std::allocator<T>>
typename s21_vector<T,Alloc>::iterator s21_vector<T,Alloc>::iterator::operator++() noexcept { 
    iterator tmp (++ptr);
    return tmp; 
}

template <typename T, typename Alloc = std::allocator<T>>
typename s21_vector<T,Alloc>::iterator s21_vector<T,Alloc>::iterator::operator--() noexcept { 
        iterator tmp (--ptr);
        return tmp; 
}

template <typename T, typename Alloc = std::allocator<T>>
typename s21_vector<T,Alloc>::iterator s21_vector<T,Alloc>::iterator::operator-(const size_type& ind) noexcept {
        iterator tmp (ptr - ind);
        return tmp;
}

template <typename T, typename Alloc = std::allocator<T>>
typename s21_vector<T,Alloc>::iterator s21_vector<T,Alloc>::iterator::operator+(const size_type& ind) noexcept {
        iterator tmp (ptr + ind);
        return tmp;
}

template <typename T, typename Alloc = std::allocator<T>>
constexpr bool  s21_vector<T,Alloc>::iterator::operator!=(const iterator& other) noexcept{
        return ptr != other.ptr;
}


template <typename T, typename Alloc>
s21_vector<T,Alloc>::s21_vector() noexcept : arr(nullptr),sz(0),cap(0) {}


template <typename T, typename Alloc>
s21_vector<T,Alloc>::s21_vector(size_type n): alloc(Alloc()),arr(AllocTraits::allocate(alloc,n)), sz(n),cap(n) {
        for (size_t i = 0; i < sz; ++i)
            try { 
                AllocTraits::construct(alloc, arr+i,T());
            } catch(...) { 
                for (size_type j = 0; j < i; ++j) { 
                    AllocTraits::destroy(alloc,arr + j);
                }
                AllocTraits::deallocate(alloc,arr,cap);
                throw;
            }
    }

template <typename T, typename Alloc>
s21_vector<T,Alloc>::s21_vector(const s21_vector &v): alloc(AllocTraits::select_on_container_copy_construction(v.alloc)),arr(AllocTraits::allocate(alloc,v.cap)), sz(v.sz),cap(v.cap) { 
        for (size_type i = 0; i < sz; ++i) { 
            try { 
                AllocTraits::construct(alloc, arr + i, std::move_if_noexcept(v.arr[i]));
            } 
            catch (...) { 
                for (size_type j = 0; j < i; ++i) { 
                    AllocTraits::destroy(alloc,arr + j);
                }
                AllocTraits::deallocate(alloc,arr,cap);
                throw;
            }
        }
    }

template <typename T, typename Alloc>
s21_vector<T,Alloc>::s21_vector(std::initializer_list<value_type> const &items): s21_vector(items.size()) {
        for (size_type i = 0; i < sz; ++i) { 
            arr[i] = *(items.begin() + i);
        }
}

template <typename T, typename Alloc>
s21_vector<T,Alloc>::s21_vector(s21_vector &&v) noexcept(noexcept(alloc(std::move(v.alloc)))) : arr(v.arr),sz(v.size),cap(v.cap) { 
            if (AllocTraits::propagate_on_container_move_assignment::value) { 
                alloc(std::move(v.alloc));
            }
            v.sz = 0; 
            v.cap = 0; 
            v.arr = nullptr; 
        }

template <typename T, typename Alloc>
s21_vector<T,Alloc>::~s21_vector() { 
        for (size_type i = 0; i < sz; i++) { 
            AllocTraits::destroy(alloc,arr + i);
        }
        AllocTraits::deallocate(alloc, arr, cap);
    }

template <typename T, typename Alloc>
typename s21_vector<T,Alloc>::reference s21_vector<T,Alloc>::operator=(s21_vector &&v) noexcept(noexcept(alloc(std::move(v.alloc)))) { 
        arr = v.arr; 
        sz = v.size;
        cap = v.cap; 
        alloc = std::move(v.alloc);
        v.arr = nullptr;
        v.sz = 0;
        v.cap = 0; 
        return *this;
    }

template <typename T,typename Alloc>
constexpr typename s21_vector<T,Alloc>::reference s21_vector<T,Alloc>::at(size_type pos) { 
        if (pos > size())
            throw std::out_of_range("Out of range");
        return arr[pos];
    }

template <typename T,typename Alloc>
constexpr typename s21_vector<T,Alloc>::reference s21_vector<T,Alloc>::operator[](size_type pos) { 
        return arr[pos];
}

template <typename T,typename Alloc>
constexpr typename s21_vector<T,Alloc>::const_reference s21_vector<T,Alloc>::front() {
        return arr[0b0];
    }


template <typename T,typename Alloc>
constexpr typename s21_vector<T,Alloc>::const_reference s21_vector<T,Alloc>::back() { 
        return arr[sz - 1];
    }

template <typename T,typename Alloc>
     T* s21_vector<T,Alloc>::data() { 
        return arr;
    }
template <typename T,typename Alloc>
constexpr bool s21_vector<T,Alloc>::empty() noexcept { 
    return !(begin() != end());
}

template <typename T,typename Alloc>
    constexpr typename s21_vector<T,Alloc>::size_type s21_vector<T,Alloc>::max_size() const noexcept { 
        return static_cast<size_type>((std::pow(2,63)))/sizeof(T) - 1;
    }

template <typename T,typename Alloc>
        void  s21_vector<T,Alloc>::reserve(size_type size) { 
        if (size <= cap) return;

        T* newarr = AllocTraits::allocate(alloc,size);

        for (size_type i = 0; i < sz; ++i) { 
            try { 
                AllocTraits::construct(alloc,newarr + i,std::move_if_noexcept(arr[i]));
            }
            catch (...) { 
                for (size_type j = 0; j < i; ++j) { 
                    AllocTraits::destroy(alloc,newarr + j);
                }
                AllocTraits::deallocate(alloc,newarr,size);
                throw; 
            }
        }

        for (size_type i = 0; i < sz; ++i) { 
            AllocTraits::destroy(alloc,arr + i);
        }
        AllocTraits::deallocate(alloc,arr,cap);
        cap = size;
        arr = newarr; 
    }
template <typename T,typename Alloc>
    void s21_vector<T,Alloc>::shrink_to_fit() { 
        if ( size() < capacity() ) { 
            T* newarr = AllocTraits::allocate(alloc,sz);

            for (size_type i = 0; i < sz; ++i) { 
                try { 
                    AllocTraits::construct(alloc,newarr + i, std::move_if_noexcept(arr[i]));
                } catch (...) { 
                    for (size_type j = 0; j < i; ++j) { 
                        AllocTraits::destroy(alloc,newarr + j);
                    }
                    AllocTraits::deallocate(alloc,newarr,sz);
                    throw;
                }
            }
            for (size_type i = 0; i < sz; i++) { 
                AllocTraits::destroy(alloc,arr+i);
            }
            AllocTraits::deallocate(alloc,arr,cap);
            cap = sz;
            arr = newarr;
        } 
    }

template <typename T,typename Alloc>
    void s21_vector<T,Alloc>::clear() noexcept { 
        for (size_type i = 0; i < sz; i++) { 
            AllocTraits::destroy(alloc,arr+i);
        }
        sz = 0; 
    }
template <typename T,typename Alloc>
        void s21_vector<T,Alloc>::pop_back()  { 
        --sz; 
        AllocTraits::destroy(alloc,arr + sz);
    }

template <typename T,typename Alloc>
    void s21_vector<T,Alloc>::push_back(const_reference value) { 
         if (cap == 0) { reserve(1);}
         if (sz >= cap) { 
            reserve(cap*2);
        }
        try { 
            AllocTraits::construct(alloc,arr+sz,value);
        } catch (...) { 
            AllocTraits::destroy(alloc,arr+sz);
        }
        ++sz;
    }
template <typename T,typename Alloc>
    void  s21_vector<T,Alloc>::push_back(T&& value) { 
        if (cap == 0) { reserve(1);}
         if (sz >= cap) { 
            reserve(cap*2);
        }
        try { 
            AllocTraits::construct(alloc,arr+sz,std::move_if_noexcept(value));
        } catch (...) { 
            AllocTraits::destroy(alloc,arr+sz);
        }
        ++sz;
    }

template <typename T,typename Alloc>
template <typename... Args>
    void s21_vector<T,Alloc>::emplace_back(Args&&... args) { 
         if (cap == 0) { reserve(1);}
        if (sz >= cap) { 
            reserve(cap*2);
        }
        AllocTraits::construct(alloc,arr + sz, std::forward<Args>(args)...);
        sz++;
    }
template <typename T,typename Alloc>
typename s21_vector<T,Alloc>::size_type s21_vector<T,Alloc>::size() const noexcept {
        return sz;  
    }

template <typename T,typename Alloc>
typename s21_vector<T,Alloc>::size_type s21_vector<T,Alloc>::capacity() const noexcept { 
        return cap;
    }
template <typename T,typename Alloc>
    void s21_vector<T,Alloc>::erase(iterator pos) { 
       AllocTraits::destroy(alloc,pos.getter());
        for (iterator it = pos; it != end() - 1; ++it) { 
            *it = *(it + 1);
        }
        --sz;
    }

template <typename T,typename Alloc>
typename s21_vector<T,Alloc>::iterator s21_vector<T,Alloc>::insert(iterator pos, const_reference value) { 
        if (!(pos != end())) { 
            push_back(value);
            iterator tmp(arr + sz - 1);
            return tmp;
        }
        size_type pos_in_arr = pos.getter() - arr;
        if (sz == cap) reserve(2*cap);
        push_back(value);
        for (size_type i = (end() - 1).getter() - arr; i != (pos_in_arr); i--)
        std::swap(arr[i],arr[i-1]);
        iterator tmp(arr+pos_in_arr);
        return tmp;
    }

template <typename T,typename Alloc>
     void s21_vector<T,Alloc>::swap(s21_vector& other) noexcept(noexcept(AllocTraits::propagate_on_container_swap::value
    || AllocTraits::is_always_equal::value)) { 
        std::swap(arr,other.arr);
        std::swap(sz,other.sz);
        std::swap(cap,other.cap);
        if (AllocTraits::propagate_on_container_swap::value && alloc != other.allloc) { 
            std::swap(alloc,other.alloc);
        }
    }


template <typename T,typename Alloc>    
template <typename... Args>
typename s21_vector<T,Alloc>::iterator s21_vector<T,Alloc>::insert_many(iterator pos, Args&&... args) { 
        s21_vector<T> temp {args...};
       for (auto i = static_cast<int>(temp.size() - 1);  i >= 0; i--) { 
            insert(pos,temp.arr[i]);
       }
        iterator tmp = begin();
    return tmp;
    }
template <typename T,typename Alloc>    
template <typename... Args>
void s21_vector<T,Alloc>::insert_many_back(Args&&... args) { 
        insert_many(end(),(args)...);
    }

template <typename T,typename Alloc>    
constexpr typename s21_vector<T,Alloc>::iterator s21_vector<T,Alloc>::begin() noexcept { 
        iterator it(arr);
        return it;
    }
template <typename T,typename Alloc>    

constexpr typename s21_vector<T,Alloc>::iterator s21_vector<T,Alloc>::end() noexcept { 
        iterator it(arr + sz);
        return it; 
    }