#pragma once
#include <cstddef>

namespace moderncppmastery {

// Simple custom allocator (demonstrates memory management)
// Real libraries use this with std::vector, pmr, etc.
template <typename T>
struct CustomAllocator {
    using value_type = T;

    T* allocate(std::size_t n) {
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* p, std::size_t) noexcept {
        ::operator delete(p);
    }
};

}  // namespace moderncppmastery
