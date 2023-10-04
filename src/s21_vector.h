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
        constexpr iterator() noexcept;
        explicit iterator (T* new_ptr): ptr(new_ptr) {}
       // ~iterator() {}
        T& operator*() const noexcept { 
            return *ptr;
        }
        T* getter() noexcept { 
            return ptr;
        } 
    iterator operator++() noexcept { 
        iterator tmp (++ptr);
        return tmp; 
    }

     iterator operator--() noexcept { 
        iterator tmp (--ptr);
        return tmp; 
    }

    iterator operator-(const size_type& ind) noexcept { 
        iterator tmp (ptr - ind);
        return tmp;
    }

    iterator operator+(const int& ind) noexcept { 
        iterator tmp(ptr + ind);
        return tmp;

    }

    constexpr bool operator !=(const iterator& other) {
        return ptr != other.ptr;
    }
    
    };
    constexpr iterator begin() noexcept { 
        iterator it(arr);
        return it;
    }

    constexpr iterator end() noexcept { 
        iterator it(arr + sz);
        return it; 
    }





    s21_vector() : arr(nullptr),sz(0),cap(0) {}
    explicit s21_vector(size_type n): arr(AllocTraits::allocate(alloc,n)), sz(n),cap(n) {
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
    s21_vector(const s21_vector &v): alloc(AllocTraits::select_on_container_copy_construction(v.alloc)),arr(AllocTraits::allocate(alloc,v.cap)), sz(v.sz),cap(v.cap) { 
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


    s21_vector(std::initializer_list<value_type> const &items): s21_vector(items.size()) {
        for (size_type i = 0; i < sz; ++i) { 
            arr[i] = *(items.begin() + i);
        }
    }


    s21_vector(s21_vector &&v) noexcept(noexcept(alloc(std::move(v.alloc)))) : 
        alloc(std::move(v.alloc)),arr(v.arr),sz(v.size),cap(v.cap) { 
            v.sz = 0; 
            v.cap = 0; 
            v.arr = nullptr; 
        }
    
    ~s21_vector() { 
        for (size_type i = 0; i < sz; i++) { 
            AllocTraits::destroy(alloc,arr + i);
        }
        AllocTraits::deallocate(alloc, arr, cap);
    }

    auto operator=(s21_vector &&v) noexcept(noexcept(alloc(std::move(v.alloc)))) { 
        arr = v.arr; 
        sz = v.size;
        cap = v.cap; 
        alloc = std::move(v.alloc);
        v.arr = nullptr;
        v.sz = 0;
        v.cap = 0; 
    }

    constexpr reference at(size_type pos) { 
        if (pos > size())
            throw std::out_of_range("Out of range");
        return arr[pos];
    }

    constexpr reference operator[](size_type pos) { 
        return arr[pos];
    }

    constexpr const_reference front() {
        return arr[0b0];
    }

    constexpr const_reference back() { 
        return arr[sz - 1];
    }

    T* data() { 
        return arr;
    }
    constexpr bool empty() noexcept { 
        return !(begin() != end());
    }

    constexpr size_type max_size() { 
        return static_cast<size_type>((std::pow(2,63)))/sizeof(T) - 1;
    }

    void reserve(size_type size) { 
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

    void shrink_to_fit() { 
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

    void clear() noexcept { 
        for (size_type i = 0; i < sz; i++) { 
            AllocTraits::destroy(alloc,arr+i);
        }
        sz = 0; 
    }

    void pop_back()  { 
        --sz; 
        AllocTraits::destroy(alloc,arr + sz);
    }

    void push_back(const_reference value) { 
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

    void push_back(T&& value) { 
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


    template <typename... Args>
    void emplace_back(Args&&... args) { 
         if (cap == 0) { reserve(1);}
        if (sz >= cap) { 
            reserve(cap*2);
        }
        AllocTraits::construct(alloc,arr + sz, std::forward<Args>(args)...);
        sz++;
    }

    size_type size() const noexcept {
        return sz;  
    }
    size_type capacity() const noexcept { 
        return cap;
    }


    void erase(iterator pos) { 
   //    AllocTraits::destroy(alloc,pos);
        for (iterator it = pos; it != end() - 1; ++it) { 
            *it = *(it + 1);
        }
        --sz;
    }

    iterator insert(iterator pos, const_reference value)  { 
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

    void swap(s21_vector& other) { 
        std::swap(arr,other.arr);
        std::swap(sz,other.sz);
        std::swap(cap,other.cap);
        if (AllocTraits::propagate_on_container_swap::value && alloc != other.allloc) { 
            std::swap(alloc,other.alloc);
        }
    }
    template <typename... Args>
    iterator insert_many(iterator pos, Args&&... args) { 
        s21_vector<T> temp {args...};
       for (auto i = static_cast<int>(temp.size() - 1);  i >= 0; i--) { 
            insert(pos,temp.arr[i]);
       }
        iterator tmp = begin();
    return tmp;
    }

    template <typename... Args>
    void insert_many_back(Args&&... args) { 
        insert_many(end(),(args)...);
    }

};

template <typename T, typename Alloc = std::allocator<T>>
constexpr s21_vector<T,Alloc>::iterator::iterator() noexcept: ptr(nullptr) {};


