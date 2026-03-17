#pragma once
#include <chrono>
#include <iostream>

namespace moderncppmastery {

// RAII Timer (automatically prints duration when destroyed)
class ScopedTimer {
public:
    explicit ScopedTimer(const char* name)
        : name_(name), start_(std::chrono::high_resolution_clock::now()) {}

    ~ScopedTimer() {
        auto end      = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration<double, std::milli>(end - start_).count();
        std::cout << name_ << " took " << duration << " ms\n";
    }

private:
    const char* name_;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_;
};

}  // namespace moderncppmastery
