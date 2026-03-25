#pragma once
#include <cstddef>
namespace moderncppmastery {
template <typename T>
struct CustomAllocator {
    using value_type = T;
    T* allocate(std::size_t n) { if(n==0) return nullptr; return static_cast<T*>(::operator new(n * sizeof(T))); }
    void deallocate(T* p, std::size_t) noexcept { if(p) ::operator delete(p); }
    template <typename U> struct rebind { using other = CustomAllocator<U>; };
};
}
