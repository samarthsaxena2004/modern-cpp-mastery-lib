#include "moderncppmastery/fixed_vector.hpp"
#include "moderncppmastery/raii_helpers.hpp"
#include <iostream>

int main() {
    moderncppmastery::ScopedTimer timer("Entire demo");

    moderncppmastery::FixedVector<int, 10> fv;
    fv.push_back(42);
    fv.push_back(100);

    std::cout << "FixedVector size: " << fv.size() << "\n";

    // Move semantics demo
    auto fv2 = std::move(fv);
    std::cout << "After move, fv2 size: " << fv2.size() << "\n";

    return 0;
}
