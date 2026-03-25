#pragma once
#include <array>
#include <stdexcept>
#include <utility>
namespace moderncppmastery {
template <typename T, size_t N>
class FixedVector {
    std::array<T, N> data_{};
    size_t size_ = 0;
public:
    using value_type = T;
    using size_type = size_t;
    FixedVector() = default;
    FixedVector(const FixedVector& o) : data_(o.data_), size_(o.size_) {}
    FixedVector(FixedVector&& o) noexcept : data_(std::move(o.data_)), size_(o.size_) { o.size_ = 0; }
    FixedVector& operator=(FixedVector&& o) noexcept { if(this!=&o){ data_=std::move(o.data_); size_=o.size_; o.size_=0; } return *this; }
    FixedVector& operator=(const FixedVector& o) { if(this!=&o){ data_=o.data_; size_=o.size_; } return *this; }
    void push_back(const T& v) { if(size_>=N) throw std::overflow_error("full"); data_[size_++] = v; }
    void push_back(T&& v) { if(size_>=N) throw std::overflow_error("full"); data_[size_++] = std::move(v); }
    T& operator[](size_type i) { return data_[i]; }
    const T& operator[](size_type i) const { return data_[i]; }
    size_type size() const { return size_; }
    auto begin() { return data_.begin(); }
    auto end() { return data_.begin() + size_; }
};
}
