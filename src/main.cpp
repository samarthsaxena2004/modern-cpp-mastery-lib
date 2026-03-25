#include "moderncppmastery/fixed_vector.hpp"
#include "moderncppmastery/custom_allocator.hpp"
#include "moderncppmastery/raii_helpers.hpp"
#include <iostream>
#include <vector>
int main() {
    moderncppmastery::ScopedTimer timer("Entire demo");
    moderncppmastery::FixedVector<int, 10> fv;
    fv.push_back(42);
    auto fv2 = std::move(fv);
    std::cout << "fv2 size: " << fv2.size() << "\n";
    for(const auto& v : fv2) std::cout << v << " ";
    std::cout << "\nDemo completed.\n";
    return 0;
}
