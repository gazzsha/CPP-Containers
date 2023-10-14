#include <iostream>

void modifyPointer(int* ptr, int*& a) {
    ptr = a; // Модификация указателя, но это не повлияет на оригинальный указатель в вызывающем коде
}
void modifyPointerByReference(int*& ptr, int*& a) {
    ptr = a; // Модификация указателя, повлияет на оригинальный указатель в вызывающем коде
}


int main() {
    int a = 2;
    int b = 13;
    int* ptr = &a;
    int *bb = &b;
    std::cout << '\n';
    std::cout << ptr;
    std::cout << '\n';
    modifyPointer(ptr, bb);
    std::cout << ptr;
    std::cout << '\n';
    modifyPointerByReference(ptr, bb);
    std::cout << ptr;
    std::cout << '\n';
}