#include <iostream>

template<typename T>
class A { 
    public:
    virtual void f() {
        std::cout << "aaa";
    };
   protected:
    T a = 5;
};

template <typename T>
class B: public A<T> { 
    public:
    void f() override{ 
        A<T>::a = 6;
        std::cout << A<T>::a;
    }
};


int main() { 
    B<int> b;
    b.f();
    return 0;
}