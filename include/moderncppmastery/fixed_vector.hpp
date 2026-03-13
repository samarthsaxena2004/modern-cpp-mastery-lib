#pragma once
#include <array>
#include <stdexcept>

namespace moderncppmastery {

// Fixed-size vector with dynamic size tracking
// Demonstrates: templates, RAII, rule of 5
template <typename T, size_t N>
class FixedVector {
public:
    using value_type = T;
    using size_type  = size_t;

    FixedVector() = default;

    // Copy constructor
    FixedVector(const FixedVector& other)
        : data_(other.data_), size_(other.size_) {}

    void push_back(const T& value) {
        if (size_ >= N)
            throw std::overflow_error("FixedVector capacity exceeded");
        data_[size_++] = value;
    }

    T&       operator[](size_type index)       { return data_[index]; }
    const T& operator[](size_type index) const { return data_[index]; }

    size_type size()     const { return size_; }
    size_type capacity() const { return N; }
    bool      empty()    const { return size_ == 0; }

private:
    std::array<T, N> data_{};
    size_type size_ = 0;
};

} // namespace moderncppmastery
