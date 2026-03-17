#include "moderncppmastery/fixed_vector.hpp"
#include "moderncppmastery/custom_allocator.hpp"
#include "moderncppmastery/raii_helpers.hpp"
#include <iostream>
#include <vector>

int main() {
    moderncppmastery::ScopedTimer timer("Entire demo");  // RAII in action

    moderncppmastery::FixedVector<int, 10> fv;
    fv.push_back(42);
    fv.push_back(100);

    std::cout << "FixedVector size: " << fv.size() << "\n";

    // Move semantics demo
    auto fv2 = std::move(fv);
    std::cout << "After move, fv2 size: " << fv2.size() << "\n";

    // Custom allocator demo (with std::vector)
    std::vector<int, moderncppmastery::CustomAllocator<int>> vec;
    vec.push_back(999);

    std::cout << "Demo completed successfully!\n";
    return 0;
}
