#pragma once
#include <chrono>
#include <iostream>

namespace moderncppmastery {

// RAII Timer - resource acquired in ctor, released in dtor
class ScopedTimer {
public:
    explicit ScopedTimer(const char* name)
        : name_(name), start_(std::chrono::high_resolution_clock::now()) {}

    ~ScopedTimer() {
        // TODO: calculate duration and print
    }

private:
    const char* name_;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_;
};

}  // namespace moderncppmastery
