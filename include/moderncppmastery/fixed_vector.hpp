#pragma once
#include <array>
#include <stdexcept>
#include <utility>  // std::move, std::swap

namespace moderncppmastery {

// Fixed-size vector with dynamic size (max capacity N)
// Demonstrates: templates, move semantics, RAII, iterators
template <typename T, size_t N>
class FixedVector {
public:
    using value_type = T;
    using size_type  = size_t;

    FixedVector() = default;

    // Copy constructor
    FixedVector(const FixedVector& other) : data_(other.data_), size_(other.size_) {}

    // Move constructor (key modern C++ feature)
    FixedVector(FixedVector&& other) noexcept
        : data_(std::move(other.data_)), size_(other.size_) {
        other.size_ = 0;  // leave other in valid state
    }

    // Move assignment
    FixedVector& operator=(FixedVector&& other) noexcept {
        if (this != &other) {
            data_  = std::move(other.data_);
            size_  = other.size_;
            other.size_ = 0;
        }
        return *this;
    }

    void push_back(const T& value) {
        if (size_ >= N) throw std::overflow_error("FixedVector capacity exceeded");
        data_[size_++] = value;
    }

    void push_back(T&& value) {  // rvalue overload
        if (size_ >= N) throw std::overflow_error("FixedVector capacity exceeded");
        data_[size_++] = std::move(value);
    }

    T&       operator[](size_type index)       { return data_[index]; }
    const T& operator[](size_type index) const { return data_[index]; }

    size_type size()     const { return size_; }
    size_type capacity() const { return N; }
    bool      empty()    const { return size_ == 0; }

    // Range-based for loop support
    auto begin()       { return data_.begin(); }
    auto end()         { return data_.begin() + size_; }
    auto begin() const { return data_.begin(); }
    auto end()   const { return data_.begin() + size_; }

private:
    std::array<T, N> data_{};  // RAII: std::array is automatically managed on scope exit
    size_type size_ = 0;
};

}  // namespace moderncppmastery
