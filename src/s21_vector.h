#include <iostream> 
#include <vector>
#include <memory>
#include <utility>
#include <string>
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
        constexpr iterator() noexcept: ptr(nullptr) {}
        explicit iterator (T* new_ptr): ptr(new_ptr) {}
       // ~iterator() {}
        T& operator*() const noexcept { 
            return *ptr;
        }
    iterator operator++() noexcept { 
        iterator tmp (++ptr);
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
        AllocTraits::construct(alloc, arr+i,0);
    }
    s21_vector(const s21_vector &v): alloc(AllocTraits::select_on_container_copy_construction(v.alloc)),arr(AllocTraits::allocate(alloc,v.cap)), sz(v.sz),cap(v.cap) { 
        for (size_type i = 0; i < sz; ++i) { 
            try { 
                AllocTraits::construct(alloc, arr + i, std::move_if_noexcept(v.arr[i]));
            } 
            catch (...) { 
                for (size_type j = 0; j < i; ++i) { 
                    AllocTraits::destroy(alloc,arr + i);
                }
                AllocTraits::deallocate(alloc,arr,cap);
                throw;
            }
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








    size_type size() const noexcept {
        return sz;  
    }
    size_type capacity() const noexcept { 
        return cap;
    }
};
